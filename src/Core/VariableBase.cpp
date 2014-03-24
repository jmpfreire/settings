#include "VariableBase.h"

namespace appSet {

int VariableBase::get_value_int()
{
	throw EWrongValue("Wrong class the object do not have integer value");
}

double VariableBase::get_value_double()
{
	throw EWrongValue("Wrong class the object do not have double value");
}

std::string VariableBase::get_value_string()
{
	throw EWrongValue("Wrong class the object do not have string value");
}

VariableBase * VariableBase::get_value_vector(const int &index)
{
	throw EWrongValue("Wrong class the object do not have vector class");
}

int VariableBase::get_num_elems_vec()
{
	throw EWrongValue("Wrong class the object do not have vector class");
}

VariableBase * VariableBase::operator[](const int &index)
{
	throw EWrongValue("Wrong class the object do not have vector class");
}

void VariableBase::get_value(std::map<std::string, int> &mv)
{
	throw EWrongValue("Wrong class the object do not have map class");
}

void VariableBase::get_value(std::map<std::string, double> &mv)
{
	throw EWrongValue("Wrong class the object do not have map class");
}

void VariableBase::get_value(std::map<std::string, std::string> &mv)
{
	throw EWrongValue("Wrong class the object do not have map class");
}

VariableBase * VariableBase::get_value_map(const std::string &key)
{
	throw EWrongValue("Wrong class the object do not have map class");
}

int VariableBase::get_num_elems_map()
{
	throw EWrongValue("Wrong class the object do not have map class");
}

VariableBase * VariableBase::operator[](const std::string &key)
{
	throw EWrongValue("Wrong class the object do not have map class");
}

} /* namespace appSet */
