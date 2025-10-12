class Solution {
public:
    bool isBalanced(vector<int>& freq) {
    int target = 0;
    for(int f : freq) {
        if(f != 0) {
            if(target == 0) target = f;
            else if(f != target) return false;
        }
    }
    return true;
}
    int longestBalanced(string s) {
        int n = s.size();
    int maxLen = 0;

    for(int i = 0; i < n; i++) {
        vector<int> freq(26, 0);
        for(int j = i; j < n; j++) {
            freq[s[j] - 'a']++;
            if(isBalanced(freq)) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;

    }
};