#ifndef CONSTDECLS_HPP
#define CONSTDECLS_HPP

#include <iostream>
#include "Decls.hpp"

class ConstDecls : public Decls {
    private:
        std::vector<std::pair<std::string, Expression*>>* decls;
    public:
        ConstDecls(std::vector<std::pair<std::string, Expression *>>* decls) : decls(decls) {}
        std::vector<std::pair<std::string, Expression*>>* getDecls() override {
            return decls;
        }
};

#endif
