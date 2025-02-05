class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size(),cnt=0;
        int i=0,j=0;
        
        // while(j<n){
        //  if(nums[j]!=val) j++;
        //  else break;
        // } i=j;
       
        while(j<n){
        if(nums[i]==val && nums[j]!=val)
        { 
            swap(nums[i],nums[j]);
            i++;
        }
         else if(nums[i]!=val) i++;
         j++;
        }
        return i;
    }
};