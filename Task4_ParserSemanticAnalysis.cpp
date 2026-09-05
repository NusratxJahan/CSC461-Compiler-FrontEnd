#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

void runSemanticCheck(const vector<string>& codeLines) {
    map<string, string> symbolTable;
    bool hasError = false;

    for (const string& line : codeLines) {
        stringstream ss(line);
        string token1, token2, token3;
        ss >> token1;

        // Handles declarations: int x; float y; string t;
        if (token1 == "int" || token1 == "float" || token1 == "string" || token1 == "char") {
            ss >> token2;
            if (!token2.empty() && token2.back() == ';') {
                token2.pop_back(); // Remove trailing semicolon
            }
            symbolTable[token2] = token1;
        } 
        // Handles assignments: x = y + 1;
        else if (!token1.empty() && symbolTable.count(token1)) {
            string lhs = token1;
            string eq, rhsVar;
            ss >> eq >> rhsVar;

            // Check if RHS contains another variable
            for (const auto& pair : symbolTable) {
                if (rhsVar.find(pair.first) != string::npos) {
                    string rhsType = pair.second;
                    string lhsType = symbolTable[lhs];

                    if (lhsType == "int" && rhsType == "float") {
                        cout << "Type Compatibility Error: Can't assign float to int." << endl;
                        hasError = true;
                        break;
                    } else if (lhsType != rhsType) {
                        cout << "Type Compatibility Error: Type mismatched." << endl;
                        hasError = true;
                        break;
                    }
                }
            }
        }
        if (hasError) break;
    }

    if (!hasError) {
        cout << "Passed" << endl;
    }
}

int main() {
    cout << "--- Test Case A ---" << endl;
    vector<string> testA = {
        "int x;",
        "float y;",
        "x = 5;",
        "y = 2.6;",
        "y = x + 1;"
    };
    runSemanticCheck(testA);

    cout << "\n--- Test Case B ---" << endl;
    vector<string> testB = {
        "int x;",
        "float y;",
        "x = 5;",
        "y = 2.6;",
        "x = y + 1;"
    };
    runSemanticCheck(testB);

    cout << "\n--- Test Case C ---" << endl;
    vector<string> testC = {
        "int x;",
        "string t;",
        "x = 8;",
        "t = x;"
    };
    runSemanticCheck(testC);

    return 0;
}
