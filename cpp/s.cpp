#include <iostream>
using namespace std;

// Global variable to count steps
int stepCount = 0;

// Recursive function to solve Tower of Hanoi
void solveTowerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n <= 0) return;

    if (n == 1) {
        cout << "Step " << ++stepCount << ": Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    solveTowerOfHanoi(n - 1, source, auxiliary, destination);

    cout << "Step " << ++stepCount << ": Move disk " << n << " from " << source << " to " << destination << endl;

    solveTowerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int numDisks;

    cout << "Enter the number of disks: ";
    cin >> numDisks;

    if (numDisks <= 0) {
        cout << "Please enter a positive number of disks." << endl;
        return 1;
    }

    cout << "\nSequence of moves to solve Tower of Hanoi:\n";
    solveTowerOfHanoi(numDisks, 'A', 'C', 'B');

    cout << "\nTotal steps taken: " << stepCount << endl;

    return 0;
}
