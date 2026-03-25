class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        // max heap for the summation of maximum elements 
        // sorting in decending order for maximum element
       int total=0;
       vector<pair<int,int>>arr;
       int n=nums1.size();
       for(int i=0;i<n;i++){
        arr.push_back({nums2[i],nums1[i]});
       }
     sort(arr.begin(), arr.end(), greater<pair<int,int>>());
        priority_queue<int, vector<int>, greater<int>> minHeap;

      
        long long sum = 0;
        long long ans = 0;

        for(int i = 0; i < n; i++){

            sum += arr[i].second;
            minHeap.push(arr[i].second);

            // keep only k elements
            if(minHeap.size() > k){
                sum -= minHeap.top();
                minHeap.pop();
            }

            // when we have exactly k elements
            if(minHeap.size() == k){
                ans = max(ans, sum * (long long)arr[i].first);
            }
        }
        return ans;
    }
};