class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int>ans;
        long long k=1;
        while(n!=0){
            
        if(n%10!=0)ans.push_back(n%10 * k);
         n=n/10;
         k=k*10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};