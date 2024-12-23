class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n =arr.size();
        sort(arr.begin(),arr.end());
        vector<int>dp(n,1);vector<int>hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if((arr[i]%arr[j]==0 ) && dp[j]+1>dp[i] ){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
        }
        int maxi=-1,last=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>maxi){
                maxi=dp[i];
               last=i;
            }
        }
        vector<int>temp;
        temp.push_back(arr[last]);
        while(last!=hash[last]){
            last=hash[last];
            temp.push_back(arr[last]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};