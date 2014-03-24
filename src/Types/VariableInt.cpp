#include "VariableInt.h"

namespace appSet {

VariableInt::VariableInt():VariableBase(), value(-1)
{

}

VariableInt::~VariableInt()
{

}

VariableInt * VariableInt::clone() const
{
	return new VariableInt(*this);
}

std::string VariableInt::get_msg_string_values(const std::string &map_key) const
{
	std::string msg;

	msg = map_key + " (int) el valor es: " + std::to_string(value);

	return msg;
}

void VariableInt::set_value(const int &v)
{
	value = v;
}

int VariableInt::get_value_int() const
{
	return value;
}

} /* namespace appSet */
