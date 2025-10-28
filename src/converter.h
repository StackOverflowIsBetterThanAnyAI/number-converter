#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>

std::string reverseString(std::string str);

std::string convertDecToHex(int num);
std::string convertHexToDec(std::string str);
std::string decimalToBinary(int num, std::string bit);
std::string decimalToHex(int num, std::string bit);
std::string binaryToDecimal(std::string str);
std::string binaryToHex(std::string str);
std::string hexToDecimal(std::string str);
std::string hexToBinary(std::string str);

std::string calculateOutput(std::string formatFrom, std::string formatTo, std::string numberIn);

std::string validateFormat(std::string question);
std::string validateInput(std::string formatFrom);

#endif
