class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        // int i=0,j=1,cnt=1;
        // while(j<n){
        //  if(nums[i]==nums[j]) cnt++;
        //  else if(nums[i]!=nums[j]){
        //     i=j; cnt=1;
        //  }
        //  j++;
        // }
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int i=0;
        
        for(auto it:mp){
            for(int j=0;j<min(2,it.second);j++){
                nums[i]=it.first;
                i++;
            }
        }
        return i;
    }
};