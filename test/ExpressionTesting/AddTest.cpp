#include "AddTest.hpp"

void AddTest::test() {
    auto litA = new LiteralExpression(5, IntegerType::getInstance());
    auto litB = new LiteralExpression(9, IntegerType::getInstance());
    {
        std::cout << litA->getValue() << std::endl;
        if (!litA->isConst())
        {
            std::cout << "A is not const" << std::endl;
        }
        auto addA = new AddExpr(litA, litB, litA->getType());
        // addA->emit();

        if (addA->getType() == litB->getType())
        {
            std::cout << "same" << std::endl;
        }
        auto litc = new LiteralExpression(7, IntegerType::getInstance());
        auto addB = new AddExpr(addA, litc, IntegerType::getInstance());
        addB->emit();
    }
}
