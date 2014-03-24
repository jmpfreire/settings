#ifndef VARIABLEBASE_H_
#define VARIABLEBASE_H_

/**
 *  @file
 *  This file is part of libSettings
 *
 *  Copyright (C) 2014  Jose Manuel Pintor Freire
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

#include <string>
#include <vector>
#include <map>
#include <iostream>

#include "Log.h"
#include "Utils.h"
#include "EWrongValue.h"

/**
 *  \addtogroup appSet
 *  @{
 */
namespace appSet
{
	class VariableBase
	{
		public:
			VariableBase();
			virtual ~VariableBase();
			virtual VariableBase * clone() = 0;
			virtual std::string get_msg_string_values(const std::string &map_key) = 0;
			//VariableInt
			virtual void set_value(const int &v){return;} //VariableVector
			virtual int get_value_int();
			//VariableDouble
			virtual void set_value(const double &v){return;} //VariableVector
			virtual double get_value_double();
			//VariableString
			virtual void set_value(const std::string &v){return;} //VariableVector
			virtual std::string get_value_string();
			//VariableVector
			virtual VariableBase * get_value_vector(const int &index);
			virtual int get_num_elems_vec();
			virtual VariableBase * operator[](const int &index);
			//VariableMap
			virtual void set_value(const std::string &key, const int &v){return;}
			virtual void set_value(const std::string &key, const double &v){return;}
			virtual void set_value(const std::string &key, const std::string &v){return;}
			virtual void get_value(std::map<std::string, int> &mv);
			virtual void get_value(std::map<std::string, double> &mv);
			virtual void get_value(std::map<std::string, std::string> &mv);
			virtual VariableBase * get_value_map(const std::string &key);
			virtual int get_num_elems_map();
			virtual VariableBase * operator[](const std::string &key);
	};

} /*! @}*/
#endif /* VARIABLEBASE_H_ */
