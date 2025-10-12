class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++) mp[nums[i]]++;
        long long sum=0;
        for(auto it:mp){
            if(it.second%k==0) sum=sum+1ll*it.first*it.second;
        }
        return (int) sum;
    }
};