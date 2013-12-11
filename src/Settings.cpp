/**
 *  Settings.cpp
 *  This file is part of libSettings
 *
 *  Copyright (C) 2013  Jose Manuel Pintor Freire
 *
 *  libSettings is free software: you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation, either
 *  version 3 of the License, or (at your option) any later version.
 *
 *  libSettings is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with libSettings.  If not, see <http://www.gnu.org/licenses/>.
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
		sysUtil::Log::print_log("Unable to open settings files " + pref_file_path, 4, 3);
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
		sysUtil::Log::print_log("Exception libxml " + sysUtil::Utils::convertCharToString(ex.what()), 4, 4);

		return false;
	}
	#endif //LIBXMLCPP_EXCEPTIONS_ENABLED

	return true;
}

} /* namespace appSet */
