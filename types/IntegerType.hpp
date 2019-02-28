#ifndef INTEGERTYPE_HPP
#define INTEGERTYPE_HPP

#include "Type.hpp" 

class IntegerType : public Type {
    private:
        IntegerType() {}
    public:
        int size() override {
            return 4;
        };
        static IntegerType* getInstance() {
            static IntegerType* instance;
            return instance;
        }
        IntegerType(IntegerType const&) = delete;
        void operator=(IntegerType const&) = delete;
};

#endif
