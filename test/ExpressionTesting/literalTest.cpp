#include "literalTest.hpp"

void LiteralTest::test() {
    auto litA = new LiteralExpression(5, IntegerType::getInstance());
    auto litB = new LiteralExpression(9, IntegerType::getInstance());
    {
        if (litA->getValue() != 5) {
            std::cout << "Did not return correct val" << std::endl;
            return;
        }
        if (litA->getType() != litB->getType()) {
            std::cout << "Not same type" << std::endl;
            return;
        }
        if (litA->getType()->size() != 4) {
            std::cout <<  "Wrong size" << std::endl;
            return;
        }
    }

    std::cout << "LiteralTest::test() passed" << std::endl;
    return;
}
