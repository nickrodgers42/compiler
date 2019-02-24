#ifndef INTEGER_TYPE_HPP
#define INTEGER_TYPE_HPP

#include "Type.hpp"

class IntegerType : public Type {
    public:
        int size() {
            return 4;
        };
};

#endif
