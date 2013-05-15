/**
 *  VariableInt.cpp
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

#include "VariableInt.h"

namespace appSet {

/**
 *
 */
VariableInt::VariableInt():VariableBase(), value(-1)
{

}

/**
 *
 */
VariableInt::~VariableInt()
{

}

/**
 *
 * @return
 */
VariableInt * VariableInt::clone()
{
	return new VariableInt(*this);
}

/**
 *
 * @param map_key
 * @return
 */
std::string VariableInt::get_msg_string_values(const std::string &map_key)
{
	std::string msg;

	msg = map_key + " (int) el valor es: " + drivIn::Utiles::converString(value);

	return msg;
}

/**
 *
 * @param v
 */
void VariableInt::set_value(const int &v)
{
	value = v;
}

/**
 *
 * @return
 */
int VariableInt::get_value_int()
{
	return value;
}

} /* namespace appSet */
