#include <iostream>
#include <string>

#include "suspicious.h"
#include "system.h"
#include "file_ops.h"

int main() {
	printSuspiciousStrings();

	//Verificar debugger
	if (checkDebugger()) {
		return 0;
	}

	std::string password = requestPassword();

	if(!validatePassword(password)) {
		return 0;
	}

	launchCalculator();
	performDelay();
	createDummyFile();
	showFinalMessage();
	
	return 0;
}

