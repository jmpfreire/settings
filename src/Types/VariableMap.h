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
	/**
	 * @class VariableMap
	 *
	 * @brief
	 */
	class VariableMap: public appSet::VariableBase
	{
		/**
		 *
		 */
		typedef std::pair<std::map<std::string,
							VariableBase *>::iterator, bool> def_check_insert;

		public:
			/**
			 *
			 */
			VariableMap();
			/**
			 *
			 */
			~VariableMap();
			/**
			 *
			 * @return
			 */
			VariableMap * clone() const;
			/**
			 *
			 * @param map_key
			 * @return
			 */
			std::string get_msg_string_values(const std::string &map_key) const;
			/**
			 *
			 * @param key
			 * @param v
			 */
			void set_value(const std::string &key, const int &v);
			/**
			 *
			 * @param key
			 * @param v
			 */
			void set_value(const std::string &key, const double &v);
			/**
			 *
			 * @param key
			 * @param v
			 */
			void set_value(const std::string &key, const std::string &v);
			/**
			 *
			 * @param mv
			 */
			void get_value(std::map<std::string, int> &mv);
			/**
			 *
			 * @param mv
			 */
			void get_value(std::map<std::string, double> &mv);
			/**
			 *
			 * @param mv
			 */
			void get_value(std::map<std::string, std::string> &mv);
			/**
			 *
			 * @param key
			 * @return
			 */
			VariableBase * get_value_map(const std::string &key);
			/**
			 *
			 * @return
			 */
			int get_num_elems_map() const;
			/**
			 *
			 * @param key
			 * @return
			 */
			VariableBase * operator[](const std::string &key);
		private:
			std::map<std::string, VariableBase *> value; /**< */
	};
} /*! @}*/
#endif /* VARIABLEMAP_H_ */
