class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size(),m=potions.size();
        vector<int>pair(n);
        sort(potions.begin(),potions.end());
        
        for(int i=0;i<n;i++){
            int low=0,heigh=m-1,cnt=0; 
           while(low<=heigh){
            int mid=(low+heigh)/2;
            if(1ll*spells[i]*potions[mid]>=success){
                cnt=m-mid;
                heigh=mid-1;
            }
            else low=mid+1;
           } 
           pair[i]=cnt;
        }
        return pair;
    }
};