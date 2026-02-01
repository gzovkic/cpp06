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

// void convert(const std::string& input)
// {
    
// }

void converter(char *argv)
{
    std::cout << argv << std::endl;
}