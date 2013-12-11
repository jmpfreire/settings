/**
 *  VariableDouble.cpp
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

#include "VariableDouble.h"

namespace appSet {

/**
 *
 */
VariableDouble::VariableDouble() :VariableBase(), value(0.0)
{

}

/**
 *
 */
VariableDouble::~VariableDouble()
{

}

/**
 *
 * @return
 */
VariableDouble * VariableDouble::clone()
{
	return new VariableDouble(*this);
}

/**
 *
 * @param map_key
 * @return
 */
std::string VariableDouble::get_msg_string_values(const std::string &map_key)
{
	std::string msg;

	msg = map_key + " (double) el valor es: " + sysUtil::Utils::converString(value);

	return msg;
}

/**
 *
 * @param v
 */
void VariableDouble::set_value(const double &v)
{
	value = v;
}

/**
 *
 * @return
 */
double VariableDouble::get_value_double()
{
	return value;
}


} /* namespace appSet */
