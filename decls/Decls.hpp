#ifndef DECLS_HPP
#define DECLS_HPP

#include <string>
#include <vector>
#include <utility>

#include "../expressions/Expression.hpp"
#include "../symbol_table.hpp"
extern SymbolTable symbol_table;

class Decls {
    virtual std::vector<std::pair<std::string, Expression*>>* getDecls() = 0;
};

#endif
