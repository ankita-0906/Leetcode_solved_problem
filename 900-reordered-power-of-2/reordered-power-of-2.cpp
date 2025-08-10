class Solution {
public:
    string getcount(int n){
      string s=to_string(n);
      sort(s.begin(),s.end());
      return s;
    }
    bool reorderedPowerOf2(int n) {
       string target=getcount(n);
       
       for(int i=0;i<31;i++){
        if(target==getcount(1<<i)) return true;

       }
       return false;
    }
};