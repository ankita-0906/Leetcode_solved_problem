class Solution {
public:
    string removeStars(string s) {
        string st="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
                if(!st.empty()) st.pop_back();
            }
            else st.push_back(s[i]);
        }
        return st;
    }
};