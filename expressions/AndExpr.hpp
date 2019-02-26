#ifndef ANDEXPR_HPP
#define ANDEXPR_HPP

#include "Expression.hpp"

class AndExpr : public Expression {
    private:
        Expression* a;
        Expression* b;
        ExprValue* value;
    public:
        AndExpr(Expression* e1, Expression* e2): a(e1), b(e2) {}
        Register* emit() {
            auto regA = a->emit();
            auto regB = b->emit();
            value = new RegisterValue();
            std::cout << "and " << value->getRegister() << ", "
                      << regA->getRegister() << ", "
                      << regB->getRegister() 
                      << std::endl;
            return value->getRegister();
        }
};

#endif
