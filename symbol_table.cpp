#include "symbol_table.hpp"

SymbolTable symbol_table;

std::string SymbolTable::storeString(std::string str) {
    strings.push_back(str);
    return ("str" + std::to_string(strings.size()-1));
}

Type* SymbolTable::lookupType(std::string ident) {
    for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
        auto typeLookup = it->types.find(ident);
        if (typeLookup != it->types.end()) {
            return typeLookup->second;
        }
    }
    throw undefinedType();
}

void SymbolTable::declareConst(std::string ident, Expression *expr) {
    scopes.back().constants.emplace(ident, expr);
}

Expression* SymbolTable::lookupLVal(std::string ident) {
    for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
        auto findConstant = it->constants.find(ident);
        if (findConstant != it->constants.end()) {
            return findConstant->second;
        }
    }
    throw undefinedVariable();
}

void SymbolTable::enterScope() {
    scopes.emplace_back();
}

void SymbolTable::exitScope() {
    scopes.pop_back();
}

void SymbolTable::emitStrings() {
    std::cout << ".data" << std::endl;
    for (auto i = 0; i < strings.size(); ++i) {
        std::cout << "str" << std::to_string(i) << ": .asciiz " << strings[i] << std::endl;
    }
}
