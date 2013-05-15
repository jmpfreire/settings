/**
 *  EWrongValue.cpp
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

#include "EWrongValue.h"

namespace appSet {

/**
 *
 * @param m
 */
EWrongValue::EWrongValue(const std::string &m): msg(m)
{

}

/**
 *
 */
EWrongValue::~EWrongValue()
{

}

/**
 *
 * @return
 */
std::string EWrongValue::what()
{
	return msg;
}
} /* namespace appSet */
