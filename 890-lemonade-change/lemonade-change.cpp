class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size(); 
        int cnt5=0,cnt10=0,cnt20=0, sum=0;
        int r=0;
        while(r<n){
            if(bills[r]==5) cnt5++;
            else if(bills[r]==10){
                cnt10++;
                if(cnt5>=1)cnt5--;
                else return false;
            }
            else {
                if(cnt10>0 && cnt5>0){
                    cnt10--; cnt5--;
                }
                else if(cnt5>=3) cnt5=cnt5-3;
                else return false;
            }
                
        r++;
        }
        return true;
       
    }
};