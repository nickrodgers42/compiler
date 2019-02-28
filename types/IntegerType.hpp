#ifndef INTEGERTYPE_HPP
#define INTEGERTYPE_HPP

#include "Type.hpp" 

class IntegerType : public Type {
    private:
        static IntegerType* instance;
        IntegerType() {}
    public:
        int size() override {
            return 4;
        };
        static IntegerType* getInstance() {
            if (instance == 0) {
                instance = new IntegerType;
            }
            return instance;
        }
        IntegerType(IntegerType const&) = delete;
        void operator=(IntegerType const&) = delete;
};

#endif
