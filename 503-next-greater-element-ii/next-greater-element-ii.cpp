class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        for(int i=n-1;i>=0;i--) st.push(nums[i]);

        vector<int>temp(n);
        for(int i=n-1;i>=0;i--){
           while(!st.empty() && nums[i]>=st.top())
           st.pop();
           if(st.empty()) temp[i]=-1;
          else if(nums[i]<st.top())
           temp[i]=st.top();

          st.push(nums[i]);
        }
        return temp;
    }
};