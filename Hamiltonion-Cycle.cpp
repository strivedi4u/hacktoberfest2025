// Travelling salesman Problem

#include<bits/stdc++.h>
using namespace std;

int hamiltonianCycle(vector<vector<int>>& a, int b, int c, vector<vector<int>>& d) {
    int e = a.size();

    if (c == (1 << e) - 1) {
        return a[b][0];
    }
    if (d[b][c] != -1) {
        return d[b][c];
    }
    int f = INT_MAX;

    for (int g = 0; g < e; g++) {
        if ((c & (1 << g)) == 0) {
            int h = a[b][g] + hamiltonianCycle(a, g, c | (1 << g), d);
            f = min(f, h);
        }
    } return d[b][c] = f;
}
int main() {
    int i;
    cout << "number of cities: ";
    cin >> i;

    vector<vector<int>> j(i, vector<int>(i));
    cout << "cost matrix:\n";
    for (int k = 0; k < i; k++) {
        for (int l = 0; l < i; l++) {
            cin >> j[k][l];
        }
    }

    vector<vector<int>> m(i, vector<int>(1 << i, -1));
    int n = hamiltonianCycle(j, 0, 1, m);
    cout << "The minimum cost is: " << n << endl;

    return 0;
}
