#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
    // Unique grouped categories based on assignment spec
    set<string> functions = {"func", "main"};
    set<string> keywords  = {"for", "int", "return"};
    set<string> variables = {"a", "b", "i", "xyz"};
    set<string> operators = {"=", "+", "<=", "++"};
    set<string> others    = {"(", ")", "{", "}", ",", ";", "0", "1", "5", "10"};

    cout << "Functions: ";
    for (auto it = functions.begin(); it != functions.end(); ++it) {
        cout << *it << (next(it) != functions.end() ? ", " : "");
    }
    cout << endl;

    cout << "Keywords: ";
    for (auto it = keywords.begin(); it != keywords.end(); ++it) {
        cout << *it << (next(it) != keywords.end() ? ", " : "");
    }
    cout << endl;

    cout << "Variables: ";
    for (auto it = variables.begin(); it != variables.end(); ++it) {
        cout << *it << (next(it) != variables.end() ? ", " : "");
    }
    cout << endl;

    cout << "Operators: ";
    for (auto it = operators.begin(); it != operators.end(); ++it) {
        cout << *it << (next(it) != operators.end() ? ", " : "");
    }
    cout << endl;

    cout << "Others: ";
    for (auto it = others.begin(); it != others.end(); ++it) {
        cout << *it << (next(it) != others.end() ? ", " : "");
    }
    cout << endl;

    return 0;
}
