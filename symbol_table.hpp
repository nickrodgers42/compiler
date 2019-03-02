#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include <string>
#include <vector>
#include <utility>
#include <map>

#include "./types/Type.hpp"
#include "./types/IntegerType.hpp"
#include "./types/CharacterType.hpp"
#include "./types/BooleanType.hpp"
#include "./types/StringType.hpp"

#include "./expressions/Expression.hpp"
#include "./expressions/LiteralExpression.hpp"

#include "./exceptions/customExceptions.hpp"
#include "./nodes/BlockNode.hpp"

struct Scope {
    // std::map<std::string, std::string> strs;
    std::map<std::string, Type*> types;
    std::map<std::string, Expression*> constants;
};

class SymbolTable 
{
    private:
        // What kind of map to put in Symbol table
        std::vector<std::string> strings;
        // int strNum = 0;
        std::vector<Scope> scopes;
    public:
        SymbolTable() {
            Scope predefined = Scope(); 
            predefined.types.emplace("integer", IntegerType::getInstance());
            predefined.types.emplace("INTEGER", IntegerType::getInstance());
            predefined.types.emplace("char", CharacterType::getInstance());
            predefined.types.emplace("CHAR", CharacterType::getInstance());
            predefined.types.emplace("boolean", BooleanType::getInstance());
            predefined.types.emplace("BOOLEAN", BooleanType::getInstance());
            predefined.types.emplace("string", StringType::getInstance());
            predefined.types.emplace("STRING", StringType::getInstance());

            predefined.constants.emplace("true", new LiteralExpression(1, BooleanType::getInstance()));
            predefined.constants.emplace("TRUE", new LiteralExpression(1, BooleanType::getInstance()));
            predefined.constants.emplace("false", new LiteralExpression(0, BooleanType::getInstance()));
            predefined.constants.emplace("FALSE", new LiteralExpression(0, BooleanType::getInstance()));

            scopes.push_back(predefined);
        };
        std::string storeString(std::string str);
        Type* lookupType(std::string ident);
        void declareConst(std::string ident, Expression* expr);
        Expression* lookupLVal(std::string ident);
        void enterScope();
        void exitScope();
        void emitStrings();
};

extern SymbolTable symbol_table;
#endif
