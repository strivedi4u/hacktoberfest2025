class Solution {
public:
    const int MOD = 1e9 + 7;

    long long helper(long long x, long long n) {
        if (n == 0) return 1;
        long long half = helper((x * x) % MOD, n / 2);
        return (n % 2 == 0) ? half : (half * x) % MOD;
    }

    long long myPow(long long x, long long n) {
        return helper(x, n);
    }

    int countGoodNumbers(long long n) {
        long long odd = myPow(4, n / 2);
        long long even = myPow(5, (n + 1) / 2);
        return (odd * even) % MOD;
    }
};
