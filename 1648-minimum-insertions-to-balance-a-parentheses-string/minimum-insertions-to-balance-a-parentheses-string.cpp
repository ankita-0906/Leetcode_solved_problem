class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        int i=0,cnt=0;
        stack<char>st;
        while(i<n){
          if(s[i]=='(') st.push(s[i]);
          else{
            // double ) ----->))
            if(i!=n-1 && s[i+1]==')'){
                if(st.empty()) cnt++;
                else st.pop();
                i++;
            }
            // single )
            else{
               if(st.empty()) cnt=cnt+2;   //)(
                 else{
                    st.pop(); cnt++;
                }    
                
            }
          }
          i++;
        }
        cnt=cnt+2*st.size();
        return cnt;
    }
};