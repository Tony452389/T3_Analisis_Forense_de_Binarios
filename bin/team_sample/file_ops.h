#pragma once

//Funcion que crea un archivo temporal
//Nota: Esta función utiliza la API de Windows para crear un archivo temporal en el directorio TEMP del sistema. El archivo se llama "dummy.txt" y contiene algunos datos de ejemplo. Asegúrate de que tu entorno de desarrollo esté configurado para compilar aplicaciones de Windows y que tengas los permisos necesarios para crear archivos en el sistema.
void createDummyFile();
