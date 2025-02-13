class Solution {
public:
    string clearDigits(string s) {
        stack<int>st; int n=s.length(),i=0;
        while(i<n){
          if(!isdigit(s[i])) st.push(s[i]);
          else {
            if(!st.empty())st.pop();
          }
          i++;
        }
        string ss;
        while(!st.empty()){
            ss.push_back(st.top()); st.pop();
        }
        reverse(ss.begin(),ss.end());
        return ss;
    }
};