#include <windows.h>
#include <iostream>
#include <string>
#include <cstring>

#include "file_ops.h"

void createDummyFile() {

	char tempPath[MAX_PATH];

	//obtener ruta TEMP
	GetTempPathA(MAX_PATH, tempPath);

	//Construir ruta completa del archivo temporal
	std::string filPath = std::string(tempPath) + "dummy.txt";

	HANDLE hFile = CreateFileA(
		filPath.c_str(),          // Nombre del archivo
		GENERIC_WRITE,            // Acceso de escritura
		0,                        // No compartir
		NULL,                     // Atributos de seguridad predeterminados
		CREATE_ALWAYS,            // Crear siempre un nuevo archivo
		FILE_ATTRIBUTE_NORMAL,    // Atributos del archivo
		NULL                      // Sin plantilla de archivo
	);

	if (hFile != INVALID_HANDLE_VALUE) {
		const char* data =
			"Execution log created\n"
			"System scan complete\n";

			DWORD bytesWritten;

		WriteFile(
			hFile,          // Handle del archivo
			data,           // Datos a escribir
			strlen(data),   // Número de bytes a escribir
			&bytesWritten,  // Número de bytes escritos
			NULL            // Sin estructura de overlapped
		);

		CloseHandle(hFile);

		std::cout << "Dummy file created at: "
			<< filPath << std::endl;
	}
	else {
		std::cout << "Failed to create dummy file. Error code: "
			<< GetLastError() << std::endl;
	}
}