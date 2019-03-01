#ifndef STOPSTATEMENT_HPP
#define STOPSTATEMENT_HPP

#include "Statement.hpp"

class StopStatement : public Statement {
    public:
        void emit() {
            std::cout << "li $v0 10\n"
                      << "syscall"
                      << std::endl;
        }
};

#endif
