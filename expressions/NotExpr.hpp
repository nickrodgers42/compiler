#ifndef NOTEXPR_HPP
#define NOTEXPR_HPP

#include "Expression.hpp"

class NotExpr : public Expression { 
    private:
        Expression* a;
        ExprValue* value;
    public:
        NotExpr(Expression* e1): a(e1) {}
        Register* emit() {
            auto regA = a->emit();
            value = new RegisterValue();
            std::cout << "not " << value->getRegister() << ", "
                      << regA->getRegister()
                      << std::endl;
            return value->getRegister();
        }
};

#endif
