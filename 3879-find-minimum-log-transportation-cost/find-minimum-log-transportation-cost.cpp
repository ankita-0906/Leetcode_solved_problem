class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        int track1=k, track2=k,track3=k;
        if(n<=k && m<=k) return 0;
        long long cost=0,l1=n,l2=0;
        for(int l1=n;l1>=n/2;l1--){
          if(l1<=k) {
            l2=n-l1;
            cost=cost+(long long)l1*l2;
            break;
          }
          
        }
        track1=k-l1; track2=k-l2;l2=0;

        for(int l1=m;l1>=m/2;l1--){
          if(l1<=k && track2>=(m-l1)) {
            l2=m-l1;
            cost=cost+(long long)l1*l2;
            break;
          }
        }
        return cost;  
          
    }
};