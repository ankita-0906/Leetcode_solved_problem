class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>arr=nums;vector<int>ans;
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mp;
       
        mp[arr[0]]=0;
        for(int i=1;i<nums.size();i++){
         if(arr[i]==arr[i-1]) continue;
         else mp[arr[i]]=i;
        }
        for(int i=0;i<nums.size();i++)
        ans.push_back(mp[nums[i]]);

        return ans;
    }
};