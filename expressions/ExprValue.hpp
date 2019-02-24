#ifndef EXPRVALUE_HPP
#define EXPRVALUE_HPP

#include "../register.hpp"

class ExprValue {
    public:
        virtual Register* r = 0;
        virtual bool isLiteral() { return false; }
};

#endif
