#ifndef BODYNODE_HPP
#define BODYNODE_HPP

#include "Node.hpp"

#include "BlockNode.hpp"

class BodyNode : public Node {
    private:
        BlockNode* block;
    public:
        BodyNode(ConstDecls* constDecls, BlockNode* block) :  block(block) {
            symbol_table.enterScope();
            if (constDecls != nullptr) {
                declareConsts(constDecls->getDecls());
            }
        };
        void emit() {
            block->emit();
        }
};

#endif
