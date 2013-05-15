/**
 * EWrongValue.cpp
 *
 *  Created on: 14/05/2013
 *      Author: José Manuel Pintor Freire
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
