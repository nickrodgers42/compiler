// #include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

#include "register.hpp"

extern int yyparse();

// RegisterPool *RegisterPool::instance = 0;

int main(int argc, char** argv)
{
    yyparse();  
};
