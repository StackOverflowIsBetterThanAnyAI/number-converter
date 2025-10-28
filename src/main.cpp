#include "converter.h"
#include <iostream>

int main() {
	std::string formatFrom = validateFormat("What is the number format of your number?");
	std::string formatTo = validateFormat("What format do you want the number to be converted to?");

	std::string numberIn = validateInput(formatFrom);
	std::string numberOut = calculateOutput(formatFrom, formatTo, numberIn);

	std::cout << numberIn << " is the same as " << numberOut << std::endl;
}
