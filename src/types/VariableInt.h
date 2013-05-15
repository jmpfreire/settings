/**
 * VariableInt.h
 *
 *  Created on: 07/05/2013
 *      Author: José Manuel Pintor Freire
 */

#ifndef VARIABLEINT_H_
#define VARIABLEINT_H_

#include <iostream>

#include "../VariableBase.h"

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
} /* namespace appSet */
#endif /* VARIABLEINT_H_ */
