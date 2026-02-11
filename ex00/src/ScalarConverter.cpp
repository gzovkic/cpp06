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

    if (d > INT_MAX || d < INT_MIN || std::isnan(d))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
    //char
    if(input.length() == 1 && !std::isdigit(input[0]))
    {
        char c = input[0];

        printValue(c,static_cast<int>(c),static_cast<float>(c),static_cast<double>(c));
        return ;
    }
    else if(input.find('f') != std::string::npos && input.length() > 1) //float
    {
        float f = std::strtof(input.c_str(), NULL);

        printValue(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f));
        return ;
    }
    else if(input.find('.') != std::string::npos) //double
    {
        double d = std::strtod(input.c_str(), NULL);

        printValue(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d);
        return ;
    }
    char *end;
    long test = std::strtol(input.c_str(), &end, 10);
    if(*end != '\0')
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (test <= INT_MAX && test >= INT_MIN) 
    {
        int i = static_cast<int>(test);
        printValue(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i));
    }
    else 
    {
        double d = std::strtod(input.c_str(), NULL);
        printValue(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d);
    }
}
