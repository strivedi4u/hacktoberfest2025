#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mapping = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        stack<char> open_brackets;
        for (char c : s) {
            if (mapping.count(c)) {
                if (open_brackets.empty()) {
                    return false;
                }
                char top_element = open_brackets.top();
                open_brackets.pop();
                if (top_element != mapping[c]) {
                    return false;
                }
            } else {
                open_brackets.push(c);
            }
        }
        return open_brackets.empty();
    }
};