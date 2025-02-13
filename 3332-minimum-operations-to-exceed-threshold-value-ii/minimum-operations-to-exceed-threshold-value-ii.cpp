class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<long long>ms(nums.begin(),nums.end()); int cnt=0;
        while(ms.size()>1 && *ms.begin()<k){
         long long x=*ms.begin();  ms.erase(ms.begin());
         long long y=*ms.begin(); ms.erase(ms.begin());
         long long ans = x *2+  y;

         cnt++;
         ms.insert(ans);
        }
        return cnt;
    }
};