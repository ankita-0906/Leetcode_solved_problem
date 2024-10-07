class Solution {
public:
    int minLength(string s) {
        int n=s.length();
        int i=0;
        stack<char>st;
        while(i<n){
        if(s[i]=='B' && st.empty()==false && st.top()=='A')
        st.pop();
        else if(s[i]=='D' &&  st.empty()==false && st.top()=='C')
        st.pop();
        else st.push(s[i]);
        i++;
        }
        return st.size();
    }
};