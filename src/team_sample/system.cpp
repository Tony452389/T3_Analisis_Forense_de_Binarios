#include <string>
#include <iostream>

#include <windows.h>
#include "system.h"
#include "suspicious.h"

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

bool checkDebugger() {
	if (IsDebuggerPresent()) {
		MessageBoxA(
			NULL,
			"Debugger detected!",
			"Warning",
			MB_OK | MB_ICONWARNING
		);
		return true;
	}
	return false;
}

std::string requestPassword() {
	std::string password;
	std::cout << "Enter password: ";
	std::cin >> password;
	return password;
}

bool validatePassword(const std::string& password) {
	std::string encodedPassword = "QAttx1se234";

	std::string correctPassword = decodeHiddenString(encodedPassword);
	
	if (password == correctPassword) {
		std::cout << "Access granted!" << std::endl;

		return true;
	}
	else {
		MessageBoxA(
			NULL,
			"Invalid password!",
			"Access Denied",
			MB_OK | MB_ICONERROR
		);

		return false;
	}
}