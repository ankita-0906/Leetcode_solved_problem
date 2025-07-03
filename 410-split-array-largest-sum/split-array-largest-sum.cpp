class Solution {
public:
int is_possible(vector<int>& nums, int k,int mid){
    int count=1,sum=0;

     for(int i=0;i<nums.size();i++){
       sum=sum+nums[i];
       if(sum>mid){
        count++; sum=nums[i];
       }
         
     }
     
     return count;
}
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int mid,ans;
        while(low<=high){
            mid=low+(high-low)/2;
            if(k>=is_possible(nums,k,mid)) {
                 ans=mid;high=mid-1;
                 }
            else  low=mid+1;     
           
        }
        return ans;
    }
};