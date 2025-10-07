class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        unordered_map<int,int>mp;
        vector<int> dry;
         vector<int>res;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
           if(rains[i]==0) dry.push_back(i);

           else{
               if(mp.find(rains[i])==mp.end()) {
                ans[i]=-1;
                mp[rains[i]]=i;
                }
                else {
                    bool flag=false;
                for(int j=0;j<dry.size();j++){
                    if(i>dry[j] && mp[rains[i]]<dry[j]) {
                        ans[dry[j]]=rains[i];
                        ans[i]=-1;
                        dry.erase(dry.begin()+j);
                         flag =true;
                        break;
                    }
                    
                   
                }
                if(flag==false) return res;
                mp[rains[i]]=i;
            }
           }
            
        }
       
        for(int i=0;i<dry.size();i++) ans[dry[i]]=1;
        return ans;
        
    }
};