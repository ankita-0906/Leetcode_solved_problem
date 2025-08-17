class Solution {
public:
    int minInsertions(string s) {
        // int n=s.length();
        // int i=0,cnt=0;
        // stack<char>st;
        // while(i<n){
        //   if(s[i]=='(') st.push(s[i]);
        //   else{
        //     // double ) ----->))
        //     if(i!=n-1 && s[i+1]==')'){
        //         if(st.empty()) cnt++;
        //         else st.pop();
        //         i++;
        //     }
        //     // single )
        //     else{
        //        if(st.empty()) cnt=cnt+2;   //)(
        //          else{
        //             st.pop(); cnt++;
        //         }    
                
        //     }
        //   }
        //   i++;
        // }
        // cnt=cnt+2*st.size();
        // return cnt;

        int insertions = 0; // total insertions we need to make
        int need = 0;       // how many ')' we still need

        for (char c : s) {
            if (c == '(') {
                // Each '(' needs 2 ')'
                need += 2;

                // If need is odd, insert one ')' now to make it even
                if (need % 2) {
                    insertions++; // inserted one ')'
                    need--;       // now need is even
                }
            } else { // c == ')'
                need--;

                if (need < 0) {
                    // We have more ')' than needed
                    insertions++; // insert one '('
                    need = 1;     // one ')' is still needed
                }
            }
        }

        return insertions + need;
    }
};