class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size(); int j=0;int maxi=INT_MIN;
       
        vector<int>prefix(n+1); prefix[1]=nums[0]; prefix[0]=0;

        for(int i=1;i<n;i++){
          prefix[i+1]=prefix[i]+nums[i];
        }
        for(int i=0;i<k;i++){
            j=i;
            while(j+k<n+1){
                maxi=max(maxi,prefix[j+k]-prefix[j]);
                j=j+k;
            }
        }
        return (double)(maxi)/k;
       
    }
};