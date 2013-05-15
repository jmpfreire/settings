/**
 * Settings.cpp
 *
 *  Created on: 07/05/2013
 *      Author: José Manuel Pintor Freire
 */

#include "Settings.h"

namespace appSet {

/**
 *
 */
Settings::Settings():pref_file_path("")
{

}

/**
 *
 * @param pp
 */
Settings::Settings(const std::string &pp): pref_file_path(pp)
{
	if(!this->load_settings_file(pref_file_path))
	{
		drivIn::Log::print_log("Unable to open settings files " + pref_file_path, 4, 3);
	}
}

/**
 *
 */
Settings::~Settings()
{
	// TODO Auto-generated destructor stub
}

/**
 *
 * @param s
 */
Settings::Settings(const Settings &s)
{
	pref_file_path = s.pref_file_path;
	schema = s.schema;
}

/**
 *
 */
void Settings::print_settings_values()
{
	this->schema.print_settings_values();
}

/**
 *
 * @return
 */
SchemaSettings * Settings::get_schema()
{
	return &this->schema;
}

/**
 *
 * @param key
 * @return
 */
VariableBase & Settings::operator[](const std::string &key)
{
	return this->schema[key];
}

/**
 *
 * @param s
 * @return
 */
Settings & Settings::operator=(const Settings &s)
{
	this->pref_file_path = s.pref_file_path;
	this->schema = s.schema;

	return *this;
}

/**
 *
 * @param path
 * @return
 */
bool Settings::load_settings_file(const std::string &path)
{
	// Parse the entire document in one go:
	#ifdef LIBXMLCPP_EXCEPTIONS_ENABLED
	try
	{
	#endif //LIBXMLCPP_EXCEPTIONS_ENABLED
		XmlParser parse(*this->get_schema());
		parse.set_substitute_entities(true);
		parse.parse_file(path);
	#ifdef LIBXMLCPP_EXCEPTIONS_ENABLED
	}
	catch(const xmlpp::exception& ex)
	{
		drivIn::Log::print_log("Exception libxml " + drivIn::Utiles::convertCharToString(ex.what()), 4, 4);

		return false;
	}
	#endif //LIBXMLCPP_EXCEPTIONS_ENABLED

	return true;
}

} /* namespace appSet */
