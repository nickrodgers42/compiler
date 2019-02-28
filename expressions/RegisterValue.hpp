#ifndef REGISTERVALUE_HPP
#define REGISTERVALUE_HPP

/************
 * This says that the value of the expression
 * that this belongs to is contained in a register
 * ***********/

#include "../register.hpp"
#include "ExprValue.hpp"

class RegisterValue : public ExprValue {
    private:
        Register* reg;
    public:
        RegisterValue() {
            reg = new Register();
        }
        Register* getRegister() override {
            return reg;
        }
};

#endif
