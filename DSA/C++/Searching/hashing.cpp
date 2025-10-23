#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> marks;
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    // Taking user input
    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cout << "Enter name and marks: ";
        cin >> name >> score;
        marks[name] = score;  // Insertion in hash table
    }

    cout << "\nAll student marks:\n";
    for (auto &entry : marks) {
        cout << entry.first << " -> " << entry.second << endl;
    }

    // Searching for a student
    string query;
    cout << "\nEnter name to search: ";
    cin >> query;

    if (marks.find(query) != marks.end()) {
        cout << query << " found with marks " << marks[query] << endl;
    } else {
        cout << query << " not found!" << endl;
    }

    return 0;
}
