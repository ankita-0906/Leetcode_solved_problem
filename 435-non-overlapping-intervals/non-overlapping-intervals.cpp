class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),[](const vector<int>&a, const vector<int>&b){
            return a[1]<b[1];
        });
        int n=arr.size();
        vector<vector<int>>ans;int cnt=0;
        int end=arr[0][1];
        for(int i=1;i<n;i++){

           if(arr[i][0]<end) cnt++;
          else end=arr[i][1];
        }
        return cnt;
    }
};