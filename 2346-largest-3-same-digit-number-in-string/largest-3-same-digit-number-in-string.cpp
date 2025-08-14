class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        string s="";
        int i=0,j=1;char ch=num[i]; int maxi=-1;
        while(j<n){
          if(num[j]!=ch){
           if(j-i>=3){
            maxi=max(maxi,ch-'0');
           }
            i=j;ch=num[i];
            
          }
          j++;
        }
        if(j-i>=3){
          maxi=max(maxi,ch-'0');
        }
        if(maxi==-1) return "";
        string res=to_string(maxi);
       s=res+res+res;
        return s;
    }
};