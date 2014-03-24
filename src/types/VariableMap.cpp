#include "VariableMap.h"

namespace appSet {

VariableMap::VariableMap():VariableBase()
{
	value.clear();
}

VariableMap::~VariableMap()
{

}

VariableMap * VariableMap::VariableMap::clone()
{
	return new VariableMap(*this);
}

std::string VariableMap::get_msg_string_values(const std::string &map_key)
{
	std::string msg;
	std::map<std::string, VariableBase *>::iterator iter;

	msg = "\nValores para la tabla " + map_key + "\n{\n";

	for(iter = value.begin(); iter != value.end(); ++iter)
	{
		msg += "\t" + iter->second->get_msg_string_values(iter->first) + "\n";
	}

	msg += "}\n";

	return msg;
}

void VariableMap::set_value(const std::string &key, const int &v)
{
	VariableBase * new_value = new VariableInt;
	def_check_insert check;

	new_value->set_value(v);

	check = value.insert(std::pair<std::string, VariableBase *>(key, new_value->clone()));

	if(!check.second)
	{
		sysUtil::Log::print_log("Unable to add the map ", 4, 3);
	}
}

void VariableMap::set_value(const std::string &key, const double &v)
{
	VariableBase * new_value = new VariableDouble;
	def_check_insert check;

	new_value->set_value(v);

	check = value.insert(std::pair<std::string, VariableBase *>(key, new_value->clone()));

	if(!check.second)
	{
		sysUtil::Log::print_log("Unable to add the map ", 4, 3);
	}
}

void VariableMap::set_value(const std::string &key, const std::string &v)
{
	VariableBase * new_value = new VariableString;

	def_check_insert check;

	new_value->set_value(v);

	check = value.insert(std::pair<std::string, VariableBase *>(key, new_value->clone()));

	if(!check.second)
	{
		sysUtil::Log::print_log("Unable to add the map ", 4, 3);
	}
}

void VariableMap::get_value(std::map<std::string, int> &mv)
{
	std::map<std::string, VariableBase *>::iterator iter;

	for(iter = value.begin(); iter != value.end(); ++iter)
	{
		mv.insert(std::pair<std::string, int>(iter->first, iter->second->get_value_int()));
	}
}

void VariableMap::get_value(std::map<std::string, double> &mv)
{
	std::map<std::string, VariableBase *>::iterator iter;

	for(iter = value.begin(); iter != value.end(); ++iter)
	{
		mv.insert(std::pair<std::string, double>(iter->first, iter->second->get_value_double()));
	}
}

void VariableMap::get_value(std::map<std::string, std::string> &mv)
{
	std::map<std::string, VariableBase *>::iterator iter;

	for(iter = value.begin(); iter != value.end(); ++iter)
	{
		mv.insert(std::pair<std::string, std::string>(iter->first, iter->second->get_value_string()));
	}
}

VariableBase * VariableMap::get_value_map(const std::string &key)
{
	return value[key];
}

int VariableMap::get_num_elems_map()
{
	return (int)value.size();
}

VariableBase * VariableMap::operator[](const std::string &key)
{
	if(value.find(key) != value.end())
	{
		return value[key];
	}
	else
	{
		sysUtil::Log::print_log("Key not found", 4, 3);

		return 0;
	}
}

} /* namespace appSet */
