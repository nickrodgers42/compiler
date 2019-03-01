#ifndef PREDEXPR_HPP
#define PREDEXPR_HPP

#include "Expression.hpp"

class PredExpr : public Expression { 
    private:
        Expression* a;
    public:
        PredExpr(Expression* a, Type* t) : Expression(t), a(a) {}
        Register* emit() {
            auto regA = a->emit();
            auto result = new Register();
            std::cout << "addi " << result->getRegister() << ", "
                      << regA->getRegister() << ", "
                      << " -1"
                      << std::endl;
            delete regA;
            return result;
        } 
};

#endif
