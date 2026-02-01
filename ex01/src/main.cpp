#include "Serializer.hpp"

int main(void)
{
	Data myData;
    myData.id = 42;
    myData.name = "Test";

	Data myData2;
	myData2.id = 2;
    myData2.name = "3";
    // Store original address
    Data* originalPtr = &myData;
	Data* failPtr = &myData2;
    // Run the cycle
    uintptr_t raw = Serializer::serialize(originalPtr);
    Data* resultPtr = Serializer::deserialize(raw);

    // Print results
    std::cout << "Original:    	" << originalPtr << std::endl;
	std::cout << "Fail:    	" << failPtr << std::endl;
    std::cout << "Serialized:  	" << raw << std::endl;
    std::cout << "Deserialized: 	" << resultPtr << std::endl;

    // Final check
    if (originalPtr == resultPtr)
        std::cout << GREEN << "Success: Addresses match!" << RESET << std::endl;
    else
        std::cout << RED << "Error: Addresses differ!" << RESET << std::endl;
	
	if (failPtr == resultPtr)
        std::cout << GREEN << "Success: Addresses match!" << RESET << std::endl;
    else
        std::cout << RED << "Error: Addresses differ!" << RESET << std::endl;

	return (0);
}