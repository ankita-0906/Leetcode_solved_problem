class Solution {
public:
    bool strongPasswordCheckerII(string s) {
        if(s.length()<8) return false;
        int upper=0,lower=0,special=0,digit=0;
        if (s[0] >= 'A' && s[0] <= 'Z') upper++;
        else if(s[0] >= 'a' && s[0] <= 'z') lower++;
        else if (s[0] >= '0' && s[0] <= '9') digit++;
        else  special++;
        for(int i=1;i<s.length();i++){
          if(s[i]==s[i-1]) return false;
          if (s[i] >= 'A' && s[i] <= 'Z') upper++;
           else if(s[i] >= 'a' && s[i] <= 'z') lower++;
           else if (s[i] >= '0' && s[i] <= '9') digit++;
         else special++;
        }
        if(upper!=0 && lower!=0 && special!=0 && digit!=0) return true;
        return false;
    }
};