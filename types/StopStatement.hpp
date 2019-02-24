#ifndef STOP_STATEMENT_HPP
#define STOP_STATEMENT_HPP

#include <iostream>
#include <string>
#include "type.hpp"

class StopStatement : public Type {
    public:
        void emit() {
            std::cout << "li $v0 10\n"
                      << "syscall"
                      << std::endl;
        }
};

#endif
