#include "VariableVector.h"

namespace appSet {

VariableVector::VariableVector() :VariableBase()
{
	value.clear();
}

VariableVector::~VariableVector()
{
	for(auto &th : value)
	{
		delete th;
		th = nullptr;
	}

	value.clear();
	value.shrink_to_fit();
}

VariableVector * VariableVector::clone() const
{
	return new VariableVector(*this);
}

std::string VariableVector::get_msg_string_values(const std::string &map_key) const
{
	std::string msg;

	msg = "\nValores para la tabla " + map_key + "\n{\n";

	for(auto elem_v : value)
	{
		msg += "\t" + elem_v->get_msg_string_values(map_key) + "\n";
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

int VariableVector::get_num_elems_vec() const
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
