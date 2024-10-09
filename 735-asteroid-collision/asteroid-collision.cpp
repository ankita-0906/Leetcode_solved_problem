class Solution {
public:
    vector<int> asteroidCollision(vector<int>& s) {
        vector<int>ans;
        int n=s.size();
        
        int i=0;
        while(i<n){
          if(ans.size()==0)  {
            ans.push_back(s[i]);
            i++;
          }
          else if(ans.back()*s[i]>0) {
            ans.push_back(s[i]);
            i++;
          }
          else if(ans.back()*s[i] <0 && ans.back()<0){
             ans.push_back(s[i]);
            i++;
          }
          while(i<n && ans.size()!=0 && ans.back()*s[i] <0 && ans.back()>0){

            if(abs(ans.back())==abs(s[i])) {
               ans.pop_back();
               i++;
            }
            else if(abs(ans.back())<abs(s[i])){
              ans.pop_back();
            }
            else{
                i++;
            }
          }
        } 
        return ans;
    }
};