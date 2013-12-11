/**
 *  XmlParse.cpp
 *  This file is part of libSettings
 *
 *  Copyright (C) 2013  Jose Manuel Pintor Freire
 *
 *  libSettings is free software: you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation, either
 *  version 3 of the License, or (at your option) any later version.
 *
 *  libSettings is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with libSettings.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "XmlParser.h"

namespace appSet {

/**
 *
 * @param ss
 */
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

/**
 *
 */
XmlParser::~XmlParser()
{

}

/**
 *
 * @param nameXml
 * @param properties
 */
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
