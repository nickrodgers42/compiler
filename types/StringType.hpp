#ifndef STRINGTYPE_HPP
#define STRINGTYPE_HPP

#include "Type.hpp"

class StringType : public Type {
    private:
        static StringType* instance;
        StringType() {}
    public:
        int size() {
            return 4;
        }
        static StringType* getInstance() {
             if (instance == 0) {
                instance = new StringType;
            }
            return instance;
        }
        StringType(StringType const&) = delete;
        void operator=(StringType const&) = delete;
};

#endif
