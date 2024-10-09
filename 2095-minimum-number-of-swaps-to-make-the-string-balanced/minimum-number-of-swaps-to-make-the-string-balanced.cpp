class Solution {
public:
    int minSwaps(string s) {
        stack<int>st;
        int n=s.length();
        int i=0;
        while(i<n){
            if(s[i]=='[') st.push(s[i]);
            else{
                if(!st.empty() && st.top()=='[') st.pop();
                else st.push(s[i]);
            }
            i++;
        }
        int m=st.size();
        int p=m/2;
        return (p+1)/2;
    }
};