#include "binaryExpressionTree.h"
#include <algorithm>

void binaryExpressionTree::buildExpressionTree(const string &postfixExpression) {
    stack<nodeType<string> *> nodeStack;
    istringstream tokens(postfixExpression);
    string token;

    while (tokens >> token) {
        if (isOperand(token)) {
            nodeType<string> *newNode = new nodeType<string>{token, nullptr, nullptr};
            nodeStack.push(newNode);
        } else if (isOperator(token)) {
            if (nodeStack.size() < 2) {
                cerr << "Error: Invalid postfix expression\n";
                return;
            }

            nodeType<string> *newNode = new nodeType<string>{token, nullptr, nullptr};
            newNode->rLink = nodeStack.top();
            nodeStack.pop();
            newNode->lLink = nodeStack.top();
            nodeStack.pop();

            nodeStack.push(newNode);
        } else {
            cerr << "Error: Unsupported token " << token << "\n";
            return;
        }
    }

    if (nodeStack.size() == 1) {
        root = nodeStack.top();
        nodeStack.pop();
    } else {
        cerr << "Error: Invalid postfix expression\n";
        root = nullptr;
    }
}

double binaryExpressionTree::evaluateExpressionTree() {
    if (!root) {
        cerr << "Error: Expression tree is empty\n";
        return 0;
    }
    return evaluate(root);
}

bool binaryExpressionTree::isOperand(const string &token) {
    return !token.empty() && all_of(token.begin(), token.end(), ::isdigit);
}

bool binaryExpressionTree::isOperator(const string &token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

double binaryExpressionTree::evaluate(nodeType<string> *p) {
    if (!p->lLink && !p->rLink) {
        return stod(p->info);
    }

    double leftValue = evaluate(p->lLink);
    double rightValue = evaluate(p->rLink);

    if (p->info == "+") {
        return leftValue + rightValue;
    } else if (p->info == "-") {
        return leftValue - rightValue;
    } else if (p->info == "*") {
        return leftValue * rightValue;
    } else if (p->info == "/") {
        if (rightValue == 0) {
            cerr << "Error: Division by zero\n";
            return 0;
        }
        return leftValue / rightValue;
    }

    cerr << "Error: Unsupported operator " << p->info << "\n";
    return 0;
}