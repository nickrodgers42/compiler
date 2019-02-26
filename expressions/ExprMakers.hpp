#ifndef EXPRMAKERS_HPP
#define EXPRMAKERS_HPP

#include "../exceptions/TypeMismatch.hpp"
#include "../register.hpp"

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
 

#endif
