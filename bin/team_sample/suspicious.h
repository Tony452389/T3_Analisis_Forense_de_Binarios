#pragma once

#include <string>

//Funcion que imprime cadenas sospechosas
//Nota: Esta función imprime varias cadenas de texto que podrían ser indicativas de actividades sospechosas o maliciosas. Puedes personalizar las cadenas impresas para que se ajusten a tus necesidades o para simular diferentes escenarios de malware.
void printSuspiciousStrings();

//----------------------------------------------------------------------------------------- V3 --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Funcion que decodifica un string ofuscado
//Nota: Esta función implementa una decodificación simple utilizando un cifrado César, donde cada carácter del string codificado se desplaza un lugar hacia atrás en el alfabeto. Puedes modificar la lógica de decodificación según el método de ofuscación que desees utilizar.
std::string decodeHiddenString(const std::string& encoded);

//Funcion que agrega strings falsas para el analisis
void addDecoyStrings();