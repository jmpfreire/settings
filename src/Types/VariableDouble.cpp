#include "VariableDouble.h"

namespace appSet {

VariableDouble::VariableDouble() :VariableBase(), value(0.0)
{

}

VariableDouble::~VariableDouble()
{

}

VariableDouble * VariableDouble::clone() const
{
	return new VariableDouble(*this);
}

std::string VariableDouble::get_msg_string_values(const std::string &map_key)
{
	std::string msg;

	msg = map_key + " (double) el valor es: " + std::to_string(value);

	return msg;
}

void VariableDouble::set_value(const double &v)
{
	value = v;
}

double VariableDouble::get_value_double()
{
	return value;
}


} /* namespace appSet */
