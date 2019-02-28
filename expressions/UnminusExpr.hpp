#ifndef UNMINUSEXPR_HPP
#define UNMINUSEXPR_HPP

#include "Expression.hpp"

class UnminusExpr : public Expression { 
    private:
        Expression* a;
    public:
        UnminusExpr(Expression* e1): a(e1) {}
        Register* emit() {
            auto regA = a->emit();
            auto result = new Register();
            std::cout << "neg " << result->getRegister() << ", "
                      << regA->getRegister()
                      << std::endl;
            return result;
        }
};

#endif
