class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        priority_queue<long long,vector<long long>,greater<long long>>q
        (nums.begin(),nums.end());

        int i=0,cnt=0,n=nums.size();

        while(i<n){
         
          if(q.top()>=k) return cnt;
          if(q.size()>=2 && q.top()<k){
               long long x=q.top(); q.pop();
               long long y=q.top(); q.pop();
               long long ans=x*2+y; q.push(ans);
               cnt++;
          }
          i++;
        }
        return cnt;
    }
};