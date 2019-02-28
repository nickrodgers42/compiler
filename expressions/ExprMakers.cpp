#include "ExprMakers.hpp"

Expression* getAddExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression(lita->getValue() + litb->getValue(), lita->getType());
    }
    else {
        return new AddExpr(a, b, a->getType());
    }
}

Expression* getSubExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression(lita->getValue() - litb->getValue(), lita->getType());
    }
    else {
        return new SubExpr(a, b, a->getType());
    }
}

Expression* getMulExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression(lita->getValue() * litb->getValue(), lita->getType());
    }
    else {
        return new MulExpr(a, b, a->getType());
    }
}

Expression* getDivExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression((lita->getValue() / litb->getValue()), lita->getType());
    }
    else {
        return new DivExpr(a, b, a->getType());
    }
}

Expression* getModExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression(lita->getValue() % litb->getValue(), lita->getType());
    }
    else {
        return new ModExpr(a, b, a->getType());
    }
}

Expression* getEqExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression(lita->getValue() == litb->getValue(), lita->getType());
    }
    else {
        return new EqExpr(a, b, a->getType());
    }
}

Expression* getNeqExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression(lita->getValue() != litb->getValue(), lita->getType());
    }
    else {
        return new NeqExpr(a, b, a->getType());
    }
}

Expression* getLeqExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression(lita->getValue() <= litb->getValue(), lita->getType());
    }
    else {
        return new LeqExpr(a, b, a->getType());
    }
}

Expression* getGeqExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression(lita->getValue() >= litb->getValue(), lita->getType());
    }
    else {
        return new GeqExpr(a, b, a->getType());
    }
}

Expression* getLtExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression(lita->getValue() < litb->getValue(), lita->getType());
    }
    else {
        return new LtExpr(a, b, a->getType());
    }
}

Expression* getGtExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression(lita->getValue() > litb->getValue(), lita->getType());
    }
    else {
        return new GtExpr(a, b, a->getType());
    }
}

Expression* getOrExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression(lita->getValue() || litb->getValue(), lita->getType());
    }
    else {
        return new OrExpr(a, b, a->getType());
    }
}

Expression* getAndExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression(lita->getValue() && litb->getValue(), lita->getType());
    }
    else {
        return new AndExpr(a, b, a->getType());
    }
}

Expression* getNotExpr(Expression* a) {
    if (a->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        return new LiteralExpression(!lita->getValue(), lita->getType());
    }
    else {
        return new NotExpr(a, a->getType());
    }
}

Expression* getUnminusExpr(Expression* a) {
    if (a->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        return new LiteralExpression(lita->getValue() * -1, lita->getType());
    }
    else {
        return new UnminusExpr(a, a->getType());
    }
}

Expression *makeCharacterType(Expression *a) {
    if (a->getType() != )
}

Expression *makeIntegerType(Expression *a) {

}

Expression *predValue(Expression *a) {

}

Expression *succValue(Expression *a) {

}
