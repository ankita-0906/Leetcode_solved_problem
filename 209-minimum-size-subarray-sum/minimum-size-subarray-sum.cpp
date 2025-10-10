class Solution {
public:
// bool ispossible(vector<int>&arr,int n,int mid,int target){
//     for(int i=0;i<mid;i++){
//         int j=i;
//       while(j+mid<n){
//        if(arr[j+mid]-arr[j]>=target) return true;
//        j=j+mid;
//       }
//     }
//     return false;
// }
    int minSubArrayLen(int target, vector<int>& nums) {
    //     int n=nums.size(); int sum=0;
    //     vector<int>arr; arr.push_back(0);
    //     for(int i=0;i<n;i++) {
    //         sum=sum+nums[i];
    //        arr.push_back(sum);
    //     }
        
    //    int low=0,high=n,ans=0;
    //    while(low<=high){
    //     int mid=(low+high)/2;
    //     if(ispossible(arr,n+1,mid,target)){
    //         ans=mid;high=mid-1;
    //     }
    //     else low=mid+1;
    //    }
    //    if(ans==0){
    //     if(arr.back()>=target) ans=n;
    //    }
    //    return ans;

    int n=nums.size(),sum=0,mini=INT_MAX,j=0;
    for(int i=0;i<n;i++){
        sum=sum+nums[i];
        if(sum>=target){
          mini=min(mini,i-j+1);
          }
        while(sum>=target) {
            sum=sum-nums[j];j++;
            if(sum>=target){
          mini=min(mini,i-j+1);
          }
        }  
    }
    if(mini==INT_MAX) return 0;
    return mini;
    }
};