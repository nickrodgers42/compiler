#ifndef LITERALEXPRESSION_HPP
#define LITERALEXPRESSION_HPP

#include "Expression.hpp"

class LiteralExpression : public Expression {
    private:
        int value;
    public:
        LiteralExpression() {}
        LiteralExpression(int a, Type* t) : Expression(t), value(a) {}
        Register* emit() override {
            Register* result = new Register();
            std::cout << "addi " << result->getRegister() << ", " 
                      << "$zero" << ", " 
                      << value
                      << std::endl;
            return result;
        }
        int getValue() {
            return value;
        }
        bool isConst() override {
            return true;
        }
};

#endif
