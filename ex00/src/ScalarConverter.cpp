#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
};

ScalarConverter::~ScalarConverter()
{
};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return(*this);
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    *this = other;
}

void    checkChar(std::string input)
{
    int charValue;

    charValue = std::atoi(input.c_str());
    if(charValue > 0 && charValue < 127)
    {
        if(std::isprint(charValue))
        {

        }
    }
}

void printNaN(void)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
    if (input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff")
    {
        printNaN();
        return;
    }
    double valueDouble = strtod(input.c_str(), NULL);
    int  valueInt = static_cast<int>(valueDouble);
    float valueFloat = static_cast<float>(valueDouble);
    char valueChar = static_cast<char>(valueDouble);


    // char
    if(valueChar < 32 || valueChar > 126)
        std::cout << BOLD << "char: " << RESET << "Non displayable" << std::endl;
    else
        std::cout << BOLD << "char: " << RESET << "'" << valueChar << "'" << std::endl;

	//int
	if(valueDouble > static_cast<double>(INT32_MAX) || valueDouble < static_cast<double>(INT32_MIN))
		std::cout << BOLD << "int: " << RESET << "impossible" << std::endl;
	else
		std::cout << BOLD << "int: " << RESET << valueInt << std::endl;
	
	//float
	std::cout << BOLD << "float: " << RESET << valueFloat << "f" << std::endl;

	//double
	std::cout << BOLD << "double: " << RESET << valueDouble << std::endl;
	
}
