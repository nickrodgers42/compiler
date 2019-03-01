#ifndef SUCCEXPER_HPP
#define SUCCEXPER_HPP

#include "Expression.hpp"

class SuccExpr : public Expression { 
    private:
        Expression* a;
    public:
        SuccExpr(Expression* a, Type* t) : Expression(t), a(a) {}
        Register* emit() {
            auto regA = a->emit();
            auto result = new Register();
            std::cout << "addi " << result->getRegister() << ", "
                      << regA->getRegister() << ", "
                      << "1"
                      << std::endl;
            delete regA;
            return result;
        }
};

#endif
