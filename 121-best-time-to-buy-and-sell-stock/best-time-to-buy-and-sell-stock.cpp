class Solution {
public:
    int maxProfit(vector<int>& arr) {
       
        int n=arr.size(); 
        int mini=INT_MAX, ans=0;

        for(int i=0;i<n;i++){
          if(i==0) continue;
            mini=min(mini,arr[i-1]);
            ans=max(ans,arr[i]-mini);
        }

   
    if(ans<0) return 0;
    return ans;
    }
};