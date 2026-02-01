#include "Colors.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate()
{
	int r;
    
    r = std::rand() % 3;
	switch (r) 
    {
		case 0:
			std::cout << BOLD << "Generated A\n" << RESET << std::endl;
			return new A();
        
		case 1:
			std::cout << BOLD << "Generated B\n" << RESET << std::endl;
			return new B();
        
		case 2:
			std::cout << BOLD << "Generated C\n" << RESET << std::endl;
			return new C();
        
		default:
			return nullptr;
	}
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    try 
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    } 
    catch (...) 
    {}

    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    } 
    catch (...) 
    {}

    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    }
    catch (...)
    {}

    std::cout << "Unknown type" << std::endl;
}

int main(void)
{
    std::srand(std::time(0));

    Base* ptr = generate();
        
    identify(ptr);
    identify(*ptr);
        
    delete ptr;
    return 0;
}