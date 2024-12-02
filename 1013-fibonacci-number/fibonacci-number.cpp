class Solution {
public:
    int fib(int n) {
        int prev1=1,prev2=0;
        int sum=0;
        if(n==0) return 0;
        if(n==1) return 1;
        for(int i=2;i<=n;i++){
          sum=prev1+prev2;
          prev2=prev1;
          prev1=sum;
        }
        return sum;
    }
};