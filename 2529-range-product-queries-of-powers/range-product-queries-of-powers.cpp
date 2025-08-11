class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>powers;
       
        int i=0;
        int mod=1e9 + 7;
        while((1 << i) <= n){
           if(n &(1<<i)) powers.push_back(1<<i);
           i++;
        }
        
    
       vector<int> result;
        long long multiply=1;
        for (auto& q : queries) {
            int product = 1;
            for (int i = q[0]; i <= q[1]; ++i) {
                product = (1LL * product * powers[i]) % mod;
            }
            result.push_back(product);
        }
        return result;
    }
};