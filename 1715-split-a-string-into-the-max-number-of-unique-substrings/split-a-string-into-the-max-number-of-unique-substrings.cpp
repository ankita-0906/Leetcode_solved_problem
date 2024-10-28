class Solution {
public:
int maxi=0;
void solve(string s,int index,set<string>&mpp,int cnt,int n){
    //base case
     if(index==n){
      maxi=max(cnt,maxi);
      return;
     }
     for(int i=index;i<n;i++){
        string str=s.substr(index,i-index+1);
        if(mpp.find(str)==mpp.end()){
            mpp.insert(str); cnt++;
            solve(s,i+1,mpp,cnt,n);
            mpp.erase(str);
            cnt--;
        }
     }
}
    int maxUniqueSplit(string s) {
        int n=s.length();int cnt=0;
       set<string>mpp;
         solve(s,0,mpp,cnt,n);
       return maxi;
        
       
    }
};