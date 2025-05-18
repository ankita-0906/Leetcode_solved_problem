class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int>mpp;
        int l=0,r=0,len=0,maxfreq=0,change;
        int n=s.length();
        while(r<n){
         mpp[s[r]]++;
         maxfreq=max(maxfreq,mpp[s[r]]);
         change=(r-l+1)-maxfreq;
           if(change>k){  
           
                mpp[s[l]]--;l++;
                
            }  
         
         if(change<=k)
         len=max(len,r-l+1);
         r++;
        }
        return len;
    }
};