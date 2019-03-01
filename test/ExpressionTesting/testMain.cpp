#include <iostream>
#include <string>

#include "../../register.hpp"
#include "../../types/IntegerType.hpp"

RegisterPool *RegisterPool::instance = 0;
IntegerType* IntegerType::instance = 0;

#include "literalTest.hpp"
#include "AddTest.hpp"
#include "../../expressions/AddExpr.hpp"

int main() {
    auto litTest = LiteralTest();
    litTest.test();
    auto addTest = AddTest();
    addTest.test();

    return 0;
}
