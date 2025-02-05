class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        
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