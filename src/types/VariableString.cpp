/**
 *  VariableString.cpp
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

#include "VariableString.h"

namespace appSet {

/**
 *
 */
VariableString::VariableString(): VariableBase(), value("")
{

}

/**
 *
 */
VariableString::~VariableString()
{

}

/**
 *
 * @return
 */
VariableString * VariableString::clone()
{
	return new VariableString(*this);
}

/**
 *
 * @param map_key
 * @return
 */
std::string VariableString::get_msg_string_values(const std::string &map_key)
{
	std::string msg;

	msg = map_key + " (string) el valor es: " + value;

	return msg;
}

/**
 *
 * @param v
 */
void VariableString::set_value(const std::string &v)
{
	value = v;
}

/**
 *
 * @return
 */
std::string VariableString::get_value_string()
{
	return value;
}

} /* namespace appSet */
