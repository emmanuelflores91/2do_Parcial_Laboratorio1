
#ifndef MENSAJES_H_
#define MENSAJES_H_

/// @brief muestra el menú de opciones para el usuario
///
/// @param opcion = puntero al número de la opción elegida
/// @return -1 en caso de erro, 0 en caso de éxito
int ShowMenu (int* opcion );

/// @brief muestra el mensaje en caso de error para el menú
///
/// @param estado = código de error
void MsjMenu (int estado);

/// @brief muestra los mensajes en caso de error para el Controller1
///
/// @param estado = código de error
void MsjController1 (int estado);


#endif /* MENSAJES_H_ */
