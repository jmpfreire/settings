/**
 * VariableDouble.cpp
 *
 *  Created on: 07/05/2013
 *      Author: José Manuel Pintor Freire
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

	msg = map_key + " (double) el valor es: " + drivIn::Utiles::converString(value);

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
