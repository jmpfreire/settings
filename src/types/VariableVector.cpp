/**
 *  VariableVector.cpp
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

#include "VariableVector.h"

namespace appSet {

/**
 *
 */
VariableVector::VariableVector() :VariableBase()
{
	value.clear();
}

/**
 *
 */
VariableVector::~VariableVector()
{
	// TODO Auto-generated destructor stub
}

/**
 *
 * @return
 */
VariableVector * VariableVector::clone()
{
	return new VariableVector(*this);
}

/**
 *
 * @param map_key
 * @return
 */
std::string VariableVector::get_msg_string_values(const std::string &map_key)
{
	std::string msg;

	int num_elems = this->value.size();

	msg = "\nValores para la tabla " + map_key + "\n{\n";

	for(int i = 0; i < num_elems; i++)
	{
		msg += "\t" + value[i]->get_msg_string_values(map_key) + "\n";
	}

	msg += "}\n";

	return msg;
}

/**
 *
 * @param v
 */
void VariableVector::set_value(const int &v)
{
	VariableBase *new_value = new VariableInt;

	new_value->set_value(v);

	value.push_back(new_value->clone());
}

/**
 *
 * @param v
 */
void VariableVector::set_value(const double &v)
{
	VariableBase *new_value = new VariableDouble;

	new_value->set_value(v);

	value.push_back(new_value->clone());
}

/**
 *
 * @param v
 */
void VariableVector::set_value(const std::string &v)
{
	VariableBase *new_value = new VariableString;

	new_value->set_value(v);

	value.push_back(new_value->clone());
}

/**
 *
 * @param index
 * @return
 */
VariableBase * VariableVector::get_value_vector(const int &index)
{
	return value[index];
}

/**
 *
 * @return
 */
int VariableVector::get_num_elems_vec()
{
	return (int)value.size();
}

/**
 *
 * @param index
 * @return
 */
VariableBase * VariableVector::operator[](const int &index)
{
	if((index >= 0) && index < (int)value.size())
	{
		return value[index];
	}
	else
	{
		sysUtil::Log::print_log("Index out of limits", 4, 3);
		return 0;
	}
}

} /* namespace appSet */
