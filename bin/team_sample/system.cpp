#include <windows.h>
#include "system.h"

void launchCalculator() {
	// Ejecuta la calculadora de Windows
	WinExec("calc.exe", SW_SHOW);
}

void performDelay() {
	// Introduce un retraso de 5 segundos (5000 milisegundos)
	Sleep(5000);
}

void showFinalMessage() {
	MessageBoxA(
		NULL,
		"Execution Complete",
		"team_sample",
		MB_OK | MB_ICONINFORMATION
	);
}	