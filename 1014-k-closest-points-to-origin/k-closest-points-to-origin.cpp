class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        vector<vector<int>>ans;
        
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<arr.size();i++){
            int x=arr[i][0],y=arr[i][1];
            int dist=x*x+y*y;
            pq.push({dist,{x,y}});
            if(pq.size()>k)pq.pop();
        }
        while(pq.size()>0){
            auto[dist,coord]=pq.top();
            int x=coord.first;
            int y=coord.second;
            pq.pop();
            ans.push_back({x,y});
        }
       
        return ans;
    }
};