#pragma once

#include <string>

//Funcion que abre la calculadora de Windows
//Nota: Esta función utiliza la API de Windows para ejecutar la calculadora. Asegúrate de que tu entorno de desarrollo esté configurado para compilar aplicaciones de Windows y que tengas los permisos necesarios para ejecutar programas en tu sistema.
void launchCalculator();

//Funcion que introduce un delay
//Nota: Esta función utiliza la función Sleep de la API de Windows para introducir un retraso en la ejecución del programa. El tiempo de retraso se especifica en milisegundos (1000 ms = 1 segundo). Puedes ajustar el valor del retraso según tus necesidades.
void performDelay();

//Funcion que muestra mensaje final
//Nota: Esta función utiliza la función MessageBoxA de la API de Windows para mostrar un mensaje emergente al usuario. El mensaje se muestra con un título y un ícono de información. Puedes personalizar el mensaje, el título y el tipo de ícono según tus preferencias.
void showFinalMessage();

//----------------------------------------------------------------------------------------- V2 --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Funcion que verifica debugger
//Nota: Esta función utiliza la función IsDebuggerPresent de la API de Windows para verificar si el programa está siendo ejecutado bajo un depurador. Si se detecta un depurador, se muestra un mensaje de advertencia al usuario. Esta función es útil para evitar que el programa sea analizado o modificado por depuradores.
bool checkDebugger();

//Solicita contraseña al usuario
//Nota: Esta función solicita al usuario que ingrese una contraseña a través de la consola. El valor ingresado por el usuario se almacena en una variable y se devuelve como resultado de la función. Puedes personalizar el mensaje de solicitud o agregar validaciones adicionales según tus necesidades.
std::string requestPassword();

//Valida la contraseña ingresada por el usuario
//Nota: Esta función compara la contraseña ingresada por el usuario con una contraseña codificada previamente. La contraseña codificada se decodifica utilizando la función decodeHiddenString, que implementa una lógica de decodificación simple. Si la contraseña ingresada coincide con la contraseña correcta, se muestra un mensaje de acceso concedido y la función devuelve true. De lo contrario, se muestra un mensaje de error y la función devuelve false.
bool validatePassword(const std::string& password);