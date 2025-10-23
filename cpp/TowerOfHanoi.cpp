#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char from, char to, char aux) {
    if (n <= 0) return; // invalid case
    if (n == 1) {
        cout << "Move disk 1 from rod " << from << " → " << to << '\n';
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    cout << "Move disk " << n << " from rod " << from << " → " << to << '\n';
    towerOfHanoi(n - 1, aux, to, from);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    if (n <= 0) {
        cout << "Number of disks must be positive.\n";
        return 0;
    }
    cout << "\nSteps to solve Tower of Hanoi for " << n << " disks:\n\n";
    towerOfHanoi(n, 'A', 'C', 'B');
    cout << "\nTotal moves required: " << (pow(2, n) - 1) << '\n';
    return 0;
}

