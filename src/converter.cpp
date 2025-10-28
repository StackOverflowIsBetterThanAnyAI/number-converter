#include "converter.h"
#include <iostream>
#include <list>
#include <regex>
#include <cmath>

std::string reverseString(std::string str) {
	std::string reverse = "";

	for (int i = str.length() - 1; i >= 0; i--) {
		reverse += str[i];
	}
	return reverse;
}

std::string convertDecToHex(int num) {
	if (num == 10) {
		return "A";
	}
	if (num == 11) {
		return "B";
	}
	if (num == 12) {
		return "C";
	}
	if (num == 13) {
		return "D";
	}
	if (num == 14) {
		return "E";
	}
	if (num == 15) {
		return "F";
	}
	return std::to_string(num);
}

std::string convertHexToDec(std::string str) {
	if (str == "A") {
		return "10";
	}
	if (str == "B") {
		return "11";
	}
	if (str == "C") {
		return "12";
	}
	if (str == "D") {
		return "13";
	}
	if (str == "E") {
		return "14";
	}
	if (str == "F") {
		return "15";
	}
	return str;
}

std::string decimalToBinary(int num, std::string bit) {
	int q = num / 2;
	int r = num - q * 2;

	bit += std::to_string(r);

	if (q > 0) {
		return decimalToBinary(q, bit);
	}
	return bit;
}

std::string decimalToHex(int num, std::string bit) {
	int q = num / 16;
	int r = num - q * 16;

	bit += convertDecToHex(r);

	if (q > 0) {
		return decimalToHex(q, bit);
	}
	return bit;
}

std::string binaryToDecimal(std::string str) {
	int result = 0;

	for (int i = 0; i < str.length(); i++) {
		result += (str[i] - '0') * std::pow(2, str.length() - i - 1);
	}
	return std::to_string(result);
}

std::string binaryToHex(std::string str) {
	int missingZeros = (4 - (str.length() % 4)) % 4;

	for (int i = 0; i < missingZeros; i++) {
		str = "0" + str;
	}

	int numChunks = str.length() / 4;
	std::string result = "";

	for (int i = 0; i < numChunks; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			sum += (str[i * 4 + j] - '0') * std::pow(2, 3 - j);
		}
		result += convertDecToHex(sum);
	}
	return result;
}

std::string hexToDecimal(std::string str) {
	std::transform(str.begin(), str.end(), str.begin(),
		[](char c) { return std::toupper(c); });

	int result = 0;

	for (int i = 0; i < str.length(); i++) {
		std::string s = convertHexToDec(std::string(1, str[i]));
		int p = (int)std::pow(16, str.length() - i - 1);
		result += std::stoi(s) * p;
	}
	return std::to_string(result);
}

std::string hexToBinary(std::string str) {
	return decimalToBinary(std::stoi(hexToDecimal(str)), "");
}

std::string calculateOutput(
	std::string formatFrom, std::string formatTo, std::string numberIn
) {
	switch (std::stoi(formatFrom)) {
	case 0:
		if (formatTo == "0") {
			return numberIn;
		}
		if (formatTo == "1") {
			return reverseString(decimalToHex(std::stoi(numberIn), ""));
		}
		if (formatTo == "2") {
			return reverseString(decimalToBinary(std::stoi(numberIn), ""));
		}
		break;
	case 1:
		if (formatTo == "0") {
			return hexToDecimal(numberIn);
		}
		if (formatTo == "1") {
			return numberIn;
		}
		if (formatTo == "2") {
			return reverseString(hexToBinary(numberIn));
		}
		break;
	case 2:
		if (formatTo == "0") {
			return binaryToDecimal(numberIn);
		}
		if (formatTo == "1") {
			return binaryToHex(numberIn);
		}
		if (formatTo == "2") {
			return numberIn;
		}
		break;
	}
}

std::string validateFormat(std::string question) {
	std::list<std::string> validInputs = { "0", "1", "2" };

	while (true) {
		try {
			std::cout << question << std::endl;
			std::cout << "[decimal|hex|binary] [0|1|2]" << std::endl;

			std::string input;
			std::cin >> input;

			bool isValidInput = false;

			for (std::string i : validInputs) {
				if (i == input) {
					isValidInput = true;
				}
			}

			if (!isValidInput) {
				throw (isValidInput);
			}

			return input;
		}
		catch (...) {
			std::cout << "Please enter a number between 0 and 2." << std::endl;
		}
	}
}

std::string validateInput(std::string formatFrom) {
	while (true) {
		try {
			std::cout << "Please enter your number." << std::endl;

			std::string input;
			std::cin >> input;

			std::regex decPat("^[0-9]+$");
			std::regex hexPat("^[0-9A-F]+$", std::regex_constants::icase);
			std::regex binPat("^[01]+$");

			bool decMatch = std::regex_match(input, decPat);
			bool hexMatch = std::regex_match(input, hexPat);
			bool binMatch = std::regex_match(input, binPat);

			if (formatFrom == "0" && decMatch) {
				return input;

			}
			if (formatFrom == "1" && hexMatch) {
				return input;
			}
			if (formatFrom == "2" && binMatch) {
				return input;
			}

			throw false;
		}
		catch (...) {
			std::cout << "Please enter a valid number from your chosen number format." << std::endl;
		}
	}
}
