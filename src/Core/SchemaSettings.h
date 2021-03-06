#ifndef SCHEMASETTINGS_H_
#define SCHEMASETTINGS_H_

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

#include <map>
#include <string>
#include <iostream>

#include "../Core/VariableBase.h"
#include "../Types/VariableString.h"
#include "../Types/VariableInt.h"
#include "../Types/VariableDouble.h"
#include "../Types/VariableVector.h"
#include "../Types/VariableMap.h"

#include "../Utilities/Log.h"

#include <typeinfo>

/**
 *  \addtogroup appSet
 *  @{
 */
namespace appSet
{
	/**
	 * @class SchemaSettings
	 *
	 * @brief
	 */
	class SchemaSettings
	{
		/**
		 *
		 */
		typedef std::map<std::string, VariableBase *> def_settings;

		/**
		 *
		 */
		typedef std::pair<std::map<std::string,
					VariableBase *>::iterator, bool> def_check_insert;
		public:
			/**
			 *
			 */
			SchemaSettings();
			/**
			 *
			 */
			virtual ~SchemaSettings();
			/**
			 *
			 * @param ss
			 */
			SchemaSettings(const SchemaSettings &ss);
			/**
			 *
			 */
			void print_settings_values() const;
			/**
			 *
			 * @param is
			 */
			void set_id_schema(const std::string &is);
			/**
			 *
			 * @param key
			 * @param value
			 */
			void set_value(const std::string &key, const std::string &value);
			/**
			 *
			 * @param key
			 * @param value
			 */
			void set_value(const std::string &key, const std::vector<std::string> &value);
			/**
			 *
			 * @param key
			 * @param value
			 */
			void set_value(const std::string &key, std::map<std::string, std::string> value);
			/**
			 *
			 * @param key
			 * @return
			 */
			VariableBase & operator[](const std::string &key);
			/**
			 *
			 * @param ss
			 * @return
			 */
			SchemaSettings & operator=(const SchemaSettings &ss);
		private:
			//Methods
			/**
			 *
			 * @param value
			 * @return
			 */
			std::shared_ptr<VariableBase> analize_type_data(const std::string &value);
			/**
			 *
			 * @param vec_aux
			 * @param value
			 */
			void set_data_vector(VariableVector &vec_aux, const std::string &value);
			/**
			 *
			 * @param map_aux
			 * @param key
			 * @param value
			 */
			void set_data_map(VariableMap &map_aux, const std::string &key, const std::string &value);
			//Attributes
			def_settings settings_table; /**< */
			std::string id_schema; /**< */
	};
} /*! @}*/
#endif /* SCHEMASETTINGS_H_ */
