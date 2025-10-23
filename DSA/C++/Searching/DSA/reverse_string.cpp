// Problem: Reverse a string without using built-in reverse functions
// Author: Hansika Arora (GitHub: Hansika1225)

#include <iostream>
#include <string>
using namespace std;

// Function to reverse a string
string reverseString(const string& str) {
    string reversed = "";
    for(int i = str.length() - 1; i >= 0; i--) {
        reversed += str[i];
    }
    return reversed;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    string result = reverseString(input);
    cout << "Reversed string: " << result << endl;

    return 0;
}
