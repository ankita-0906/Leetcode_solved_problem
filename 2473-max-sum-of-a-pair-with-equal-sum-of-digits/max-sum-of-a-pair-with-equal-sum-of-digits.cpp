class Solution {
public:
     int calculate(int num){
        int sum=0;
        while(num){
          sum=sum+num%10;
          num=num/10;  
        }
        return sum;
     }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int>mp; // first value=sum of digit and 2nd value=nums[i]
        int n=nums.size();
        int i=0,maxi=-1;
        while(i<n){
            int num=calculate(nums[i]); // using we are finding key actually
            auto it=mp.find(num);
            if(it!=mp.end()){
                maxi=max(maxi,nums[i]+it->second);
                it->second=max(it->second,nums[i]);
            }
            else mp[num]=nums[i];
            i++;
        }
        return maxi;
    }
};