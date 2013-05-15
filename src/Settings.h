/**
 * Settings.h
 *
 *  Created on: 07/05/2013
 *      Author: José Manuel Pintor Freire
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <string>
#include <map>

#include "XmlParser.h"
#include "SchemaSettings.h"

#include "Log.h"
#include "Utiles.h"

namespace appSet
{
	class Settings
	{
		public:
			Settings();
			Settings(const std::string &pp);
			virtual ~Settings();
			Settings(const Settings &s);
			void print_settings_values();
			VariableBase & operator[](const std::string &key);
			Settings & operator=(const Settings &s);
		private:
			//Methods
			SchemaSettings * get_schema();
			bool load_settings_file(const std::string &path);
			//Attributes
			std::string pref_file_path;
			SchemaSettings schema;
	};
} /* namespace appSet */
#endif /* SETTINGS_H_ */
