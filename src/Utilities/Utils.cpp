#include "Utils.h"

namespace sysUtil {

std::string Utils::converString(int valor)
{
	std::ostringstream flujo;

	flujo << valor;

	return flujo.str();

}

std::string Utils::converString(long int valor)
{
	std::ostringstream flujo;

	flujo << valor;

	return flujo.str();

}

std::string Utils::converString(double valor)
{
	std::ostringstream flujo;

	flujo << valor;

	return flujo.str();

}

std::string Utils::convertCharToString(char *cad)
{
	std::ostringstream flujo;

	flujo << cad;

	return flujo.str();
}

std::string Utils::convertCharToString(const char *cad)
{
	std::ostringstream flujo;

	flujo << cad;

	return flujo.str();
}

std::string Utils::timestamp()
{
	std::string fechHora;
	time_t rawtime;
	struct tm * timeinfo;
	char buffer [80];

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );

	strftime(buffer,80,"%Y-%m-%d %H:%M:%S",timeinfo);

    fechHora = Utils::convertCharToString(buffer);

	return fechHora;
}

std::string Utils::get_time_stamp(time_t t)
{
	std::string timeStamp;
	struct tm * timeinfo;
	char buffer [80];

	timeinfo = localtime ( &t);

	strftime(buffer,80,"%Y-%m-%d %H:%M:%S",timeinfo);

	timeStamp = Utils::convertCharToString(buffer);

	return timeStamp;
}

std::string Utils::sub_str_last(const std::string &str_original, const std::string &char_cut)
{
	std::string aux_str;
	size_t found;

	found = str_original.find_last_of(char_cut);
	aux_str = str_original.substr(0, found + 1);

	return aux_str;
}

std::string Utils::sub_str_first(const std::string &str_original, const std::string &char_cut)
{
	std::string aux_str;
	size_t found;

	found = str_original.find_first_of(char_cut);
	aux_str = str_original.substr(0, found + 1);

	return aux_str;
}

std::vector<std::string> Utils::split_boost_by_char(const std::string &str, const std::string &char_cut)
{
	std::vector<std::string> v_str;

	boost::split(v_str, str, boost::is_any_of(char_cut));

	return v_str;
}

void Utils::show_load_progress(const int &percent)
{
	std::string bar;

	for(int i = 0; i < 50; i++)
	{
		if( i < (percent/2))
		{
			bar.replace(i,1,"=");
		}
		else if( i == (percent/2))
		{
			bar.replace(i,1,">");
		}
		else
		{
			bar.replace(i,1," ");
		}
	  }

	  std::cout<< "\r" "[" << bar << "] ";
	  std::cout.width( 3 );
	  percent == 100 ? std::cout<< percent << "%     " << std::endl :
			  std::cout<< percent << "%     " << std::flush;
}
} /* namespace sysUtil */
