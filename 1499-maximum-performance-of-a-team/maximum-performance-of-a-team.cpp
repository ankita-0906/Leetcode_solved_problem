class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long mod=1e9+7; //int n=speed.size();
        vector<pair<int,int>>arr;

        for(int i=0;i<n;i++){
            arr.push_back({efficiency[i],speed[i]});
        }
        
        sort(arr.begin(),arr.end(),greater<pair<int,int>>());

        priority_queue<int,vector<int>,greater<int>>pq;
       int mini;
       long long sum=0,total=0;
        for(int i=0;i<n;i++){
            // mini=arr[i].first;
            sum=sum+arr[i].second;
            pq.push(arr[i].second);
            if(pq.size()>k){
                sum=sum-pq.top();
                pq.pop();
            }
           if(pq.size()<=k){
            total=max(total,(sum*(long long)arr[i].first));
           }
        }
        return total%mod;
    }
};