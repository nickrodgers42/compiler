#ifndef LITERALVALUE_HPP
#define LITERALVALUE_HPP

/***********
 * This says that it is a value containing a literal number
 *
 ***********/

#include <string>

#include "ExprValue.hpp"
#include "../register.hpp"

class LiteralValue : public ExprValue {
    private:
        Register* reg = new Register();
    public:
        LiteralValue();
        Register* getRegister() {
            return reg;
        }
        bool isLiteral() {
            return true;
        }
};

#endif
