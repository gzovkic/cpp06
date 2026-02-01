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

void ScalarConverter::convert(const std::string& input)
{
    std::cout << input << std::endl;
}
