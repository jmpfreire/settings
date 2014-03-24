#ifndef VARIABLEINT_H_
#define VARIABLEINT_H_

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

#include <iostream>

#include "../VariableBase.h"

/**
 *  \addtogroup appSet
 *  @{
 */
namespace appSet
{
	class VariableInt: public appSet::VariableBase
	{
		public:
			VariableInt();
			virtual ~VariableInt();
			VariableInt * clone();
			std::string get_msg_string_values(const std::string &map_key);
			void set_value(const int &v);
			int get_value_int();
		private:
			int value;
	};
} /*! @}*/
#endif /* VARIABLEINT_H_ */
