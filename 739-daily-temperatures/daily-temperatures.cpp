class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        stack<pair<int,int>>st; int n=arr.size();
        vector<int>ans(n,0);
        for(int i=0;i<arr.size();i++){
           
           
            while(!st.empty() && arr[i]>st.top().first){
                ans[st.top().second]=i-st.top().second;
                st.pop();
            }
            st.push({arr[i],i});
        }
        return ans;
    }
};