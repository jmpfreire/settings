/**
 *  EWrongValue.h
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
