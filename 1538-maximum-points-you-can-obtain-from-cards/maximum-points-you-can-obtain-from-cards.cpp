class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int sum=0;
        for(int i=0;i<k;i++){
            sum=sum+arr[i];
        }
        int n=arr.size();
        int left=k-1,right=n-1,maxi=sum;
         
        while(k>0 && left<right){
        sum=sum-arr[left]+arr[right];
        maxi=max(maxi,sum);
        k--;left--;right--;
        }
        return maxi;
    }
};