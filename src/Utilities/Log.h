#ifndef _LOG_H_
#define _LOG_H_

/**
 * @file
 *
 * @date 11/12/2013
 * @author José Manuel Pintor Freire
 *
 *  @brief
 *  VALOR POR DEFECTO: LOG_CONS | LOG_PID | LOG_NDELAY;
 *
 *  Especifica opciones de configuración al syslog. Es resultado de la combinación con
 *  el operador de bits O inclusivo de cualquiera de los siguientes valores.
 *
 *	LOG_PERROR			Imprime también en stderr. (No presente en SUSv3.)
 *	LOG_CONS			Escribe directamente en la consola del sistema si hay  un  error
 *  					mientras se está enviando algo al registrador del sistema.
 *	LOG_PID				Incluye el PID con cada mensaje.
 *	LOG_NDELAY			Abre  la  conexión  inmediatamente  (normalmente, la conexión se
 *  					abre cuando se registra el primer mensaje).
 *	LOG_ODELAY			La  opuesta de LOG_NDELAY; la apertura de la conexión se retrasa
 *  					hasta que se invoca a syslog().  (Esta es la opción por defecto,
 *  					y no necesita ser especificada.)
 *
 *
 *  FACILITY.
 *
 *  VALOR POR DEFECTO: LOG_LOCAL0;
 *
 *  El  argumento  facility se emplea para especificar qué tipo de programa
 *  está registrando  el  mensaje.  Esto  permite  que  en  el  fichero  de
 *  configuración  se  especifique  que mensajes de diferentes programas se
 *  manejen de forma distinta.
 *
 *  Las diferentes valores son:
 *
 *  LOG_AUTH				Mensajes de seguridad o autorización.
 *  LOG_AUTHPRIV			Mensajes de seguridad o autorización (privado).
 *  LOG_CRON				El demonio del reloj (cron y at).
 *  LOG_DAEMON				Demonios del sistema con valor de ‘facility’ separado.
 *  LOG_FTP 				Demonio de ftp.
 *  LOG_KERN				Mensajes del núcleo.
 *  LOG_LPR 				Subsistema de impresora de línea (de impresión).
 *  LOG_MAIL				Subsistema de correo.
 *  LOG_NEWS				Subsistema de tablón de anuncios USENET News.
 *  LOG_SYSLOG				Mensajes generados internamente por syslogd.
 *  LOG_USER				Mensajes genéricos del nivel de usuario.
 *  LOG_UUCP				Subsistema de UUCP.
 *  LOG_LOCAL0-7			Reservados para uso local.
 *
 *
 *  LEVEL.
 *
 *  Esto determina la importancia del mensaje. Los niveles son, en orden de
 *  importancia decreciente:
 *
 *  LOG_EMERG            		El sistema está inutilizable.
 *  LOG_ALERT             		Debe tomarse una acción correctora inmediatamente.
 *  LOG_CRIT              		Condiciones críticas.
 *  LOG_ERR               		Condiciones de error.
 *  LOG_WARNING           		Condiciones de advertencia.
 *  LOG_NOTICE            		Condición normal, pero significativa.
 *  LOG_INFO               		Mensaje informativo.
 *  LOG_DEBUG              		Mensaje del nivel de depuración.
 *
 */

#include <stdlib.h>
#include <iostream>
#include <syslog.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>
#include <string.h>
#include <fstream>

/**
 *  \addtogroup sysUtil
 *  @{
 */
namespace sysUtil
{
	/**
	 * @class Log
	 *
	 * @brief Esta clase gestiona los logs del sistema, está compuesta por métodos estáticos.
	 */
	class Log
	{
		public:
			/**
			 * Imprime un log en el sistema.
			 * @param msg string que contiene el mensaje a imprimir
			 * @param facility entero que representa el subgrupo del log a mantener en el sistema
			 * @param level entero que representa la gravedad del log a mostrar 8 menos grave 1 más grave
			 */
			static void print_log(const std::string &msg, int facility = 8, int level = 8);
			/**
			 * Imprime en la consola el log pasado por parámetro
			 * @param msg string que contiene el log a imprimir
			 */
			static void show_log(const std::string &msg);
		private:
			//Metodos privados
			/**
			 * Devuelve el nivel de gravedad de un log.
			 * @param level entero que contiene el nivel de gravedad del log.
			 * @param situation referencia a un string que obtiene el tipo de log segun su nivel
			 * @return El nivel de log
			 */
			static int get_level(const int &level, std::string &situation);
			/**
			 * Devuelve el subgrupo al que pertenece el log
			 * @param facility entero que representa el subgrupo del log a mantener en el sistema
			 * @return El facility del log
			 */
			static int get_facility(const int &facility);
			//Variables
			static const int dfOptions = LOG_CONS | LOG_PID; /**< Opciones de configuración por defecto*/
	};
}  /*! @}*/
#endif /* LOG_H_ */
