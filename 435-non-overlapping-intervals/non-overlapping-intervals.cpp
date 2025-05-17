class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),[](const vector<int>&a, const vector<int>&b){
            return a[1]<b[1];
        });
        int n=arr.size();
        vector<vector<int>>ans;int cnt=0;
        for(int i=0;i<n;i++){
          if(i==0) ans.push_back(arr[i]);

          else if(arr[i][0]<ans.back()[1]) cnt++;
          else ans.push_back(arr[i]);
        }
        return cnt;
    }
};