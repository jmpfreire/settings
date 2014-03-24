#include "EWrongValue.h"

namespace appSet {

EWrongValue::EWrongValue(const std::string &m): msg(m)
{

}

std::string EWrongValue::what()
{
	return msg;
}
} /* namespace appSet */
