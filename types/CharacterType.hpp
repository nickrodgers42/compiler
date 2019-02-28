#ifndef CHARACTER_TYPE_HPP
#define CHARACTER_TYPE_HPP

#include "Type.hpp"

class CharacterType : public Type {
    private:
        static CharacterType* instance;
        CharacterType() {}
    public:
        int size() override {
            return 4;
        };
        static CharacterType* getInstance() {
            if (instance == 0) {
                instance = new CharacterType;
            }
            return instance;
        }
        CharacterType(CharacterType const&) = delete;
        void operator=(CharacterType const&) = delete;
};

#endif
