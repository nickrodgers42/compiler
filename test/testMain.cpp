#include <iostream>

#include "registerTest.hpp"

RegisterPool* RegisterPool::instance = 0;

int main ()
{
    std::cout << "=== Executing Unit Tests ===" << std::endl;
    RegisterTest regTester;
    regTester.test();
    std::cout << "=== Testing Complete ===" << std::endl;
    return 0;
}
