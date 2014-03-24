#include "EWrongValue.h"

namespace appSet {

EWrongValue::EWrongValue(const std::string &m): msg(m)
{

}

EWrongValue::~EWrongValue()
{

}

std::string EWrongValue::what()
{
	return msg;
}
} /* namespace appSet */
