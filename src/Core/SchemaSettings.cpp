#include "SchemaSettings.h"

namespace appSet {

SchemaSettings::SchemaSettings(): id_schema("")
{
	settings_table.clear();
}

SchemaSettings::~SchemaSettings()
{
	for(auto &th : settings_table)
	{
		delete th.second;
		th.second = nullptr;
	}

	settings_table.clear();
}

SchemaSettings::SchemaSettings(const SchemaSettings &ss)
{
	operator=(ss);
}

void SchemaSettings::print_settings_values() const
{
	std::cout<<std::endl;
	sysUtil::Log::print_log("***************INICIO FICHERO CONFIGURACION***************", 4, 7);
	std::cout<<std::endl;

	sysUtil::Log::print_log("Preferencias id: " + this->id_schema, 4, 7);

	for(auto elem_table : settings_table)
	{
		std::string part_msg;

		part_msg =  elem_table.second->get_msg_string_values(elem_table.first);

		sysUtil::Log::print_log(part_msg, 4, 7);
	}

	std::cout<<std::endl;
	sysUtil::Log::print_log("***************FIN FICHERO CONFIGURACION***************", 4, 7);
	std::cout<<std::endl;
}

void SchemaSettings::set_id_schema(const std::string &is)
{
	id_schema = is;
}

void SchemaSettings::set_value(const std::string &key, const std::string &value)
{
	def_check_insert check;

	check = settings_table.insert(std::make_pair(key, analize_type_data(value)->clone()));

	if(!check.second)
	{
		sysUtil::Log::print_log("Unable to add the element " + value, 4, 3);
	}
}

void SchemaSettings::set_value(const std::string &key, const std::vector<std::string> &value)
{
	VariableVector * new_vec = new VariableVector;
	def_check_insert check;

	for(auto elem_str : value)
	{
		this->set_data_vector(*new_vec, elem_str);
	}

	check = settings_table.insert(std::make_pair(key, new_vec->clone()));

	if(!check.second)
	{
		sysUtil::Log::print_log("Unable to add the vector ", 4, 3);
	}

	delete new_vec;
	new_vec = nullptr;
}

void SchemaSettings::set_value(const std::string &key, std::map<std::string, std::string> value)
{
	VariableMap * new_map = new VariableMap;
	def_check_insert check;

	for(auto elem_pair : value)
	{
		this->set_data_map(*new_map, elem_pair.first, elem_pair.second);
	}

	check = settings_table.insert(std::make_pair(key, new_map->clone()));

	if(!check.second)
	{
		sysUtil::Log::print_log("Unable to add the map ", 4, 3);
	}

	delete new_map;
	new_map = nullptr;
}

VariableBase & SchemaSettings::operator[](const std::string &key)
{
	return *settings_table[key];
}

SchemaSettings & SchemaSettings::operator=(const SchemaSettings &ss)
{
	for(def_settings::const_iterator it = ss.settings_table.cbegin(); it != ss.settings_table.cend(); it++)
	{
		this->settings_table.insert(std::make_pair(it->first, it->second->clone()));
	}

	return *this;
}

std::shared_ptr<VariableBase> SchemaSettings::analize_type_data(const std::string &value)
{
	std::shared_ptr<VariableBase> new_var;

	try
	{
		double val = std::stod(value);

		size_t found_double = value.find_first_of(".");

		if(found_double != std::string::npos)
		{
			std::unique_ptr<VariableDouble> unique (new VariableDouble);
			new_var = std::move(unique);

			new_var->set_value(val);
		}
		else
		{
			int val_int = std::stoi(value);

			std::unique_ptr<VariableInt> unique(new VariableInt);
			new_var = std::move(unique);

			new_var->set_value(val_int);
		}
	}
	catch(...)
	{
		std::unique_ptr<VariableString> unique(new VariableString);
		new_var = std::move(unique);

		std::string aux_str = value;

		aux_str.erase(std::remove(aux_str.begin(), aux_str.end(), '\"'), aux_str.end());

		new_var->set_value(aux_str);
	}

	return new_var;
}

void SchemaSettings::set_data_vector(VariableVector &vec_aux, const std::string &value)
{
	try
	{
		double val = std::stod(value);

		size_t found_double = value.find_first_of(".");

		if(found_double != std::string::npos)
		{
			vec_aux.set_value(val);
		}
		else
		{
			int val_int = std::stoi(value);

			vec_aux.set_value(val_int);
		}
	}
	catch(...)
	{
		std::string aux_str = value;

		aux_str.erase(std::remove(aux_str.begin(), aux_str.end(), '\"'), aux_str.end());

		vec_aux.set_value(aux_str);
	}
}

void SchemaSettings::set_data_map(VariableMap &map_aux, const std::string &key, const std::string &value)
{
	try
	{
		double val = std::stod(value);

		size_t found_double = value.find_first_of(".");

		if(found_double != std::string::npos)
		{
			map_aux.set_value(key, val);
		}
		else
		{
			int val_int = std::stoi(value);

			map_aux.set_value(key, val_int);
		}
	}
	catch(...)
	{
		std::string aux_str = value;

		aux_str.erase(std::remove(aux_str.begin(), aux_str.end(), '\"'), aux_str.end());

		map_aux.set_value(key, aux_str);
	}
}
} /* namespace appSet */
