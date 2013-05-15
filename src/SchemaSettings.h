/**
 * schemaSettings.h
 *
 *  Created on: 07/05/2013
 *      Author: José Manuel Pintor Freire
 */

#ifndef SCHEMASETTINGS_H_
#define SCHEMASETTINGS_H_

#include <map>
#include <string>
#include <iostream>

#include "VariableBase.h"
#include "types/VariableString.h"
#include "types/VariableInt.h"
#include "types/VariableDouble.h"
#include "types/VariableVector.h"
#include "types/VariableMap.h"

#include "lexical_cast.hpp"

#include "Log.h"

#include <typeinfo>

namespace appSet
{
	class SchemaSettings
	{
		typedef std::map<std::string, VariableBase *> def_settings;

		typedef std::pair<std::map<std::string,
					VariableBase *>::iterator, bool> def_check_insert;
		public:
			SchemaSettings();
			virtual ~SchemaSettings();
			SchemaSettings(const SchemaSettings &ss);
			void print_settings_values();
			void set_id_schema(const std::string &is);
			void set_value(const std::string &key, const std::string &value);
			void set_value(const std::string &key, const std::vector<std::string> &value);
			void set_value(const std::string &key, std::map<std::string, std::string> value);
			SchemaSettings & operator=(const SchemaSettings &ss);
			VariableBase & operator[](const std::string &key);
		private:
			//Methods
			VariableBase * analize_type_data(const std::string &value);
			void set_data_vector(VariableVector &vec_aux, const std::string &value);
			void set_data_map(VariableMap &map_aux, const std::string &key, const std::string &value);
			//Attributes
			def_settings settings_table;
			std::string id_schema;
	};
} /* namespace appSet */
#endif /* SCHEMASETTINGS_H_ */
