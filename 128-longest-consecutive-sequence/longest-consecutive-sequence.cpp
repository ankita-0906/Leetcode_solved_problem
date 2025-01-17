class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int>s(nums.begin(), nums.end());
       int maxi = 0,cnt=1;
       for(auto num:s){
          if(s.find(num-1)==s.end()){
          int curr=num;cnt=1;
          while(s.find(curr+1)!=s.end()){
            cnt++; curr++;
          }
         }    
         maxi=max(maxi,cnt);   
       }
        return maxi;
    }
};