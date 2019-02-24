#ifndef ADDEXPR_HPP
#define ADDEXPR_HPP

#include <string>
#include <iostream>

#include "Expression.hpp"
#include "../register.hpp"
#include "../exceptions/TypeMismatch.hpp"

class AddExpr : public Expression {
    private: 
        Expression* a;
        Expression* b;
        Register* reg;
    public:
        AddExpr(Expression* e1, Expression* e2) {
            if (e1->getType() != e2->getType()) {
                throw TypeMismatchException();
            } 
            if (a)
            a = e1;
            b = e2;
            reg = new Register();
        }
        std::string emit() {
            std::cout << ""
        }
};

#endif
