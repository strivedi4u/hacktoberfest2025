/*
Program Name   : Infix to Postfix Conversion
Problem Statement:
    Convert a given infix expression (e.g., "A+B*C") into its postfix form
    (e.g., "ABC*+") using a stack.

Example:
    Input : (A+B)*C
    Output: AB+C*

Time Complexity : O(n)    // n = length of expression
Space Complexity: O(n)    // stack size
*/

#include <bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3; // exponent operator
    return 0;
}

// Function to check if character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) { // operand
            postfix += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // pop '('
        } else if (isOperator(c)) {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                if (c == '^' && st.top() == '^') break; // right-associative
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
