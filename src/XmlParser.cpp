#include "XmlParser.h"

namespace appSet {

XmlParser::XmlParser(SchemaSettings &ss) : xmlpp::SaxParser()
{
	while(!tag_stack.empty())
	{
		tag_stack.pop();
	}

	map_aux.clear();
	v_aux.clear();
	id_aux = "";

	app_settings = &ss;
}

XmlParser::~XmlParser()
{

}

void XmlParser::on_start_element(const Glib::ustring& name_xml,const AttributeList& properties)
{
	node_name = name_xml;

	if(node_name == "schema")
	{
		for(xmlpp::SaxParser::AttributeList::const_iterator iter = properties.begin(); iter != properties.end(); ++iter)
		{
			try
			{
				if(iter->name == "id")
				{
					this->app_settings->set_id_schema(iter->value);
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

		for(xmlpp::SaxParser::AttributeList::const_iterator iter = properties.begin(); iter != properties.end(); ++iter)
		{
			try
			{
				id_aux = (std::string)iter->value;
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

	if(tag_stack.empty() && name != "schemalist" && name != "schema")
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

	if(!tag_stack.empty() && tag_stack.top() == node_name && std::isprint(aux_str[0]))
	{
		if(id_aux != "")
		{
			map_aux.insert(std::pair<std::string, std::string>(id_aux, text));
		}
		else
		{
			v_aux.push_back(text);
		}
	}
}
} /* namespace appSet */
