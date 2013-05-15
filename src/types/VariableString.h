/**
 * VariableString.h
 *
 *  Created on: 07/05/2013
 *      Author: José Manuel Pintor Freire
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
