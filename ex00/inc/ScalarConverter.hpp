#pragma once

#include "Colors.hpp"

class ScalarConverter
{
	public:
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		
		static void convert(const std::string& input);
	
	private:
		ScalarConverter();
};
