class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n=num.length(),cnt=0;
        int i=0;
        while(i<n){
         while(!st.empty() && num[i]<st.top() && k>0){
            st.pop(); k--;
         }
         st.push(num[i]);
         i++;
        }
      while ( k>0) {
        if(st.empty()) return "0";
        st.pop();
        k--;
    }
    string s;
     while(!st.empty()){
        char ele=st.top();
         s.push_back(ele); st.pop();
        }
    reverse(s.begin(),s.end());
    
    int start = 0;
    while (start < s.length() && s[start] == '0') {
        start++;
    }
    s = s.substr(start);

    // Return "0" if the string is empty
    return s.empty() ? "0" : s;
    }
};