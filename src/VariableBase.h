/**
 * VariableBase.h
 *
 *  Created on: 07/05/2013
 *      Author: José Manuel Pintor Freire
 */

#ifndef VARIABLEBASE_H_
#define VARIABLEBASE_H_

#include <string>
#include <vector>
#include <map>
#include <iostream>

#include "Log.h"
#include "EWrongValue.h"

namespace appSet
{
	class VariableBase
	{
		public:
			VariableBase();
			virtual ~VariableBase();
			virtual VariableBase * clone() = 0;
			virtual std::string get_msg_string_values(const std::string &map_key) = 0;
			//VariableInt
			virtual void set_value(const int &v){return;} //VariableVector
			virtual int get_value_int();
			//VariableDouble
			virtual void set_value(const double &v){return;} //VariableVector
			virtual double get_value_double();
			//VariableString
			virtual void set_value(const std::string &v){return;} //VariableVector
			virtual std::string get_value_string();
			//VariableVector
			virtual VariableBase * get_value_vector(const int &index);
			virtual int get_num_elems_vec();
			virtual VariableBase * operator[](const int &index);
			//VariableMap
			virtual void set_value(const std::string &key, const int &v){return;}
			virtual void set_value(const std::string &key, const double &v){return;}
			virtual void set_value(const std::string &key, const std::string &v){return;}
			virtual void get_value(std::map<std::string, int> &mv);
			virtual void get_value(std::map<std::string, double> &mv);
			virtual void get_value(std::map<std::string, std::string> &mv);
			virtual VariableBase * get_value_map(const std::string &key);
			virtual int get_num_elems_map();
			virtual VariableBase * operator[](const std::string &key);
	};

} /* namespace appSet */
#endif /* VARIABLEBASE_H_ */
