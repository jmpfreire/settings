/**
 * XmlParser.h
 *
 *  Created on: 07/05/2013
 *      Author: José Manuel Pintor Freire
 */

#ifndef XMLPARSER_H_
#define XMLPARSER_H_

#include <iostream>
#include <libxml++/libxml++.h>
#include <glibmm/convert.h>
#include <cstdlib>
#include <stack>
#include <map>

#include "SchemaSettings.h"
#include "Log.h"

namespace appSet
{
	class XmlParser: public xmlpp::SaxParser
	{
		public:
			XmlParser(SchemaSettings &ss);
			virtual ~XmlParser();
		protected:
			virtual void on_start_element(const Glib::ustring& name_xml,const AttributeList& properties);
			virtual void on_end_element(const Glib::ustring& name);
			virtual void on_characters(const Glib::ustring& text);
		private:
			SchemaSettings * app_settings;
			std::string node_name;
			std::stack<std::string> tag_stack;
			std::map<std::string, std::string> map_aux;
			std::string id_aux;
			std::vector<std::string> v_aux;
	};
} /* namespace appSet */
#endif /* XMLPARSER_H_ */
