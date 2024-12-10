#include <iostream>
#include <fstream>
#include <string>
#include "binaryExpressionTree.h"

using namespace std;

int main() {
    binaryExpressionTree expressionTree;

    ifstream inputFile("RpnData.txt");
    ofstream outputFile("Results.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file" << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output file" << endl;
        return 1;
    }

    cout << "Results from the file:\n"; // Print header

    string line;
    while (getline(inputFile, line)) {
        expressionTree.destroyTree(); // Clear the tree before building a new one
        expressionTree.buildExpressionTree(line);
        double result = expressionTree.evaluateExpressionTree();
        cout << "Expression: " << line << " = " << result << endl; // Print to console
        outputFile << line << " = " << result << endl; // Write to file
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
