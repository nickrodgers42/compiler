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
#include <utility>
#include <vector> 


// #include "symbol_table.hpp"

extern int yylex();
extern int line_num;
void yyerror(const char*);


%}

%code requires {
    #include "./expressions/Expression.hpp"
    #include "./expressions/ExprMakers.hpp"
    #include "./statements/Statement.hpp"
    #include "./statements/StopStatement.hpp"
    #include "./nodes/BlockNode.hpp"
    #include "./nodes/BodyNode.hpp"
    #include "./types/Type.hpp"
    #include "./decls/ConstDecls.hpp"
    #include "./decls/Decls.hpp"
    #include "./nodes/ProgramNode.hpp"
}

%union
{
    int val;
    char* id;
    char* string;
    char* chr;
    Expression* expr;
    std::vector<Expression*>* expressionList;
    Statement* statement;
    std::vector<Statement*>* statementSeq;
    BlockNode* blockNode;
    Type* type;
    std::vector<std::pair<std::string, Expression*>>* identExprListPairs;
    ConstDecls* constDecls;
    Node* node;
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
%token OPER_MOD
%token NUMBER
%token CHAR
%token STR

%type <val> NUMBER
%type <id> IDENTIFIER
%type <chr> CHAR
%type <string> STR
%type <expr> Expression
%type <expressionList> ExpressionList
%type <statement> Statement
%type <statementSeq> StatementSeq
%type <statement> StopStatement
%type <expr> LValue
%type <blockNode> Block
%type <type> Type
%type <type> SimpleType
%type <identExprListPairs> IdentExprList
%type <constDecls> OptionalConstDecl
%type <constDecls> ConstantDecl
%type <node> Body

%right UNMINUS 
%left OPER_MUL OPER_DIV OPER_MOD
%left OPER_ADD OPER_SUB
%nonassoc OPER_EQ OPER_NEQ OPER_LT OPER_LEQ OPER_GT OPER_GEQ
%right OPER_NOT
%left OPER_AND
%left OPER_OR

%define parse.error verbose
%%


Program : OptionalConstDecl OptionalTypeDecl OptionalVarDecl ProcOrFuncList Block OPER_DOT { 
    auto p = new ProgramNode($5); 
    p->emit();
    delete p;
  };

OptionalConstDecl : %empty { $$ = nullptr; }
                  | ConstantDecl { $$ = $1; }
                  ;
OptionalTypeDecl : %empty {}
                 | TypeDecl {}
                 ;
OptionalVarDecl : %empty {}
                | VarDecl {}
                ;
ProcOrFuncList : %empty {}
               | ProcOrFuncList ProcDecl {}
               | ProcOrFuncList FuncDecl {}
               ;

ConstantDecl : CONST IdentExprList { $$ = new ConstDecls($2); };

IdentExprList : IdentExprList IDENTIFIER OPER_EQ Expression OPER_SEMICOLON { 
                  auto p = std::make_pair(std::string($2), $4);
                  $1->push_back(p);
                  $$ = $1;
                }
              | IDENTIFIER OPER_EQ Expression OPER_SEMICOLON { 
                  auto p = std::make_pair(std::string($1), $3);
                  auto v = new std::vector<std::pair<std::string, Expression*>>;
                  v->push_back(p);
                  $$ = v;
                }
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

Body : OptionalConstDecl OptionalTypeDecl OptionalVarDecl Block { $$ = new BodyNode($4); };

Block : BEGIN_TOKEN StatementSeq END { $$ = new BlockNode($2); };

TypeDecl : TYPE IDENTIFIER OPER_EQ Type OPER_SEMICOLON IdentTypeList {};

IdentTypeList : %empty {}
              | IDENTIFIER OPER_EQ Type OPER_SEMICOLON IdentTypeList {}
              ;

Type : SimpleType { $$ = $1; }
     | RecordType { $$ = nullptr; }
     | ArrayType { $$ = nullptr; }
     ;

SimpleType : IDENTIFIER { $$ = symbol_table.lookupType($1); } ;
RecordType : RECORD IdentListTypeList END {} ;
ArrayType  : ARRAY OPER_LBRACKET Expression OPER_COLON Expression OPER_RBRACKET OF Type {};
IdentList  : IDENTIFIER {}
           | IDENTIFIER OPER_COMMA IdentList {}
           ;

IdentListTypeList : %empty {}
                  | IdentList OPER_COLON Type OPER_SEMICOLON IdentListTypeList {}
                  ;

VarDecl : VAR IdentList OPER_COLON Type OPER_SEMICOLON IdentListTypeList {};

StatementSeq : StatementSeq OPER_SEMICOLON Statement { $1->push_back($3); $$ = $1; }
             | Statement { auto v = new std::vector<Statement*>; v->push_back($1); $$ = v; }
             ;

Statement : Assignment {}
          | IfStatement {}
          | WhileStatement {}
          | RepeatStatement {}
          | ForStatement {}
          | StopStatement { $$ = $1; }
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
ForStatement : FOR IDENTIFIER OPER_ASSIGN Expression TO Expression DO StatementSeq END {}
             | FOR IDENTIFIER OPER_ASSIGN Expression DOWNTO Expression DO StatementSeq END {}
             ;

StopStatement : STOP { $$ = new StopStatement(); };

ReturnStatement : RETURN {}
                | RETURN Expression {}
                ;
ReadStatement : READ OPER_LPAREN LValueList OPER_RPAREN {};
LValueList : LValue {}
           | LValueList OPER_COMMA LValue {}
           ;
WriteStatement : WRITE OPER_LPAREN ExpressionList OPER_RPAREN {};
ProcedureCall : IDENTIFIER OPER_LPAREN OPER_RPAREN {} 
              | IDENTIFIER OPER_LPAREN ExpressionList OPER_RPAREN {}
              ;

ExpressionList : ExpressionList OPER_COMMA Expression { $1->push_back($3); $$ = $1; }
               | Expression { auto v = new std::vector<Expression*>; v->push_back($1); $$ = v; }
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
           | OPER_NOT Expression { $$ = getNotExpr($2); }
           | OPER_SUB Expression %prec UNMINUS {$$ = getUnminusExpr($2); }
           | OPER_LPAREN Expression OPER_RPAREN { $$ = nullptr; }
           | IDENTIFIER OPER_LPAREN OPER_RPAREN { $$ = nullptr; }
           | IDENTIFIER OPER_LPAREN ExpressionList OPER_RPAREN { $$ = nullptr; }
           | CHR OPER_LPAREN Expression OPER_RPAREN { $$ = makeCharacterType($3); }
           | ORD OPER_LPAREN Expression OPER_RPAREN { $$ = makeIntegerType($3); }
           | PRED OPER_LPAREN Expression OPER_RPAREN { $$ = predValue($3); }
           | SUCC OPER_LPAREN Expression OPER_RPAREN { $$ = succValue($3); }
           | LValue { $$ = $1; }
           | NUMBER { $$ = new LiteralExpression($1, IntegerType::getInstance()); }
           | STR {$$ = getStringLiteral($1); }
           | CHAR { $$ = getCharLiteral($1); }
           ;

LValue : IDENTIFIER { $$ = symbol_table.lookupLVal($1); }
       | LValue OPER_LBRACKET Expression OPER_RBRACKET { $$ == nullptr; }
       | LValue OPER_DOT IDENTIFIER {$$ = nullptr; }
       ;

%%

void yyerror(const char* msg) 
{
    std::cerr << "ERROR on line " << line_num << " " << msg << std::endl;
}

const char* token_name(int t) {
  return yytname[YYTRANSLATE(t)];
}
