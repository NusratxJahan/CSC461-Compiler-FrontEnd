#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// Function to separate source code into individual lexemes
vector<string> separateLexemes(const string& code) {
    vector<string> lexemes;
    string current = "";
    int n = code.length();

    for (int i = 0; i < n; i++) {
        char ch = code[i];

        // Skip whitespace characters
        if (isspace(ch)) {
            if (!current.empty()) {
                lexemes.push_back(current);
                current = "";
            }
            continue;
        }

        // Check multi-character operators like <=, ++
        if (i + 1 < n) {
            string op2 = code.substr(i, 2);
            if (op2 == "<=" || op2 == "++" || op2 == "==" || op2 == "!=") {
                if (!current.empty()) {
                    lexemes.push_back(current);
                    current = "";
                }
                lexemes.push_back(op2);
                i++; // Skip next character
                continue;
            }
        }

        // Single-character delimiters / operators
        if (string("(){};,=+*<>-").find(ch) != string::npos) {
            if (!current.empty()) {
                lexemes.push_back(current);
                current = "";
            }
            lexemes.push_back(string(1, ch));
        } 
        else {
            // Build identifiers / keywords / numbers
            current += ch;
        }
    }

    if (!current.empty()) {
        lexemes.push_back(current);
    }

    return lexemes;
}

int main() {
    string sourceCode = 
        "int func(int xyz)\n"
        "{\n"
        "    xyz = xyz + 1;\n"
        "    return xyz;\n"
        "}\n"
        "int main()\n"
        "{\n"
        "    int a, b = 5;\n"
        "    for(int i = 0; i <= 10; i++)\n"
        "    {\n"
        "        b = b + func(i);\n"
        "    }\n"
        "    return 0;\n"
        "}";

    vector<string> lexemes = separateLexemes(sourceCode);

    cout << "--- Task 1: Lexeme Separation Output ---" << endl;
    for (const string& lexeme : lexemes) {
        cout << lexeme << endl;
    }

    return 0;
}
