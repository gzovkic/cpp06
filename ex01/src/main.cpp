#include "Serializer.hpp"

int main(void)
{
	Data myData;
    myData.id = 42;
    myData.name = "Test";

    // Store original address
    Data* originalPtr = &myData;

    // Run the cycle
    uintptr_t raw = Serializer::serialize(originalPtr);
    Data* resultPtr = Serializer::deserialize(raw);

    // Print results
    std::cout << "Original:    " << originalPtr << std::endl;
    std::cout << "Serialized:  " << raw << std::endl;
    std::cout << "Deserialized: " << resultPtr << std::endl;

    // Final check
    if (originalPtr == resultPtr)
        std::cout << GREEN << "Success: Addresses match!" << RESET << std::endl;
    else
        std::cout << RED << "Error: Addresses differ!" << RESET << std::endl;

	return (0);
}