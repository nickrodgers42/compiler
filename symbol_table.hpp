#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include <string>
#include <vector>
#include <map>

// struct Scope {
//     std::map<std::string, std::string> strs;
// };

class SymbolTable 
{
    private:
        // What kind of map to put in Symbol table
        std::vector<std::string> strings;
        // int strNum = 0;
        // std::vector<Scope> scopes;
    public:
      SymbolTable() = default;
      std::string storeString(std::string str);
      // lookup(std::string identifier);
      // void enter_scope();
      // void exit_scope();
};

extern SymbolTable symbol_table;
#endif
