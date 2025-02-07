class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod=1000000000+7;
        int n=arr.size(); int cnt=0;
        for(int i=0;i<n;i++){
            int aim=target-arr[i];
            unordered_map<int,int>mp;
            for(int j=i+1;j<n;j++){
                int rem=aim-arr[j];
                if(mp.find(rem)!=mp.end()) cnt=(cnt+mp[rem])%mod;
              mp[arr[j]]++;
            }
        }
        return cnt;
    }
};