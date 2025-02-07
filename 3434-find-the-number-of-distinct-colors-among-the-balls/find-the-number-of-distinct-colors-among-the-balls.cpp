class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& arr) {
        int n=arr.size(),cnt=0;
        unordered_map<int,int>color,mp;
        vector<int>res(n);
        for(int i=0;i<n;i++){

          if(mp.find(arr[i][0])!=mp.end()){
          color[mp[arr[i][0]]]--;
          if(color[mp[arr[i][0]]]==0) color.erase(mp[arr[i][0]]);
          }
           color[arr[i][1]]++;

          mp[arr[i][0]]=arr[i][1];
          
          
          res[i]=color.size();
       
        }
        return res;
        
    }
};