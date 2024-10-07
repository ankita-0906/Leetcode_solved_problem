class Solution {
public:
    int solve(int n){
        int count=9,cnt=9;
       for(int i=0;i<n-1;i++){
        count=count*cnt;
        cnt--;
       } 
       return count;
    }
     
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        if(n==1) return 10;
        int cnt=10;
        for(int i=2;i<=n;i++){
         cnt=cnt+solve(i);
        }
        return cnt;
    }
};