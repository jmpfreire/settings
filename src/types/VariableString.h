/**
 *  VariableString.h
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

#ifndef VARIABLESTRING_H_
#define VARIABLESTRING_H_

#include <iostream>

#include "../VariableBase.h"

namespace appSet
{
	class VariableString: public appSet::VariableBase
	{
		public:
			VariableString();
			virtual ~VariableString();
			VariableString * clone();
			std::string get_msg_string_values(const std::string &map_key);
			void set_value(const std::string &v);
			std::string get_value_string();
		private:
			std::string value;
	};
} /* namespace appSet */
#endif /* VARIABLESTRING_H_ */
