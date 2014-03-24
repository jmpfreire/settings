#ifndef XMLPARSER_H_
#define XMLPARSER_H_

/**
 *  @file
 *  This file is part of libSettings
 *
 *  Copyright (C) 2014  Jose Manuel Pintor Freire
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

#include <iostream>
#include <libxml++/libxml++.h>
#include <glibmm.h>
#include <cstdlib>
#include <stack>
#include <map>

#include "SchemaSettings.h"
#include "../Utilities/Log.h"

/**
 *  \addtogroup appSet
 *  @{
 */
namespace appSet
{
	/**
	 * @class XmlParser
	 *
	 * @brief
	 */
	class XmlParser: public xmlpp::SaxParser
	{
		public:
			/**
			 *
			 * @param ss
			 */
			XmlParser(SchemaSettings &ss);
			/**
			 *
			 */
			virtual ~XmlParser();
		protected:
			/**
			 *
			 * @param name_xml
			 * @param properties
			 */
			virtual void on_start_element(const Glib::ustring& name_xml,const AttributeList& properties);
			/**
			 *
			 * @param name
			 */
			virtual void on_end_element(const Glib::ustring& name);
			/**
			 *
			 * @param text
			 */
			virtual void on_characters(const Glib::ustring& text);
		private:
			SchemaSettings * app_settings; /**< */
			std::string node_name; /**< */
			std::stack<std::string> tag_stack; /**< */
			std::map<std::string, std::string> map_aux; /**< */
			std::string id_aux; /**< */
			std::vector<std::string> v_aux; /**< */
	};
} /*! @}*/
#endif /* XMLPARSER_H_ */
