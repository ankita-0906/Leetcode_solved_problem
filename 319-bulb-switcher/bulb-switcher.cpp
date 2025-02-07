class Solution {
public:
    int bulbSwitch(int n) {
        int cnt=0;
       for(int i=1;i<=n;i++){
        int x=sqrt(i);
        cnt=cnt+(x*x==i);
       }
       return cnt;
    }
};