class Solution {
public:
    long long sumAndMultiply(int n) {
        string s="";int sum=0;
        while(n!=0){
            if(n%10!=0){
            s=s+char(n%10+'0');
            sum=sum+n%10;
            }
            n=n/10;
            
        }
        reverse(s.begin(),s.end());
        if (s.empty()) return 0;
        return  1ll *stoi(s) * sum;
    }
};