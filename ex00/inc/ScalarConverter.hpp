#pragma once

#include "Colors.hpp"

class ScalarConverter
{
	public:
		static void convert(const std::string& input);
	
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
};
