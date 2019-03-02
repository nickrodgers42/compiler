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
    std::cout << "New constant " << ident << std::endl;
    expr->emit();
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
    std::cout << "New Scope" << std::endl;
    scopes.emplace_back();
}
