// #include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

#include "register.hpp"

extern int yyparse();
extern int yylex();
extern char* yytext;
extern char* token_name(int t);

RegisterPool *RegisterPool::instance = 0;

int main(int argc, char** argv)
{
    yyparse();  
};
