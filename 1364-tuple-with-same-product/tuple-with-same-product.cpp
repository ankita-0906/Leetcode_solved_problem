class Solution {
public:
int combination(int n){
    int res=1;
    for(int i=0;i<2;i++){
     res=res*(n-i);
     res=res/(i+1);
    }
    return res;
}
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size(); unordered_map<int,int>mp;
        int cnt=0;
        for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
            mp[nums[i]*nums[j]]++;
          }
        }
        for(auto it: mp){
            if(it.second!=1){
             cnt=cnt+8*combination(it.second);
            }
        }
        return cnt;
    }
};