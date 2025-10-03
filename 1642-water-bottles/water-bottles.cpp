class Solution {
public:
    int numWaterBottles(int n, int m) {
        int sum=0;
        int full=n,empty=0;
        while(empty>=m || full>0){
            sum=sum+full; 
            empty=empty+full;
            full=empty/m; 
            empty=empty%m; 
        }
        return sum;
    }
};