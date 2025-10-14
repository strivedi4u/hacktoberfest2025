#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Upper half of the pattern
    for (int i = 1; i <= n; i++) {
        for (int j = n - i; j >= 0; j--) {
            cout << "*";
        }

        for (int k = 2 * (i - 1); k > 0; k--) {
            cout << " ";
        }

        for (int l = n - i; l >= 0; l--) {
            cout << "*";
        }
        cout << endl;
    }

    // Lower half of the pattern
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }

        for (int k = 2 * (n - i - 1); k > 0; k--) {
            cout << " ";
        }

        for (int m = 0; m <= i; m++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
