#include "binaryExpressionTree.h"
#include

using namespace std;

binaryExpressionTree::binaryExpressionTree() {}

void binaryExpressionTree::buildExpressionTree(string postfixExpression) {
stack s;

for (char c : postfixExpression) {
if (isdigit(c)) {
// Create a node with the operand
node* newNode = new node;
newNode->data = c - '0';
newNode->left = nullptr;
newNode->right = nullptr;

// Push the operand node onto the stack
s.push(newNode);
} else {
// Create a node with the operator
node* newNode = new node;
newNode->data = c;
newNode->left = nullptr;
newNode->right = nullptr;

// Pop the top two operands from the stack
node* rightOperand = s.top();
s.pop();
node* leftOperand = s.top();
s.pop();

// Connect the operands to the operator node
newNode->left = leftOperand;
newNode->right = rightOperand;

// Push the operator node onto the stack
s.push(newNode);
}
}

// The root of the expression tree is the last node on the stack
root = s.top();
}

int binaryExpressionTree::evaluateExpressionTree() {
return evaluateExpressionTree(root);
}

int binaryExpressionTree::evaluateExpressionTree(node* node) {
if (node == nullptr) {
return 0;
}

if (isdigit(node->data)) {
return node->data - '0';
}

int leftOperandValue = evaluateExpressionTree(node->left);
int rightOperandValue = evaluateExpressionTree(node->right);

switch (node->data) {
case '+':
return leftOperandValue + rightOperandValue;
case '-':
return leftOperandValue - rightOperandValue;
case '*':
return leftOperandValue * rightOperandValue;
case '/':
return leftOperandValue / rightOperandValue;
default:
return 0;
}
}