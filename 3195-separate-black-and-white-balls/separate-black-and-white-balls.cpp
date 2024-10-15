class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.length();
        int i=n-1;
        int cnt=0;long long sum=0;
      
        while(i>=0){
        if(s[i]=='0'){
            cnt++;
        }
        else{
            sum=sum+cnt;
        }
        i--;
        }
        return sum;
    }
};