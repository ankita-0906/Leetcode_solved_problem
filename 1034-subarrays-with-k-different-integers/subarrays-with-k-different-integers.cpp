class Solution {
public:
    int solve(vector<int>& arr, int k){
        int n=arr.size();
        unordered_map<int,int>mp;
        int i=0,cnt=0;
        for(int j=0;j<n;j++){
            mp[arr[j]]++;
            while(mp.size()>k){
                mp[arr[i]]--;
                if(mp[arr[i]]==0) mp.erase(arr[i]);
                i++;
            }
            cnt=cnt+j-i+1;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        
        return solve(arr,k)-solve(arr,k-1);
    }
};