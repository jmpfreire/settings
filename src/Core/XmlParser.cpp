#include "XmlParser.h"

namespace appSet {

XmlParser::XmlParser(SchemaSettings &ss) : xmlpp::SaxParser(), app_settings(&ss), id_aux("")
{
	while(!tag_stack.empty())
	{
		tag_stack.pop();
	}

	map_aux.clear();
	v_aux.clear();
}

XmlParser::~XmlParser()
{
	app_settings = nullptr;

	//String
	node_name.clear();
	node_name.shrink_to_fit();
	id_aux.clear();
	id_aux.shrink_to_fit();

	//Vector
	v_aux.clear();
	v_aux.shrink_to_fit();

	while(!tag_stack.empty())
	{
		tag_stack.pop();
	}

	map_aux.clear();
}

void XmlParser::on_start_element(const Glib::ustring& name_xml,const AttributeList& properties)
{
	node_name = name_xml;

	if(node_name == "schema")
	{
		for(auto elem1 : properties)
		{
			try
			{
				if(elem1.name == "id")
				{
					this->app_settings->set_id_schema(elem1.value);
				}
			}
			catch(...)
			{
				sysUtil::Log::print_log("XmlParse attributes, Exception while obtaining name or value", 7, 4);
			}
		}
	}
	else if(node_name != "schemalist")
	{
		tag_stack.push(node_name);

		for(auto elem1 : properties)
		{
			try
			{
				id_aux = (std::string)elem1.value;
			}
			catch(...)
			{
				sysUtil::Log::print_log("XmlParse attributes, Exception while obtaining name or value", 7, 4);
			}
		}
	}
}

void XmlParser::on_end_element(const Glib::ustring& name)
{
	if(tag_stack.size() >= 1)
	{
		tag_stack.pop();
	}

	if(tag_stack.empty() && (name != "schemalist") && (name != "schema"))
	{
		if(map_aux.size())
		{
			this->app_settings->set_value(name, map_aux);
			map_aux.clear();
		}
		else if(v_aux.size())
		{
			if(v_aux.size() == 1)
			{
				this->app_settings->set_value(name, v_aux[0]);
			}
			else
			{
				this->app_settings->set_value(name, v_aux);
			}

			v_aux.clear();
		}

		id_aux = "";
	}
}

void XmlParser::on_characters(const Glib::ustring& text)
{
	std::string aux_str(text);

	if(!tag_stack.empty() && (tag_stack.top() == node_name) && std::isprint(aux_str[0]))
	{
		if(id_aux != "")
		{
			map_aux.insert(std::make_pair(id_aux, text));
		}
		else
		{
			v_aux.push_back(text);
		}
	}
}
} /* namespace appSet */
