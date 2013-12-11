/**
 *  SchemaSettings.cpp
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

#include "SchemaSettings.h"

namespace appSet {

/**
 *
 */
SchemaSettings::SchemaSettings(): id_schema("")
{
	settings_table.clear();
}

/**
 *
 */
SchemaSettings::~SchemaSettings()
{

}

/**
 *
 * @param ss
 */
SchemaSettings::SchemaSettings(const SchemaSettings &ss)
{
	settings_table = ss.settings_table;
	id_schema = ss.id_schema;
}

/**
 *
 */
void SchemaSettings::print_settings_values()
{
	std::map<std::string, VariableBase *>::iterator iter;

	std::cout<<std::endl;
	sysUtil::Log::print_log("***************INICIO FICHERO CONFIGURACION***************", 4, 7);
	std::cout<<std::endl;

	sysUtil::Log::print_log("Preferencias id: " + this->id_schema, 4, 7);

	for(iter = settings_table.begin(); iter != settings_table.end(); ++iter)
	{
		std::string part_msg;

		part_msg = iter->second->get_msg_string_values(iter->first);

		sysUtil::Log::print_log(part_msg, 4, 7);
	}

	std::cout<<std::endl;
	sysUtil::Log::print_log("***************FIN FICHERO CONFIGURACION***************", 4, 7);
	std::cout<<std::endl;
}

/**
 *
 * @param is
 */
void SchemaSettings::set_id_schema(const std::string &is)
{
	id_schema = is;
}

/**
 *
 * @param key
 * @param value
 */
void SchemaSettings::set_value(const std::string &key, const std::string &value)
{
	def_check_insert check;

	check = settings_table.insert(std::pair<std::string, VariableBase *>(key, analize_type_data(value)->clone()));

	if(!check.second)
	{
		sysUtil::Log::print_log("Unable to add the element " + value, 4, 3);
	}
}

/**
 *
 * @param key
 * @param value
 */
void SchemaSettings::set_value(const std::string &key, const std::vector<std::string> &value)
{
	int num_elem;
	VariableVector * new_vec = new VariableVector;
	def_check_insert check;

	num_elem = value.size();

	for(int i = 0; i < num_elem; i++)
	{
		this->set_data_vector(*new_vec, value[i]);
	}

	check = settings_table.insert(std::pair<std::string, VariableBase *>(key, new_vec->clone()));

	if(!check.second)
	{
		sysUtil::Log::print_log("Unable to add the vector ", 4, 3);
	}
}

/**
 *
 * @param key
 * @param value
 */
void SchemaSettings::set_value(const std::string &key, std::map<std::string, std::string> value)
{
	VariableMap * new_map = new VariableMap;
	def_check_insert check;

	std::map<std::string, std::string>::iterator iter;

	for(iter = value.begin(); iter != value.end(); ++iter)
	{
		this->set_data_map(*new_map, iter->first, iter->second);
	}

	check = settings_table.insert(std::pair<std::string, VariableBase *>(key, new_map->clone()));

	if(!check.second)
	{
		sysUtil::Log::print_log("Unable to add the map ", 4, 3);
	}
}

/**
 *
 * @param ss
 * @return
 */
SchemaSettings & SchemaSettings::operator=(const SchemaSettings &ss)
{
	this->settings_table = ss.settings_table;
	this->id_schema = ss.id_schema;

	return *this;
}

/**
 *
 * @param key
 * @return
 */
VariableBase & SchemaSettings::operator[](const std::string &key)
{
	return *settings_table[key];
}

/**
 *
 * @param value
 * @return
 */
VariableBase * SchemaSettings::analize_type_data(const std::string &value)
{
	VariableBase * new_var;

	try
	{
		double val = boost::lexical_cast<double>(value);

		size_t found_double = value.find_first_of(".");

		if(found_double != std::string::npos)
		{
			new_var = new VariableDouble;

			new_var->set_value(val);
		}
		else
		{
			int val_int = boost::lexical_cast<int>(value);

			new_var = new VariableInt;

			new_var->set_value(val_int);
		}
	}
	catch(...)
	{
		new_var = new VariableString;

		std::string aux_str = value;

		aux_str.erase(std::remove(aux_str.begin(), aux_str.end(), '\"'), aux_str.end());

		new_var->set_value(aux_str);
	}

	return new_var;
}

/**
 *
 * @param vec_aux
 * @param value
 */
void SchemaSettings::set_data_vector(VariableVector &vec_aux, const std::string &value)
{
	try
	{
		double val = boost::lexical_cast<double>(value);

		size_t found_double = value.find_first_of(".");

		if(found_double != std::string::npos)
		{
			vec_aux.set_value(val);
		}
		else
		{
			int val_int = boost::lexical_cast<int>(value);

			vec_aux.set_value(val_int);
		}
	}
	catch(...)
	{
		std::string aux_str = value;

		aux_str.erase(std::remove(aux_str.begin(), aux_str.end(), '\"'), aux_str.end());

		vec_aux.set_value(aux_str);
	}
}

/**
 *
 * @param map_aux
 * @param value
 */
void SchemaSettings::set_data_map(VariableMap &map_aux, const std::string &key, const std::string &value)
{
	try
	{
		double val = boost::lexical_cast<double>(value);

		size_t found_double = value.find_first_of(".");

		if(found_double != std::string::npos)
		{
			map_aux.set_value(key, val);
		}
		else
		{
			int val_int = boost::lexical_cast<int>(value);

			map_aux.set_value(key, val_int);
		}
	}
	catch(...)
	{
		std::string aux_str = value;

		aux_str.erase(std::remove(aux_str.begin(), aux_str.end(), '\"'), aux_str.end());

		map_aux.set_value(key, aux_str);
	}
}
} /* namespace appSet */
