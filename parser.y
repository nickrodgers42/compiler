%token-table
%{
/***********************
*
* CPSL Parser
*
***********************/

/* This section will be placed into the c++ file */
#include <iostream>
#include <map>

// #include "symbol_table.hpp"

extern int yylex();
void yyerror(const char*);

%}

%union
{
    float val;
    char* id;
}

%token ARRAY
%token BEGIN_TOKEN
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

%token INT_IDENT;
%token CHAR_IDENT;
%token BOOLEAN_IDENT;
%token STRING_IDENT;
%token TRUE_IDENT;
%token FALSE_IDENT;

%type <val> NUM_OCT
%type <val> NUM_HEX
%type <val> NUM_DEC
%type <id> IDENTIFIER

%%


Program : OptionalConstDecl OptionalTypeDecl OptionalVarDecl ProcFuncDecl Block .

OptionalConstDecl : 
                  | ConstantDecl
                  ;
OptionalTypeDecl : 
                 | TypeDecl
                 ;
OptionalVarDecl :
                | VarDecl
                ;

ProcFuncDecl : ProcFuncDecl
             | FunctionDecl
             | ProcDecl 
             ;

ProcDecl : PROCEDURE IDENTIFIER OPER_LPAREN FormalParams OPER_RPAREN OPER_SEMICOLON FORWARD OPER_SEMICOLON
         | PROCEDURE IDENTIFIER OPER_LPAREN FormalParams OPER_RPAREN OPER_SEMICOLON Body OPER_SEMICOLON

FunctionDecl : FUNCTION IDENTIFIER OPER_LPAREN FormalParams OPER_RPAREN OPER_COLON Type OPER_SEMICOLON FORWARD OPER_SEMICOLON
             | FUNCTION IDENTIFIER OPER_LPAREN FormalParams OPER_RPAREN OPER_COLON Type Body OPER_SEMICOLON

FormalParams : 
             | VarOrRef IdentList OPER_COLON Type 
             | VarOrRef IdentList OPER_COLON Type OPER_SEMICOLON FormalParams

VarOrRef :
         | VAR
         | REF 
         ;

Body : OptionalConstDecl OptionalTypeDecl OptionalVarDecl Block 

Block : BEGIN_TOKEN StatementSeq END

ConstantDecl : const IdentStatementList

IdentStatementList : IdentStatementList IdentStatement
                   | IdentStatement
                   ;

IdentStatement : IDENTIFIER OPER_EQ Expression OPER_SEMICOLON

TypeDecl : type TypeIdentList;

TypeIdentList : TypeIdentList TypeIdentStatement
              | TypeIdentStatement
              ;
TypeIdentStatement : IDENTIFIER OPER_EQ TYPE ;
TYPE : SimpleType
     | RecordType
     | ArrayType
     ;
SimpleType : IDENTIFIER ;
RecordType : record IdentTypeList END
IdentTypeList : 
              | IdentList : Type OPER_SEMICOLON
              | IdentTypeList
              ;
ArrayType : ARRAY OPER_LBRACKET Expression : Expression OPER_RBRACKET OF Type
IdentList : IDENTIFIER
          | IDENTIFIER, IdentList

VarDecl : VAR IdentList : Type OPER_SEMICOLON IdentTypeList

StatementSeq : Statement
             | Statement OPER_SEMICOLON StatementSeq

Statement : Assignment
          | IfStatement
          | WhileStatement
          | RepeatStatement
          | ForStatement
          | StopStatement
          | ReturnStatement
          | ReadStatement
          | WriteStatement
          | ProcedureCall
          | NullStatement
          ;

Assignment : LValue OPER_ASSIGN Expression ;

IfStatement : if Expression then StatementSeq ElseIfStatement ElseStatement END ;

ElseIfStatement : 
                | ELSEIF Expression then StatementSeq ElseIfStatement
                ;

ElseStatement : 
              | ELSE StatementSeq
              ;

WhileStatement : WHILE Expression DO StatementSeq END ;

RepeatStatement : REPEAT StatementSeq UNTIL Expression ;

ForStatement : FOR IDENTIFIER OPER_ASSIGN Expression ToOrDownto Expression DO StatementSeq END ;

ToOrDownto : TO | DOWNTO ;

StopStatement : STOP ;

ReturnStatement : RETURN OptionalExpression ;

OptionalExpression : 
                   | Expression
                   ;

ReadStatement : READ OPER_LPAREN LValueList OPER_RPAREN ;

LValueList : LValue
           | LValue OPER_COMMA LValueList
           ;

WriteStatement : WRITE OPER_LPAREN ExpressionList OPER_RPAREN ;

ExpressionList : Expression 
               | Expression OPER_COMMA ExpressionList
               ;

ProcedureCall : IDENTIFIER OPER_LPAREN OptionalExpressionList OPER_RPAREN ;

OptionalExpressionList : 
                       | ExpressionList
                       ;

NullStatement : %empty ;

Expression : Expression OPER_OR Expression
           | Expression OPER_AND Expression
           | Expression OPER_EQ Expression
           | Expression OPER_NEQ Expresssion
           | Expression OPER_LEQ Expresssion
           | Expression OPER_GEQ Expresssion
           | Expression OPER_LT Expresssion
           | Expression OPER_GT Expresssion
           | Expression OPER_ADD Expresssion
           | Expression OPER_SUB Expresssion
           | Expression OPER_MUL Expresssion
           | Expression OPER_DIV Expresssion
           | Expression OPER_PERCENT Expresssion           
           | OPER_NOT Expression
           | OPER_SUB Expression
           | OPER_LPAREN Expression OPER_RPAREN
//TODO           | IDENTIFIER OPER_LPAREN Expression OptionalExpressionList OPER_RPAREN
           | CHR OPER_LPAREN Expression OPER_RPAREN
           | ORD OPER_LPAREN Expression OPER_RPAREN
           | PRED OPER_LPAREN Expression OPER_RPAREN
           | SUCC OPER_LPAREN Expression OPER_RPAREN
           | LValue
           

%%

void yyerror(const char* msg) 
{
    std::cerr << msg << std::endl;
}

const char* token_name(int t) {
  return yytname[YYTRANSLATE(t)];
}
