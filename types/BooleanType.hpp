#ifndef BOOLEANTYPE_HPP
#define BOOLEANTYPE_HPP

#include "Type.hpp"

class BooleanType : public Type {
    private:
        static BooleanType* instance;
        BooleanType() {}
    public:
        int size() override {
            return 4;
        }
        static BooleanType* getInstance() {
            if (instance == 0) {
                instance = new BooleanType;
            }
            return instance;
        }
        BooleanType(BooleanType const&) = delete;
        void operator=(BooleanType const&) = delete;
};

#endif
