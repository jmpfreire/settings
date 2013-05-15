/**
 *  VariableMap.cpp
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

#include "VariableMap.h"

namespace appSet {

/**
 *
 */
VariableMap::VariableMap():VariableBase()
{
	value.clear();
}

/**
 *
 */
VariableMap::~VariableMap()
{

}

/**
 *
 * @return
 */
VariableMap * VariableMap::VariableMap::clone()
{
	return new VariableMap(*this);
}

/**
 *
 * @param map_key
 * @return
 */
std::string VariableMap::get_msg_string_values(const std::string &map_key)
{
	std::string msg;
	std::map<std::string, VariableBase *>::iterator iter;

	msg = "\nValores para la tabla " + map_key + "\n{\n";

	for(iter = value.begin(); iter != value.end(); ++iter)
	{
		msg += "\t" + iter->second->get_msg_string_values(iter->first) + "\n";
	}

	msg += "}\n";

	return msg;
}

/**
 *
 * @param key
 * @param v
 */
void VariableMap::set_value(const std::string &key, const int &v)
{
	VariableBase * new_value = new VariableInt;
	def_check_insert check;

	new_value->set_value(v);

	check = value.insert(std::pair<std::string, VariableBase *>(key, new_value->clone()));

	if(!check.second)
	{
		drivIn::Log::print_log("Unable to add the map ", 4, 3);
	}
}

/**
 *
 * @param key
 * @param v
 */
void VariableMap::set_value(const std::string &key, const double &v)
{
	VariableBase * new_value = new VariableDouble;
	def_check_insert check;

	new_value->set_value(v);

	check = value.insert(std::pair<std::string, VariableBase *>(key, new_value->clone()));

	if(!check.second)
	{
		drivIn::Log::print_log("Unable to add the map ", 4, 3);
	}
}

/**
 *
 * @param key
 * @param v
 */
void VariableMap::set_value(const std::string &key, const std::string &v)
{
	VariableBase * new_value = new VariableString;

	def_check_insert check;

	new_value->set_value(v);

	check = value.insert(std::pair<std::string, VariableBase *>(key, new_value->clone()));

	if(!check.second)
	{
		drivIn::Log::print_log("Unable to add the map ", 4, 3);
	}
}

/**
 *
 * @param mv
 */
void VariableMap::get_value(std::map<std::string, int> &mv)
{
	std::map<std::string, VariableBase *>::iterator iter;

	for(iter = value.begin(); iter != value.end(); ++iter)
	{
		mv.insert(std::pair<std::string, int>(iter->first, iter->second->get_value_int()));
	}
}

/**
 *
 * @param mv
 */
void VariableMap::get_value(std::map<std::string, double> &mv)
{
	std::map<std::string, VariableBase *>::iterator iter;

	for(iter = value.begin(); iter != value.end(); ++iter)
	{
		mv.insert(std::pair<std::string, double>(iter->first, iter->second->get_value_double()));
	}
}

/**
 *
 * @param mv
 */
void VariableMap::get_value(std::map<std::string, std::string> &mv)
{
	std::map<std::string, VariableBase *>::iterator iter;

	for(iter = value.begin(); iter != value.end(); ++iter)
	{
		mv.insert(std::pair<std::string, std::string>(iter->first, iter->second->get_value_string()));
	}
}

/**
 *
 * @param key
 * @return
 */
VariableBase * VariableMap::get_value_map(const std::string &key)
{
	return value[key];
}

/**
 *
 * @return
 */
int VariableMap::get_num_elems_map()
{
	return (int)value.size();
}

/**
 *
 * @param key
 * @return
 */
VariableBase * VariableMap::operator[](const std::string &key)
{
	if(value.find(key) != value.end())
	{
		return value[key];
	}
	else
	{
		drivIn::Log::print_log("Key not found", 4, 3);

		return 0;
	}
}

} /* namespace appSet */
