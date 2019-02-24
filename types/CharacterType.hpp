#ifndef CHARACTER_TYPE_HPP
#define CHARACTER_TYPE_HPP

#include "Type.hpp"

class CharacterType : public Type {
    public:
        int size() {
            return 4;
        };
};

#endif
