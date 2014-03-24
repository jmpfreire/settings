#ifndef VARIABLEMAP_H_
#define VARIABLEMAP_H_

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

#include "VariableBase.h"

#include "VariableInt.h"
#include "VariableDouble.h"
#include "VariableString.h"

/**
 *  \addtogroup appSet
 *  @{
 */
namespace appSet
{
	class VariableMap: public appSet::VariableBase
	{
		typedef std::pair<std::map<std::string,
							VariableBase *>::iterator, bool> def_check_insert;

		public:
			VariableMap();
			virtual ~VariableMap();
			VariableMap * clone();
			std::string get_msg_string_values(const std::string &map_key);
			void set_value(const std::string &key, const int &v);
			void set_value(const std::string &key, const double &v);
			void set_value(const std::string &key, const std::string &v);
		void get_value(std::map<std::string, int> &mv);
		void get_value(std::map<std::string, double> &mv);
		void get_value(std::map<std::string, std::string> &mv);
			VariableBase * get_value_map(const std::string &key);
			int get_num_elems_map();
			VariableBase * operator[](const std::string &key);
		private:
			std::map<std::string, VariableBase *> value;
	};
} /*! @}*/
#endif /* VARIABLEMAP_H_ */
