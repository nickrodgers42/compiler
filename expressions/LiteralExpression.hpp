#ifndef LITERALEXPRESSION_HPP
#define LITERALEXPRESSION_HPP

#include "Expression.hpp"

class LiteralExpression : public Expression {
    private:
        int value;
        ExprValue* exprVal = new LiteralValue();
    public:
        LiteralExpression(int a) : value(a) {}
        Register* emit() override {
            // store the value in a register and return that register
            std::cout << "addi " << exprVal->getRegister() << " $zero " << value << std::endl;
            return exprVal->getRegister();
        }
        int getValue() {
            return value;
        }
};

#endif
