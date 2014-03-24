#include "Log.h"

namespace sysUtil {

void Log::print_log(const std::string &msg, int facility, int level)
{
	std::string msg_level;
	int actual_level, actual_facility;

	actual_level = Log::get_level(level, msg_level);
	actual_facility = Log::get_facility(facility);

	openlog(0 , dfOptions, actual_facility);
	syslog(actual_level, "msg: %s | level: %d | msg level: %s", msg.c_str(), actual_level, msg_level.c_str());
	closelog();

	//Provisional
	if(level <= 8)
	{
		show_log(msg);
	}
}

void Log::show_log(const std::string &msg)
{
	std::cout<<msg<<std::endl;
}

int Log::get_level(const int &level, std::string &situation)
{
	switch(level)
	{
		case 1:
			situation = "El sistema está inutilizable";
			return LOG_EMERG;
		case 2:
			situation = "Debe tomarse una acción correctora";
			return LOG_ALERT;
		case 3:
			situation = "Condiciones críticas";
			return LOG_CRIT;
		case 4:
			situation = "Condiciones de error";
			return LOG_ERR;
		case 5:
			situation = "Condiciones de advertencia";
			return LOG_WARNING;
		case 6:
			situation = "Condición normal, pero significativa";
			return LOG_NOTICE;
		case 7:
			situation = "Mensaje informativo";
			return LOG_INFO;
		case 8:
			situation = "Mensaje de nivel de depuración";
			return LOG_DEBUG;
		default: situation = "Mensaje de nivel de depuración";
			return LOG_DEBUG;
	}
}

int Log::get_facility(const int &facility)
{
	switch(facility)
	{
		case 1: return LOG_LOCAL0;
		case 2: return LOG_LOCAL1;
		case 3: return LOG_LOCAL2;
		case 4: return LOG_LOCAL3;
		case 5: return LOG_LOCAL4;
		case 6: return LOG_LOCAL5;
		case 7: return LOG_LOCAL6;
		case 8: return LOG_LOCAL7;
		default: return LOG_LOCAL7;
	}
}

} /* namespace sysUtil */
