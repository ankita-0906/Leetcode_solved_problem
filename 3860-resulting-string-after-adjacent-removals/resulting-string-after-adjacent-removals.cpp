class Solution {
public:
int solve(string &s,int &index){
    for(int i=index;i<s.length()-1;i++){
        if((abs(s[i]-s[i+1])==1) || (abs(s[i]-s[i+1])==25) ) return i;
    }
    return -1;
}
    string resultingString(string s) {
        int i=0;
        while(s.length()>0){
           
           int index=solve(s,i);
           if(index==-1) return s;
           else {
            s=s.erase(index,2);
           }
           i = max(0, index - 1);
        }
        return s;
    }
};