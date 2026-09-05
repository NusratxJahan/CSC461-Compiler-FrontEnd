#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct SymbolEntry {
    int id;
    string name;
    string type;
};

int main() {
    // Variable declaration list in order of appearance
    vector<pair<string, string>> vars = {
        {"a", "int"},
        {"b", "int"},
        {"i", "int"},
        {"xyz", "int"}
    };

    map<string, int> lookup;
    vector<SymbolEntry> symbolTable;

    int idCounter = 1;
    for (const auto& v : vars) {
        lookup[v.first] = idCounter;
        symbolTable.push_back({idCounter, v.first, v.second});
        idCounter++;
    }

    cout << "Functions: func, main" << endl;
    cout << "Variables: ";
    for (size_t i = 0; i < symbolTable.size(); ++i) {
        cout << "<" << symbolTable[i].id << " id>" << (i + 1 < symbolTable.size() ? ", " : "");
    }
    cout << "\n\nLookup table:" << endl;
    cout << "id\tvariable\ttype" << endl;
    for (const auto& entry : symbolTable) {
        cout << entry.id << "\t" << entry.name << "\t\t" << entry.type << endl;
    }

    return 0;
}
