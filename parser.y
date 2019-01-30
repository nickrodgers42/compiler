%{
    /***********************
    *
    * CPSL Parser
    *
    ***********************/
%}

%{

/* This section will be placed into the c++ file */
#include <iostream>
#include <map>

#include "symbol_table.hpp"

extern int yylex();
void yyerror(const char*);

%}

%union
{
    float val;
    char* id;
}

%token ARRAY
%token BEGIN
%token CHR
%token CONST
%token DO
%token DOWNTO
%token ELSE
%token ELSEIF
%token END
%token FOR
%token FORWARD
%token FUNCTION
%token IF
%token OF
%token ORD
%token PRED
%token PROCEDURE
%token READ
%token RECORD
%token REF
%token REPEAT
%token RETURN
%token STOP
%token SUCC
%token THEN
%token TO
%token TYPE
%token UNTIL
%token VAR
%token WHILE
%token WRITE
%token IDENTIFIER
%token OPER_ADD
%token OPER_SUB
%token OPER_MUL
%token OPER_DIV
%token OPER_AND
%token OPER_OR
%token OPER_NOT
%token OPER_EQ
%token OPER_NEQ
%token OPER_LT
%token OPER_LEQ
%token OPER_GT
%token OPER_GEQ
%token OPER_DOT
%token OPER_COMMA
%token OPER_COLON
%token OPER_SEMICOLON
%token OPER_LPAREN
%token OPER_RPAREN
%token OPER_LBRACKET
%token OPER_RBRACKET
%token OPER_ASSIGN
%token OPER_PERCENT
%token NUM_OCT
%token NUM_HEX
%token NUM_DEC
%token CHAR
%token ESC_CHAR
%token NEWLINE_CHAR
%token RETURN_CHAR
%token BKSPC_CHAR
%token TAB_CHAR
%token FEED_CHAR
%token STR
%token COMMENT

%type <val> NUMBER
%type <id> IDENTIFIER

%%

StatementList : ;


%%

void yyerror(const char* msg) 
{
    std::cerr << msg << std::endl;
}
