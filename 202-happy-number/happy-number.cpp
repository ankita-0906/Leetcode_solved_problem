class Solution {
public:
    bool isHappy(int n) {
       unordered_map<int,int>mp; int sum=0;
       while(true){
       while(n>0){
       int ele=n%10;
       sum=sum+ele*ele;
       n=n/10;
       }
       if(sum==1) return true;
       if(mp.find(sum)!=mp.end()) return false;
       mp[sum]++;
      n=sum; sum=0;
    }
    return false;
    }
};