class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1=str1.length(),n2=str2.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(str1[i]==str2[j]){
                   if(i-1>=0 && j-1>=0) dp[i][j]=1+dp[i-1][j-1];
                    else dp[i][j]=1;
                }
                else{
                   int left=0,up=0;
                   if(j-1>=0)  left=dp[i][j-1];
                   if(i-1>=0)  up=dp[i-1][j];
                   dp[i][j]=max(left,up);
                }
            }
        }
        int len=n1+n2-dp[n1-1][n2-1];
        string s="";
        for(int i=0;i<len;i++) s=s+'#';
        int i=n1-1,j=n2-1,index=len-1;
        while(i>=0 && j>=0){
            if(str1[i]==str2[j]){
               s[index]=str1[i]; i--;j--;index--;
            }
            else{
                if(i-1>=0 && j-1>=0){
                   if(dp[i-1][j]>dp[i][j-1]) {
                      s[index]=str1[i]; index--; i--;
                    }
                    else{
                       s[index]=str2[j]; index--; j--;
                    }
                }
                else if(i-1>=0){
                   s[index]=str1[i]; index--; i--;
                }
                else if(j-1>=0){
                     s[index]=str2[j]; index--; j--;
                }
                else {
                    s[index]=str1[i]; index--;s[index]=str2[j];i--;j--;index--;
                }
                
            }
        }
        while(j>=0) {
            s[index]=str2[j]; j--;index--;
        }
        while(i>=0) {
            s[index]=str1[i]; i--;index--;
        }
        return s;

    }
};