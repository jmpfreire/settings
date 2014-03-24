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
#include <memory>

#include "../Utilities/Log.h"
#include "../Utilities/Utils.h"
#include "../Core/EWrongValue.h"

/**
 *  \addtogroup appSet
 *  @{
 */
namespace appSet
{
	/**
	 * @class VariableBase
	 *
	 * @brief
	 */
	class VariableBase
	{
		public:
			/**
			 *
			 */
			VariableBase() = default;
			/**
			 *
			 */
			virtual ~VariableBase();
			/**
			 *
			 * @return
			 */
			virtual VariableBase * clone() const = 0;
			/**
			 *
			 * @param map_key
			 * @return
			 */
			virtual std::string get_msg_string_values(const std::string &map_key) const = 0;
			//VariableInt
			/**
			 *
			 * @param v
			 */
			virtual void set_value(const int &v){return;} //VariableVector
			/**
			 *
			 * @return
			 */
			virtual int get_value_int() const;
			//VariableDouble
			/**
			 *
			 * @param v
			 */
			virtual void set_value(const double &v){return;} //VariableVector
			/**
			 *
			 * @return
			 */
			virtual double get_value_double() const;
			//VariableString
			/**
			 *
			 * @param v
			 */
			virtual void set_value(const std::string &v){return;} //VariableVector
			/**
			 *
			 * @return
			 */
			virtual std::string get_value_string() const;
			//VariableVector
			/**
			 *
			 * @param index
			 * @return
			 */
			virtual VariableBase * get_value_vector(const int &index);
			/**
			 *
			 * @return
			 */
			virtual int get_num_elems_vec() const;
			/**
			 *
			 * @param index
			 * @return
			 */
			virtual VariableBase * operator[](const int &index);
			//VariableMap
			/**
			 *
			 * @param key
			 * @param v
			 */
			virtual void set_value(const std::string &key, const int &v){return;}
			/**
			 *
			 * @param key
			 * @param v
			 */
			virtual void set_value(const std::string &key, const double &v){return;}
			/**
			 *
			 * @param key
			 * @param v
			 */
			virtual void set_value(const std::string &key, const std::string &v){return;}
			/**
			 *
			 * @param mv
			 */
			virtual void get_value(std::map<std::string, int> &mv);
			/**
			 *
			 * @param mv
			 */
			virtual void get_value(std::map<std::string, double> &mv);
			/**
			 *
			 * @param mv
			 */
			virtual void get_value(std::map<std::string, std::string> &mv);
			/**
			 *
			 * @param key
			 * @return
			 */
			virtual VariableBase * get_value_map(const std::string &key);
			/**
			 *
			 * @return
			 */
			virtual int get_num_elems_map() const;
			/**
			 *
			 * @param key
			 * @return
			 */
			virtual VariableBase * operator[](const std::string &key);
	};

} /*! @}*/
#endif /* VARIABLEBASE_H_ */
