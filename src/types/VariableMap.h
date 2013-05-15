/*
 * VariableMap.h
 *
 *  Created on: 08/05/2013
 *      Author: kote
 */

#ifndef VARIABLEMAP_H_
#define VARIABLEMAP_H_

#include "../VariableBase.h"

#include "VariableInt.h"
#include "VariableDouble.h"
#include "VariableString.h"

namespace appSet
{
	class VariableMap: public appSet::VariableBase
	{
		typedef std::pair<std::map<std::string,
							VariableBase *>::iterator, bool> def_check_insert;

		public:
			VariableMap();
			virtual ~VariableMap();
			VariableMap * clone();
			std::string get_msg_string_values(const std::string &map_key);
			void set_value(const std::string &key, const int &v);
			void set_value(const std::string &key, const double &v);
			void set_value(const std::string &key, const std::string &v);
		void get_value(std::map<std::string, int> &mv);
		void get_value(std::map<std::string, double> &mv);
		void get_value(std::map<std::string, std::string> &mv);
			VariableBase * get_value_map(const std::string &key);
			int get_num_elems_map();
			VariableBase * operator[](const std::string &key);
		private:
			std::map<std::string, VariableBase *> value;
	};
} /* namespace appSet */
#endif /* VARIABLEMAP_H_ */
