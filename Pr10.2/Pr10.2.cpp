#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

void processFile(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Unable to open file." << endl;
        return;
    }

    stack<char> parenthesesStack;
    char ch;
    bool error = false;

    while (inputFile.get(ch)) {
        if (ch == '(') {
            parenthesesStack.push(ch);
        }
        else if (ch == ')') {
            if (parenthesesStack.empty()) {
                cerr << "Error: Unmatched closing parenthesis." << endl;
                error = true;
                break;
            }
            else {
                parenthesesStack.pop();
            }
        }
        else {
            if (parenthesesStack.empty()) {
                outputFile.put(ch);
            }
        }
    }

    if (!parenthesesStack.empty()) {
        cerr << "Error: Unmatched opening parenthesis." << endl;
        error = true;
    }

    if (!error) {
        cout << "Processing complete. Result written to " << outputFileName << endl;
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    string inputFileName, outputFileName;

    cout << "Enter the input file name: ";
    cin >> inputFileName;

    cout << "Enter the output file name: ";
    cin >> outputFileName;

    processFile(inputFileName, outputFileName);

    return 0;
}

