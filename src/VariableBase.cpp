/**
 *  VariableBase.cpp
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

#include "VariableBase.h"

namespace appSet {

/**
 *
 */
VariableBase::VariableBase()
{

}

/**
 *
 */
VariableBase::~VariableBase()
{

}

///VariableInt

/**
 *
 * @return
 */
int VariableBase::get_value_int()
{
	throw EWrongValue("Wrong class the object do not have integer value");
}

///VariableDouble

/**
 *
 * @return
 */
double VariableBase::get_value_double()
{
	throw EWrongValue("Wrong class the object do not have double value");
}

///VariableString

/**
 *
 * @return
 */
std::string VariableBase::get_value_string()
{
	throw EWrongValue("Wrong class the object do not have string value");
}

///VariableVector

/**
 *
 * @param index
 * @return
 */
VariableBase * VariableBase::get_value_vector(const int &index)
{
	throw EWrongValue("Wrong class the object do not have vector class");
}

/**
 *
 * @return
 */
int VariableBase::get_num_elems_vec()
{
	throw EWrongValue("Wrong class the object do not have vector class");
}

/**
 *
 * @param index
 * @return
 */
VariableBase * VariableBase::operator[](const int &index)
{
	throw EWrongValue("Wrong class the object do not have vector class");
}

///VariableMap

/**
 *
 * @param mv
 */
void VariableBase::get_value(std::map<std::string, int> &mv)
{
	throw EWrongValue("Wrong class the object do not have map class");
}

/**
 *
 * @param mv
 */
void VariableBase::get_value(std::map<std::string, double> &mv)
{
	throw EWrongValue("Wrong class the object do not have map class");
}

/**
 *
 * @param mv
 */
void VariableBase::get_value(std::map<std::string, std::string> &mv)
{
	throw EWrongValue("Wrong class the object do not have map class");
}

/**
 *
 * @param key
 * @return
 */
VariableBase * VariableBase::get_value_map(const std::string &key)
{
	throw EWrongValue("Wrong class the object do not have map class");
}

/**
 *
 * @return
 */
int VariableBase::get_num_elems_map()
{
	throw EWrongValue("Wrong class the object do not have map class");
}

/**
 *
 * @param key
 * @return
 */
VariableBase * VariableBase::operator[](const std::string &key)
{
	throw EWrongValue("Wrong class the object do not have map class");
}

} /* namespace appSet */
