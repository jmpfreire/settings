/**
 * VariableString.cpp
 *
 *  Created on: 07/05/2013
 *      Author: José Manuel Pintor Freire
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
