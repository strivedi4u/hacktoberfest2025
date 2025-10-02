#include <bits/stdc++.h>
using namespace std;

int sum_difference(int n, int m) {
    long long sum_is_not_divisble = 0, sum_is_divisble = 0;
    for (int i = 1; i <= n; i++) {
        if (i % m == 0)
            sum_is_divisble += i;
        else
            sum_is_not_divisble += i;
    }
    return sum_is_not_divisble - sum_is_divisble;
}

int main() {
    int n, m;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;
    int result = sum_difference(n, m);
    cout << "Divisible and Non-divisible Sums Difference is : " << result << endl;
    return 0;
}
