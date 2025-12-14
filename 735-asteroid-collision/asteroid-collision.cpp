class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n=arr.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(st.empty()) st.push(arr[i]);
            else if(st.top()*arr[i]>0) st.push(arr[i]);
            else if(st.top()<0)st.push(arr[i]);
            else if(abs(st.top())>abs(arr[i])) continue;
            else if ( abs(st.top())==abs(arr[i])) st.pop();
            else {
                while(!st.empty() && st.top()*arr[i]<0 && abs(st.top())<abs(arr[i])) st.pop();
                i=i-1;
            }
        }

        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};