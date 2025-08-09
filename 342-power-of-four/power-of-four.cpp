class Solution {
public:
    bool isPowerOfFour(int n) {
        // 0x55555555=01010101....0101
        // 4-- 100
       return (n > 0) && ((n & (n - 1)) == 0) && ((n & 0x55555555) != 0);
    }
};