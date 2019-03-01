#include "symbol_table.hpp"

SymbolTable symbol_table;

std::string SymbolTable::storeString(std::string str) {
    strings.push_back(str);
    return ("str" + std::to_string(strings.size()));
}
