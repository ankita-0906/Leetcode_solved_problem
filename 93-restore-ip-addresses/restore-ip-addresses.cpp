class Solution {
public:
  bool ispossible(int index,int i,string s){
    if (i - index + 1 > 3) return false;
    string temp=s.substr(index,i-index+1);
    if(temp[0]=='0' && temp.length()>1) return false;
   int num = 0;
    for (int j = index; j <= i; j++) {
        num = num * 10 + (s[j] - '0');
    }
    if(num>255 ) return false;
    return true;
  }
  void rec(int index, int n,vector<string>&ans,string op,string s,int parts){
    if(parts ==4 && index==n){
        ans.push_back(op);
        return;
    }
    if(parts!=4 && index==n) return ;
    for(int i=index;i<n;i++){
        if(ispossible( index, i,s)){
           string temp=s.substr(index,i-index+1);
           if(op.empty()){
            rec(i+1,n,ans,temp,s,parts+1);
           }
           else{
              rec(i+1,n,ans,op+"."+temp,s,parts+1);
           }
        }
    }

  }
    vector<string> restoreIpAddresses(string s) {
        int n=s.length();
        vector<string>ans; string op;
        rec(0,n,ans,op,s,0);
        return ans;
    }
};