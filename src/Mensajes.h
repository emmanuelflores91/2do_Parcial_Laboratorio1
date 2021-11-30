
#ifndef MENSAJES_H_
#define MENSAJES_H_

/// @brief muestra el men� de opciones para el usuario
///
/// @param opcion = puntero al n�mero de la opci�n elegida
/// @return -1 en caso de erro, 0 en caso de �xito
int ShowMenu (int* opcion );

/// @brief muestra el mensaje en caso de error para el men�
///
/// @param estado = c�digo de error
void MsjMenu (int estado);

/// @brief muestra los mensajes en caso de error para el Controller1
///
/// @param estado = c�digo de error
void MsjController1 (int estado);


#endif /* MENSAJES_H_ */
