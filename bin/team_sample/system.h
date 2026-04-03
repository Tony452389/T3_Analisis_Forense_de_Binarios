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
//Nota: Esta función solicita al usuario que ingrese una contraseña a través de la consola. La función devuelve la contraseña ingresada como una cadena de texto (std::string). Puedes personalizar el mensaje de solicitud y agregar validaciones adicionales según tus necesidades.
std::string requestPassword();

//Valida la contraseña ingresada por el usuario
bool validatePassword(const std::string& password);