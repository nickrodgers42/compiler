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
#include "./expressions/ExprMakers.hpp"
#include "./types/StopStatement.hpp"

// #include "symbol_table.hpp"

extern int yylex();
extern int line_num;
void yyerror(const char*);
%}

%union
{
    int val;
    char* id;
    char* string;
    char chr;
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
%token OPER_LBRACKET`
%token OPER_RBRACKET
%token OPER_ASSIGN
%token OPER_MOD
%token NUMBER
%token CHAR
%token STR

%type <val> NUMBER
%type <id> IDENTIFIER
%type <chr> CHAR
%type <string> STR

%right UNMINUS 
%left OPER_MUL OPER_DIV OPER_MOD
%left OPER_ADD OPER_SUB
%nonassoc OPER_EQ OPER_NEQ OPER_LT OPER_LEQ OPER_GT OPER_GEQ
%right OPER_NOT
%left OPER_AND
%left OPER_OR

%define parse.error verbose
%%


Program : OptionalConstDecl OptionalTypeDecl OptionalVarDecl ProcOrFuncList Block OPER_DOT {};

OptionalConstDecl : %empty {}
                  | ConstantDecl {}
                  ;
OptionalTypeDecl : %empty {}
                 | TypeDecl {}
                 ;
OptionalVarDecl : %empty {}
                | VarDecl {}
                ;
ProcOrFuncList : %empty {}
               | ProcDecl ProcOrFuncList {}
               | FuncDecl ProcOrFuncList {}
               ;

ConstantDecl : CONST IDENTIFIER OPER_EQ Expression OPER_SEMICOLON IdentExprList {};

IdentExprList : %empty {}
              | IDENTIFIER OPER_EQ Expression OPER_SEMICOLON IdentExprList {}
              ;

ProcDecl : PROCEDURE IDENTIFIER OPER_LPAREN FormalParams OPER_RPAREN OPER_SEMICOLON FORWARD OPER_SEMICOLON {}
         | PROCEDURE IDENTIFIER OPER_LPAREN FormalParams OPER_RPAREN OPER_SEMICOLON Body OPER_SEMICOLON {}
         ;

FuncDecl : FUNCTION IDENTIFIER OPER_LPAREN FormalParams OPER_RPAREN OPER_COLON Type OPER_SEMICOLON FORWARD OPER_SEMICOLON {}
         | FUNCTION IDENTIFIER OPER_LPAREN FormalParams OPER_RPAREN OPER_COLON Type OPER_SEMICOLON Body OPER_SEMICOLON {}
         ;

FormalParams : %empty {}
             | VarOrRef IdentList OPER_COLON Type {}
             | VarOrRef IdentList OPER_COLON Type OPER_SEMICOLON FormalParams {}
             ;

VarOrRef : %empty {}
         | VAR {}
         | REF {}
         ;

Body : OptionalConstDecl OptionalTypeDecl OptionalVarDecl Block {};

Block : BEGIN_TOKEN StatementSeq END {};

TypeDecl : TYPE IDENTIFIER OPER_EQ Type OPER_SEMICOLON IdentTypeList {};

IdentTypeList : %empty {}
              | IDENTIFIER OPER_EQ Type OPER_SEMICOLON IdentTypeList {}
              ;

Type : SimpleType {}
     | RecordType {}
     | ArrayType {}
     ;

SimpleType : IDENTIFIER {} ;
RecordType : RECORD IdentListTypeList END {} ;
ArrayType  : ARRAY OPER_LBRACKET Expression OPER_COLON Expression OPER_RBRACKET OF Type {};
IdentList  : IDENTIFIER {}
           | IDENTIFIER OPER_COMMA IdentList {}
           ;

IdentListTypeList : %empty {}
                  | IdentList OPER_COLON Type OPER_SEMICOLON IdentListTypeList {}
                  ;

VarDecl : VAR IdentList OPER_COLON Type OPER_SEMICOLON IdentListTypeList {};

StatementSeq : Statement {}
             | Statement OPER_SEMICOLON StatementSeq {}
             ;

Statement : Assignment {}
          | IfStatement {}
          | WhileStatement {}
          | RepeatStatement {}
          | ForStatement {}
          | StopStatement {$$ = $1;}
          | ReturnStatement {}
          | ReadStatement {}
          | WriteStatement {}
          | ProcedureCall {}
          | NullStatement {}
          ;

Assignment : LValue OPER_ASSIGN Expression {};
IfStatement : IF Expression THEN StatementSeq ElseIfStatement ElseStatement END {};
ElseIfStatement : %empty {}
                | ELSEIF Expression THEN StatementSeq ElseIfStatement {}
                ;
ElseStatement : %empty {}
              | ELSE StatementSeq {}
              ;
WhileStatement : WHILE Expression DO StatementSeq END {};
RepeatStatement : REPEAT StatementSeq UNTIL Expression {};
ForStatement : FOR IDENTIFIER OPER_ASSIGN Expression ToOrDownto Expression DO StatementSeq END {};
ToOrDownto : TO {}
           | DOWNTO {} 
           ;

StopStatement : STOP {
        $$ = new StopStatement();
    };

ReturnStatement : RETURN OptionalExpression {};
OptionalExpression : %empty {}
                   | Expression {};
ReadStatement : READ OPER_LPAREN LValueList OPER_RPAREN {};
LValueList : LValue {}
           | LValue OPER_COMMA LValueList {}
           ;
WriteStatement : WRITE OPER_LPAREN ExpressionList OPER_RPAREN {};
ProcedureCall : IDENTIFIER OPER_LPAREN OptionalExpressionList OPER_RPAREN {} ;
OptionalExpressionList : %empty {}
                       | Expression {}
                       | Expression OPER_COMMA ExpressionList {}
                       ;
ExpressionList : Expression OPER_COMMA ExpressionList {}
               | Expression {}
               ;
NullStatement : %empty {};

Expression : Expression OPER_OR Expression  { $$ = getOrExpr($1, $3); }
           | Expression OPER_AND Expression { $$ = getAndExpr($1, $3); }
           | Expression OPER_EQ Expression  { $$ = getEqExpr($1, $3); }
           | Expression OPER_NEQ Expression { $$ = getNeqExpr($1, $3); }
           | Expression OPER_LEQ Expression { $$ = getLeqExpr($1, $3); }
           | Expression OPER_GEQ Expression { $$ = getGeqExpr($1, $3); }
           | Expression OPER_LT Expression  { $$ = getLtExpr($1, $3); }
           | Expression OPER_GT Expression  { $$ = getGtExpr($1, $3); }
           | Expression OPER_ADD Expression { $$ = getAddExpr($1, $3); }
           | Expression OPER_SUB Expression { $$ = getSubExpr($1, $3); }
           | Expression OPER_MUL Expression { $$ = getMulExpr($1, $3); }
           | Expression OPER_DIV Expression { $$ = getDivExpr($1, $3); }
           | Expression OPER_MOD Expression { $$ = getModExpr($1, $3); }
           | OPER_NOT Expression { $$ = new NotExpr($2); }
           | OPER_SUB Expression %prec UNMINUS {$$ = new UnminusExpr($2); }
           | OPER_LPAREN Expression OPER_RPAREN { $$ = new Expression($2); }
           | IDENTIFIER OPER_LPAREN OptionalExpressionList OPER_RPAREN { $$ = nullptr; }
           | CHR OPER_LPAREN Expression OPER_RPAREN { $$ = new ChrExpr($3); }
           | ORD OPER_LPAREN Expression OPER_RPAREN { $$ = new OrdExpr($3); }
           | PRED OPER_LPAREN Expression OPER_RPAREN { $$ = new PredExpr($3); }
           | SUCC OPER_LPAREN Expression OPER_RPAREN { $$ = new SuccExpr($3); }
           | LValue {}
           | NUMBER {}
           | STR {}
           | CHAR {}
           ;

LValue : IDENTIFIER {}
       | LValue OPER_LBRACKET Expression OPER_RBRACKET {}
       | LVALUE OPER_DOT IDENTIFIER {};

%%

void yyerror(const char* msg) 
{
    std::cerr << "ERROR on line " << line_num << " " << msg << std::endl;
}

const char* token_name(int t) {
  return yytname[YYTRANSLATE(t)];
}
