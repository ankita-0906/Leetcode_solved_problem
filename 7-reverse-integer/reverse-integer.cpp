class Solution {
public:
    int reverse(int x) {
         long long ans=0;
        while(x){
           
            ans=ans*10+(long long)x%10;
            x=x/10;
        }
        if(ans>pow(2,31)|| ans<-pow(2,31) ) 
                ans=0;
        return (int)ans;
    }
};