class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        int n1=nums1.size(),n2=nums2.size();
        vector<vector<int>>ans;
        
        for(int i=0;i<min(k,n2);i++) 
        pq.push ({nums1[0]+nums2[i],0,i});

        while(k>0){
            vector<int>pair=pq.top();
            int i=pair[1],j=pair[2];
            ans.push_back({nums1[i],nums2[j]});
            pq.pop();
            k--;

            if(i+1<n1)
            pq.push({nums1[i+1]+nums2[j],i+1,j});
        }
        return ans;
    }
};