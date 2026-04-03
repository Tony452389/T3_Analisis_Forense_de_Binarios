#pragma once

//Funcion que abre la calculadora de Windows
//Nota: Esta función utiliza la API de Windows para ejecutar la calculadora. Asegúrate de que tu entorno de desarrollo esté configurado para compilar aplicaciones de Windows y que tengas los permisos necesarios para ejecutar programas en tu sistema.
void launchCalculator();

//Funcion que introduce un delay
//Nota: Esta función utiliza la función Sleep de la API de Windows para introducir un retraso en la ejecución del programa. El tiempo de retraso se especifica en milisegundos (1000 ms = 1 segundo). Puedes ajustar el valor del retraso según tus necesidades.
void performDelay();

//Funcion que muestra mensaje final
//Nota: Esta función utiliza la función MessageBoxA de la API de Windows para mostrar un mensaje emergente al usuario. El mensaje se muestra con un título y un ícono de información. Puedes personalizar el mensaje, el título y el tipo de ícono según tus preferencias.
void showFinalMessage();
