
#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

void printConvert(std::string toChar, std::string toInt, std::string toFloat, std::string toDouble) {
	std::cout << toChar << std::endl;
	std::cout << toInt << std::endl;
	std::cout << toFloat << std::endl;
	std::cout << toDouble << std::endl;
}

bool isDisplayable(std::string toConvert) {
	int length = toConvert.length();
	bool dotPresent = false;

	if (length <= 0)
		return false;

	for (int i = 0; toConvert[i]; i++) {
		if (i != 0 && (toConvert[i] == '+' || toConvert[i] == '-'))
			return false;
		if (toConvert[i] == '.') {
			if (!isdigit(toConvert[i - 1]) || !isdigit(toConvert[i + 1]))
				return false;
			if (dotPresent)
				return false;
			dotPresent = true;
		}
		if (toConvert[i] == 'f') {
			if (i != length && (!isdigit(toConvert[i - 1]) || length == 1))
				return false;
		}
		if (i != 0 && !isdigit(toConvert[i]) && !isdigit(toConvert[i - 1]))
			return false;
	}
	return true;
}

void convertToChar(char c) {
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	std::cout << "Char: " << c << std::endl;
	std::cout << "Int: " << i << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void convertToInt(int i) {
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	if (!isprint(c))
		std::cout << "Char: not displayable\n";
	else
		std::cout << "Char: " << c << std::endl;
	std::cout << "Int: " << i << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << f << "f\n";
	std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;

}

void convertToFloat(float f) {
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);

	if (!isprint(c))
		std::cout << "Char: not displayable\n";
	else
		std::cout << "Char: " << c << std::endl;
	std::cout << "Int: " << i << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << f << "f\n";
	std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void convertToDouble(double d) {
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	if (!isprint(c))
		std::cout << "Char: not displayable\n";
	else
		std::cout << "Char: " << c << std::endl;
	std::cout << "Int: " << i << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << f << "f\n";
	std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::convert(std::string toConvert) {

	int toInt;
	float toFloat;
	double toDouble;

	if (toConvert == "nanf" || toConvert == "nan") {
		printConvert("impossible", "impossible", "nanf", "nan");
		return ;
	}
	if (toConvert == "+inff" || toConvert == "+inf") {
			printConvert("impossible", "impossible", "+inff", "+inf");
			return ;
	}
	if (toConvert == "-inff" || toConvert == "-inf") {
		printConvert("impossible", "impossible", "-inff", "-inf");
		return ;
	}
	if (toConvert.length() == 1 && !std::isdigit(toConvert[0])) {
		convertToChar(toConvert.at(0));
		return ;
	}
	if (isDisplayable(toConvert) == false) {
		std::cout << "invalid input\n";
		return ;
	}
	if (toConvert.length() > 1 && toConvert[toConvert.length() - 1] == 'f') {
		std::stringstream convertFloat(toConvert);
		if (!(convertFloat >> toFloat)) {
			std::cerr << "Error: parsing float failed\n";
			return ;
		}
		convertToFloat(toFloat);
	}
	else if (toConvert.find('.') != std::string::npos) {
		std::stringstream convertDouble(toConvert);
		if (!(convertDouble >> toDouble)) {
			std::cerr << "Error: parsing double failed\n";
			return ;
		}
		convertToDouble(toDouble);
	}
	else {
		std::stringstream convertInt(toConvert);
		if (!(convertInt >> toInt)) {
			std::cerr << "Error: parsing int failed\n";
			return ;
		}
		convertToInt(toInt);
	} 
}

ScalarConverter::~ScalarConverter() {}
