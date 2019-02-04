#include "symbol_table.hpp"
#include <stdio.h>
#include <string>

extern int yyparse();
extern int yylex();
extern char* yytext;
extern char* token_name(int t);

int main(int argc, char** argv)
{
    if (argc == 2 && std::string(argv[1]) == "-tokens") {
        int token;
        while ((token = yylex()) != 0) {
            printf("%s\n", token_name(token));
        }
    }
    else if (argc == 2 && std::string(argv[1]) == "-v") {

    } 
    yyparse();
};
