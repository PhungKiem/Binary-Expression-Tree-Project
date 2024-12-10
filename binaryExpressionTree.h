#ifndef BINARY_EXPRESSION_TREE_H
#define BINARY_EXPRESSION_TREE_H

#include <stack>
#include <string>
#include <sstream>
#include <cctype>
#include "binaryTree.h"

using namespace std;

class binaryExpressionTree : public binaryTreeType<string> {
public:
    binaryExpressionTree() { root = nullptr; }
    ~binaryExpressionTree() { destroyTree(); }

    void buildExpressionTree(const string &postfixExpression);
    double evaluateExpressionTree();

    // Implement abstract methods as placeholders
    bool search(const string &searchItem) const override { return false; }
    void insert(const string &insertItem) override {}
    void deleteNode(const string &deleteItem) override {}

private:
    bool isOperand(const string &token);
    bool isOperator(const string &token);
    double evaluate(nodeType<string> *p);
};

#endif