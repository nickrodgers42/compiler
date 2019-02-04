#include "symbol_table.hpp"
#include <stdio.h>
#include <string>

extern int yylex();
extern char* yytext;
extern char* token_name(int t);

int main(int argc, char** argv)
{
    if (argc == 2) {
        if (std::string(argv[1]) == "-tokens") {
            int token;
            while ((token = yylex()) != 0) {
                // printf("Token: %d (%s)\n", token, yytext);
                printf("%s\n", token_name(token));
            }
        }
    }
    else {
        int token;
        while((token = yylex()) != 0) {
            continue;
        }
    }
    // printf("%d", yylex());
    return 0;
};
