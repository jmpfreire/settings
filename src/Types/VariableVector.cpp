#include "VariableVector.h"

namespace appSet {

VariableVector::VariableVector() :VariableBase()
{
	value.clear();
}

VariableVector::~VariableVector()
{
	// TODO Auto-generated destructor stub
}

VariableVector * VariableVector::clone() const
{
	return new VariableVector(*this);
}

std::string VariableVector::get_msg_string_values(const std::string &map_key)
{
	std::string msg;

	int num_elems = this->value.size();

	msg = "\nValores para la tabla " + map_key + "\n{\n";

	for(int i = 0; i < num_elems; i++)
	{
		msg += "\t" + value[i]->get_msg_string_values(map_key) + "\n";
	}

	msg += "}\n";

	return msg;
}

void VariableVector::set_value(const int &v)
{
	VariableBase *new_value = new VariableInt;

	new_value->set_value(v);

	value.push_back(new_value->clone());
}

void VariableVector::set_value(const double &v)
{
	VariableBase *new_value = new VariableDouble;

	new_value->set_value(v);

	value.push_back(new_value->clone());
}

void VariableVector::set_value(const std::string &v)
{
	VariableBase *new_value = new VariableString;

	new_value->set_value(v);

	value.push_back(new_value->clone());
}

VariableBase * VariableVector::get_value_vector(const int &index)
{
	return value[index];
}

int VariableVector::get_num_elems_vec()
{
	return (int)value.size();
}

VariableBase * VariableVector::operator[](const int &index)
{
	if((index >= 0) && index < (int)value.size())
	{
		return value[index];
	}
	else
	{
		sysUtil::Log::print_log("Index out of limits", 4, 3);
		return 0;
	}
}

} /* namespace appSet */
