%{
   /**********************
   *
   * CPSL Scanner
   *  
   **********************/
%}
%option noyywrap
%{
   /* Definitions */

   // These will be put verbatum at the beginning of the parser file
   #include <cstdlib>
   #include "parser.hpp"
%}

%{
int line_num = 1;
%}



%%

%{
   /* Rules */
%}

%{
   /*********** Keywords ****************/
%}
array|ARRAY          { return ARRAY; }
begin|BEGIN          { return BEGIN; }
chr|CHR              { return CHR; }
const|CONST          { return CONST; }
do|DO                { return DO; }
downto|DOWNTO        { return DOWNTO; }
else|ELSE            { return ELSE; }
elseif|ELSEIF        { return ELSEIF; }
end|END              { return END; }
for|FOR              { return FOR; }
forward|FORWARD      { return FORWARD; }
function|FUNCTION    { return FUNCTION; }
if|IF                { return IF; }
of|OF                { return OF; }
ord|ORD              { return ORD; }
pred|PRED            { return PRED; }
procedure|PROCEDURE  { return PROCEDURE; }
read|READ            { return READ; }
record|RECORD        { return RECORD; }
ref|REF              { return REF; }
repeat|REPEAT        { return REPEAT; }
return|return        { return RETURN; }
stop|STOP            { return STOP; }
succ|SUCC            { return SUCC; }
then|THEN            { return THEN; }
to|TO                { return TO; }
type|TYPE            { return TYPE; }
until|UNTIL          { return UNTIL; }
var|VAR              { return VAR; }
while|WHILE          { return WHILE; }
write|WRITE          { return WRITE; }

%{
   /* Identifiers */
%}
[A-Za-z][A-Za-z0-9_]* { yyval.id = strdup(yytext); return IDENTIFIER; }

%{
   /* Operators */
%}
"+"   { return OPER_ADD; }
"-"   { return OPER_SUB; }
"*"   { return OPER_MUL; }
"/"   { return OPER_DIV; }
"&"   { return OPER_AND; }
"|"   { return OPER_OR; }
"~"   { return OPER_NOT; }
"="   { return OPER_EQ; }
"<>"  { return OPER_NEQ; }
"<"   { return OPER_LT; }
"<="  { return OPER_LEQ; }
">"   { return OPER_GT; }
">="  { return OPER_GEQ; }
"."   { return OPER_DOT; }
","   { return OPER_COMMA; }
":"   { return OPER_COLON; }
";"   { return OPER_SEMICOLON; }
"("   { return OPER_LPAREN; }
")"   { return OPER_RPAREN; }
"["   { return OPER_LBRACKET; }
"]"   { return OPER_RBRACKET; }
":="  { return OPER_ASSIGN; }
"%"   { return OPER_PERCENT; }

%{
   /* Integer Constants */
%}
0[0-7]+        { return NUM_OCT; }
0x[0-9a-fA-F]+ { return NUM_HEX; }
[1-9]+         { return NUM_DEC; }

%{
   /* Character Constants */
%}
\'.\'           { return CHAR; }
\'\\.[^nrbtf]\' { return ESC_CHAR; }
\'\\n\'         { return NEWLINE_CHAR; }
\'\\r\'         { return RETURN_CHAR; }
\'\\b\'         { return BKSPC_CHAR; }
\'\\t\'         { return TAB_CHAR; }
\'\\f\'         { return FEED_CHAR; }

%{
   /* String constants */
%}
\".*[^\n]\" { return STR; }

%{
  /* Comments */
%}
\$.* { return COMMENT; }

%{
   /* Errors */
%}
 

\n { line_num++; printf("\n"); }

%%

/* User Code */

int main(int argc, char *argv[]) {
  yylex();
}
