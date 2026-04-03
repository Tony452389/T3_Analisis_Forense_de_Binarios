#include <iostream>
#include <string>

#include "suspicious.h"

void printSuspiciousStrings() {
	std::cout << "MAGIC: edu-malware-sim" << std::endl;
	std::cout << "Connecting to remote host..." << std::endl;
	std::cout << "Initializing system scan..." << std::endl;
	std::cout << "Loading enctypted payload..." << std::endl;
}

std::string decodeHiddenString(const std::string& encoded) {
	std::string decoded = encoded;

	for (size_t i = 0; i < decoded.length(); ++i) {
		decoded[i] = decoded[i] - 1; // Simple Caesar cipher decryption
	}

	return decoded;
}