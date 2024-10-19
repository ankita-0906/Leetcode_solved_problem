class Solution {
public:
    char findKthBit(int n, int k) {
        string ans="0";
        string op="0";string s;
        for(int i=0;i<n-1;i++){
             s=ans;op=ans;
            for(int i=0;i<op.length();i++){
                if(op[i]=='1') op[i]='0';
                else op[i]='1';
            }
             reverse(op.begin(),op.end());
             ans=s+"1"+op;
        }
       
        return ans[k-1];
    }
};