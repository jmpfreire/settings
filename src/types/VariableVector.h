/**
 * VariableVector.h
 *
 *  Created on: 10/05/2013
 *      Author: José Manuel Pintor Freire
 */

#ifndef VARIABLEVECTOR_H_
#define VARIABLEVECTOR_H_

#include "../VariableBase.h"

#include "VariableInt.h"
#include "VariableDouble.h"
#include "VariableString.h"

namespace appSet
{

	class VariableVector: public appSet::VariableBase
	{
		public:
			VariableVector();
			virtual ~VariableVector();
			VariableVector * clone();
			std::string get_msg_string_values(const std::string &map_key);
			void set_value(const int &v);
			void set_value(const double &v);
			void set_value(const std::string &v);
			VariableBase * get_value_vector(const int &index);
			int get_num_elems_vec();
			VariableBase * operator[](const int &index);
		private:
			std::vector<VariableBase *> value;
	};
} /* namespace appSet */
#endif /* VARIABLEVECTOR_H_ */
