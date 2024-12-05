class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.size();
        int i=0,j=0;
        while(i<n || j<n){
            while(start[i]=='_') i++;
            while(target[j]=='_') j++;
            //count
            if(i==n || j==n) return(i==n && j==n);

            if(start[i]!=target[j] ||
              (start[i]=='L' && i<j) ||
              (start[i]=='R' && i>j))
             return false;
             else{
                i++;j++;
             }
        }
        return true;
    }
};