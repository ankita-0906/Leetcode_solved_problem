class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int mini=INT_MAX,sec=INT_MIN,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
           mini=min(mini,nums[i]);
           if(nums[i]>maxi){
            sec=maxi;maxi=nums[i];
           }
           else if(sec<nums[i]) sec=nums[i]; 
        }
        return maxi+sec-mini;
    }
};