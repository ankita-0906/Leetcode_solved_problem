class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        stack<char>st;
        for(int i=0;i<n;i++){
            while(k>0 && !st.empty() && st.top()>num[i]){
                st.pop(); k--;
            }
        st.push(num[i]);

        }
        while(k>0 && !st.empty()){
          st.pop();k--;
        } 
        string ans="";
        while(!st.empty()){
          ans.push_back(st.top()); st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i = 0;
        while (i < ans.length() && ans[i] == '0') {
        i++;
        }
       return (i == ans.length()) ? "0" : ans.substr(i);
    }
};