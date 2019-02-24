#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include "../types/Type.hpp"
#include "../register.hpp"

class Expression {
    private:
        Type* type;
    public:
        int value;
        Type* getType() {
            return type;
        }
};

#endif
