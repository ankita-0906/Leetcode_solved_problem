class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        
        unordered_map<int, long long> total;
        for (int p : power) total[p] += p;  // sum of same damage spells

        vector<int> vals;
        for (auto &it : total) vals.push_back(it.first);
        sort(vals.begin(), vals.end());

        int n = vals.size();
        vector<long long> dp(n, 0);

        dp[0] = total[vals[0]];

        for (int i = 1; i < n; i++) {
            long long take = total[vals[i]];
            int j = i - 1;
            while (j >= 0 && vals[i] - vals[j] <= 2) j--;
            if (j >= 0) take += dp[j];
            long long skip = dp[i-1];
            dp[i] = max(skip, take);
        }

        return dp[n-1];



    }
};