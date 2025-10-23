#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &s) {
    int i = 0, j = (int)s.size() - 1;
    while (i < j) {
        // move i forward to next alphanumeric
        while (i < j && !isalnum(static_cast<unsigned char>(s[i]))) ++i;
        // move j backward to previous alphanumeric
        while (i < j && !isalnum(static_cast<unsigned char>(s[j]))) --j;

        char a = tolower(static_cast<unsigned char>(s[i]));
        char b = tolower(static_cast<unsigned char>(s[j]));
        if (a != b) return false;

        ++i; --j;
    }
    return true;
}

int main() {
    vector<string> tests = {
        "A man, a plan, a canal: Panama",
        "race a car",
        " ",
        "0P"   // example from some platforms
    };

    for (auto &t : tests) {
        cout << '"' << t << "\" -> " << (isPalindrome(t) ? "true" : "false") << '\n';
    }

    return 0;
}
