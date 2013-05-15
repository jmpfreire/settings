/**
 * EWrongValue.h
 *
 *  Created on: 14/05/2013
 *      Author: José Manuel Pintor Freire
 */

#ifndef EWRONGVALUE_H_
#define EWRONGVALUE_H_

#include <string>

namespace appSet
{
	class EWrongValue
	{
		public:
			EWrongValue(const std::string &m);
			virtual ~EWrongValue();
			std::string what();
		private:
			std::string msg;
	};
} /* namespace appSet */
#endif /* EWRONGVALUE_H_ */
