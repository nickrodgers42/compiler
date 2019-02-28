#ifndef NOTEXPR_HPP
#define NOTEXPR_HPP

#include "Expression.hpp"

class NotExpr : public Expression { 
    private:
        Expression* a;
    public:
        NotExpr(Expression* e1, Type* type) : Expression(type), a(e1) {}
        Register* emit() {
            auto regA = a->emit();
            auto result = new Register();
            std::cout << "not " << result->getRegister() << ", "
                      << regA->getRegister()
                      << std::endl;
            delete regA;
            return result;
        }
};

#endif
