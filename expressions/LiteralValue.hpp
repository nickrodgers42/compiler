#ifndef LITERALVALUE_HPP
#define LITERALVALUE_HPP

/***********
 * This says that it is a value containing a literal number
 *
 ***********/

#include <string>

class LiteralValue : public ExprValue {
    private:
        Register* reg;
    public:
        LiteralValue() {
            reg = new Register();
        }
        bool isLiteral() override {
            return true;
        }
        Register* getRegister() override {
            return reg;
        }

};

#endif
