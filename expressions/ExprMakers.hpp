#ifndef EXPRMAKERS_HPP
#define EXPRMAKERS_HPP

#include "Expression.hpp"

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

#endif
