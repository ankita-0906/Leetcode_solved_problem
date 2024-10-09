class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        int i=0;
        int n =s.length();
        while(i<n){
         if(s[i]=='(') st.push(s[i]);
         else{
            if(!st.empty() && st.top()=='(')
            st.pop();
            else st.push(s[i]);
         }
         i++;
        }
        return st.size();
    }
};