#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		converter(argv[1]);
		return(0);
	}
	std::cerr	<< RED << "Wrong amount of arguments!\n"
				<< "example ./convert <number>"
				<< RESET << std::endl;
	return (-1);
}