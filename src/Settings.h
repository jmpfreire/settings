#ifndef SETTINGS_H_
#define SETTINGS_H_

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

#include <string>
#include <map>

#include "XmlParser.h"
#include "SchemaSettings.h"

#include "Log.h"
#include "Utils.h"

/**
 *  \addtogroup appSet
 *  @{
 */
namespace appSet
{
	/**
	 * @class Settings
	 *
	 * @brief
	 */
	class Settings
	{
		public:
			/**
			 *
			 */
			Settings() = default;
			/**
			 *
			 * @param pp
			 */
			Settings(const std::string &pp);
			/**
			 *
			 */
			void print_settings_values() const;
			/**
			 *
			 * @param key
			 * @return
			 */
			VariableBase & operator[](const std::string &key);
		private:
			//Methods
			/**
			 *
			 * @return
			 */
			SchemaSettings * get_schema();
			/**
			 *
			 * @param path
			 * @return
			 */
			bool load_settings_file(const std::string &path);
			//Attributes
			std::string pref_file_path; /**< */
			SchemaSettings schema; /**< */
	};
} /*! @}*/
#endif /* SETTINGS_H_ */
