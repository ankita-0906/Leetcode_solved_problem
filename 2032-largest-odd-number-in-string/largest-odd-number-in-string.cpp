class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        int maxi=-1;
        for(int i=0;i<n;i++){
            if((num[i]-'0')%2==1) maxi=i;
        }
        string s;
        s=num.substr(0,maxi+1);
        return s;
    }
};