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
    if(i > INT32_MAX || i < INT32_MIN)
        std::cout << "int: " << "impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    // float
    // if(f > MAXFLOAT || f <)
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    // double
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
        float f = std::atof(input.c_str());

        printValue(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f));
        return ;
    }
    else if(input.find('.') != std::string::npos) //double
    {
        double d = std::atof(input.c_str());
        
        printValue(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d);
        return ;
    }
    int i = std::atoi(input.c_str());
        
    printValue(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i));
}
