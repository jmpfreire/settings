#ifndef UTILS_H_
#define UTILS_H_

/**
 * @file
 *
 * @date Mar 9, 2012
 * @author José Manuel Pintor Freire
 */

#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <time.h>
#include <vector>

#include <boost/algorithm/string.hpp>

/**
 *  \addtogroup sysUtil
 *  @{
 */
namespace sysUtil
{
	/**
	* @class Utiles
	*
	* @brief
	*/
	class Utils
	{
		public:
			/**
			 *
			 * @param value
			 * @return
			 */
			template <class T> static std::string convert_to_string(const T &value)
			{
				std::string str_res("");

				if(std::is_arithmetic<T>::value)
				{
					std::ostringstream flujo;

					flujo << value;

					str_res = flujo.str();
				}

				return str_res;
			}
			/**
			 * Convierte una cadena de caracteres (char *) a una cadena de caracteres de tipo (string)
			 * @param cad, char * que contiene la cadena de caracteres.
			 * @return La cadena de caracteres convertida a una de tipo (string).
			 */
			static std::string convertCharToString(char *cad);
			/**
			 * Convierte una cadena de caracteres (char *) a una cadena de caracteres de tipo (string)
			 * @param cad, const char * que contiene la cadena de caracteres.
			 * @return La cadena de caracteres convertida a una de tipo (string).
			 */
			static std::string convertCharToString(const char *cad);
			/**
			 * Obtiene la hora local del sistema generando un time stamp de la forma "año-mes-dia-hora-minuto-segundo".
			 * @return El timestamp en una cadena de caracteres de tipo (string).
			 */
			static std::string timestamp();
			/**
			 * Convierte la variable time_t a un string en formato timestamp
			 * @param t, tiempo en formato time_t
			 * @return string, cadena de caracteres que contiene el timestamp
			 */
			static std::string get_time_stamp(time_t t);
			/**
			 * Extrae una subcadena a partir de una cadena.
			 * @param str_original, cadena de caracteres que contiene la cadena original.
			 * @param char_cut, cadena de caracteres que contiene la cadena por donde se realizara el corte.
			 * @return string, cadena de caracteres que contiene la cadena cortada.
			 */
			static std::string sub_str_last(const std::string &str_original, const std::string &char_cut);
			/**
			 * Extrae una subcadena a partir de una cadena.
			 * @param str_original, cadena de caracteres que contiene la cadena original.
			 * @param char_cut, cadena de caracteres que contiene la cadena por donde se realizara el corte.
			 * @return string, cadena de caracteres que contiene la cadena cortada.
			 */
			static std::string sub_str_first(const std::string &str_original, const std::string &char_cut);
			/**
			 * Divide un string en varios string separados por un caracter el cual es pasado por parametro en char_cut
			 * @param str string que contiene la cadena a dividir
			 * @param char_cut string que contiene el caracter de corte
			 * @return devuelve un vector de string con el string dividido
			 */
			static std::vector<std::string> split_boost_by_char(const std::string &str, const std::string &char_cut);
			/**
			 * Barra de progreso que muestra el progreso en consola en la misma linea
			 * @param percent entero que contiene el porcentaje de progreso
			 */
			static void show_load_progress(const int &percent);
	};
}	/*! @}*/

#endif /* UTILS_H_ */
