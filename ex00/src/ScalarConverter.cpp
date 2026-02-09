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

void    printValue(char c, int i, float f, double d)
{
    //char
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    // int 
    std::cout << "int: " << i << std::endl;

    // float
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    // double
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
    if(input.length() == 1 && !std::isdigit(input[0]))
    {
            char c = input[0];

            printValue(c,static_cast<int>(c),static_cast<float>(c),static_cast<double>(c));
            return ;
    }
	
}
