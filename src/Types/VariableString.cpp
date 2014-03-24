#include "VariableString.h"

namespace appSet {

VariableString::VariableString(): VariableBase(), value("")
{

}

VariableString::~VariableString()
{

}

VariableString * VariableString::clone() const
{
	return new VariableString(*this);
}

std::string VariableString::get_msg_string_values(const std::string &map_key)
{
	std::string msg;

	msg = map_key + " (string) el valor es: " + value;

	return msg;
}

void VariableString::set_value(const std::string &v)
{
	value = v;
}

std::string VariableString::get_value_string()
{
	return value;
}

} /* namespace appSet */
