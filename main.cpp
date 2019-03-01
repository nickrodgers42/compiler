// #include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

#include "register.hpp"

extern int yyparse();
#include "symbol_table.hpp"
extern SymbolTable symbol_table;

RegisterPool *RegisterPool::instance = 0;

#include "./types/BooleanType.hpp"
#include "./types/CharacterType.hpp"
#include "./types/IntegerType.hpp"
#include "./types/StringType.hpp"

IntegerType *IntegerType::instance = 0;
CharacterType *CharacterType::instance = 0;
BooleanType *BooleanType::instance = 0;
StringType *StringType::instance = 0;

int main(int argc, char** argv)
{
    yyparse();  
};
