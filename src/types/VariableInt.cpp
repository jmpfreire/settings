/**
 * VariableInt.cpp
 *
 *  Created on: 07/05/2013
 *      Author: José Manuel Pintor Freire
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
