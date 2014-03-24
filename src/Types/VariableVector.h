#ifndef VARIABLEVECTOR_H_
#define VARIABLEVECTOR_H_

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
	 * @class VariableVector
	 *
	 * @brief
	 */
	class VariableVector: public appSet::VariableBase
	{
		public:
			/**
			 *
			 */
			VariableVector();
			/**
			 *
			 */
			~VariableVector();
			/**
			 *
			 * @return
			 */
			VariableVector * clone() const;
			/**
			 *
			 * @param map_key
			 * @return
			 */
			std::string get_msg_string_values(const std::string &map_key) const;
			/**
			 *
			 * @param v
			 */
			void set_value(const int &v);
			/**
			 *
			 * @param v
			 */
			void set_value(const double &v);
			/**
			 *
			 * @param v
			 */
			void set_value(const std::string &v);
			/**
			 *
			 * @param index
			 * @return
			 */
			VariableBase * get_value_vector(const int &index);
			/**
			 *
			 * @return
			 */
			int get_num_elems_vec() const;
			/**
			 *
			 * @param index
			 * @return
			 */
			VariableBase * operator[](const int &index);
		private:
			std::vector<VariableBase *> value; /**< */
	};
} /*! @}*/
#endif /* VARIABLEVECTOR_H_ */
