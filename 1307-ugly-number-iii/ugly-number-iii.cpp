class Solution {
public:
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long long ab = lcm(a, b);
        long long bc = lcm(b, c);
        long long ac = lcm(a, c);
        long long abc = lcm(ab, c);   // ✅ safer than lcm(a, bc)

        long long low = 1, high = 2e9;
        long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            long long count = mid/a + mid/b + mid/c
                            - mid/ab - mid/bc - mid/ac
                            + mid/abc;

            if (count < n) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};