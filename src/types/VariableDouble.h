/**
 * VariableDouble.h
 *
 *  Created on: 07/05/2013
 *      Author: José Manuel Pintor Freire
 */

#ifndef VARIABLEDOUBLE_H_
#define VARIABLEDOUBLE_H_

#include <iostream>

#include "../VariableBase.h"

namespace appSet
{
	class VariableDouble: public appSet::VariableBase
	{
		public:
			VariableDouble();
			virtual ~VariableDouble();
			VariableDouble * clone();
			std::string get_msg_string_values(const std::string &map_key);
			void set_value(const double &v);
			double get_value_double();
		private:
			double value;
	};

} /* namespace appSet */
#endif /* VARIABLEDOUBLE_H_ */
