class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n =arr.size();
     
       unordered_map<int,int>mpp;
       int rem;
       for(int i=0;i<n;i++){
       rem=arr[i]%k;
       if(rem<0) rem=k+rem;
       mpp[rem]++;
       }
       for(auto& [rem,count]:mpp){
        if(rem==0) {
            if(count & 1) return false;
        }
        else{
            int comp=k-rem;
            if(mpp[comp]!=mpp[rem]) return false;
        }
       }
       return true;
    }  
};