#ifndef LVAL_HPP
#define LVAL_HPP

#include "../register.hpp"
#include "Expression.hpp"

class Lval : public Expression {
    private:
        int offSet;
        Register* reg;
    public:
        Lval() {}
        Register* emit() {

        }
};

#endif
