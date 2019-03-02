#ifndef EXPRMAKERS_HPP
#define EXPRMAKERS_HPP

#include <vector>
#include <string>
#include <utility>

#include "../exceptions/customExceptions.hpp"
#include "../register.hpp"
#include "../symbol_table.hpp"
extern SymbolTable symbol_table;

#include "Expression.hpp"
#include "LiteralExpression.hpp"
#include "LiteralValue.hpp"
#include "AddExpr.hpp"
#include "SubExpr.hpp"
#include "MulExpr.hpp"
#include "DivExpr.hpp"
#include "ModExpr.hpp"
#include "EqExpr.hpp"
#include "NeqExpr.hpp"
#include "LeqExpr.hpp"
#include "GeqExpr.hpp"
#include "LtExpr.hpp"
#include "GtExpr.hpp"
#include "OrExpr.hpp"
#include "AndExpr.hpp"
#include "NotExpr.hpp"
#include "UnminusExpr.hpp"
#include "PredExpr.hpp"
#include "SuccExpr.hpp"
#include "StringLiteral.hpp"
#include "LValExpr.hpp"

#include "../types/IntegerType.hpp"
#include "../types/CharacterType.hpp"
#include "../types/BooleanType.hpp"
#include "../types/StringType.hpp"

Expression* getAddExpr(Expression* a, Expression* b);
Expression* getSubExpr(Expression* a, Expression* b);
Expression* getMulExpr(Expression* a, Expression* b);
Expression* getDivExpr(Expression* a, Expression* b);
Expression* getModExpr(Expression* a, Expression* b);
Expression* getEqExpr(Expression* a, Expression* b);
Expression* getNeqExpr(Expression* a, Expression* b);
Expression* getLeqExpr(Expression* a, Expression* b);
Expression* getGeqExpr(Expression* a, Expression* b);
Expression* getLtExpr(Expression* a, Expression* b);
Expression* getGtExpr(Expression* a, Expression* b);
Expression* getOrExpr(Expression* a, Expression* b);
Expression* getAndExpr(Expression* a, Expression* b);
Expression* getNotExpr(Expression* a);
Expression* getUnminusExpr(Expression* a);
Expression* makeCharacterType(Expression* a);
Expression* makeIntegerType(Expression* a);
Expression* predValue(Expression* a);
Expression* succValue(Expression* a);
Expression* getStringLiteral(char* str);
Expression* getCharLiteral(char* chr);
Expression* makeLValueExpr(std::string ident);
Expression* lookupLVal(std::string ident);

void declareConsts(std::vector<std::pair<std::string, Expression*>>* IdentExprList);


#endif
