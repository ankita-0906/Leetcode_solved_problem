class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>pre(n),suf(n);
        pre[0]=-1;
        stack<int>st;
        st.push(0); int i=0;
        while(i<n){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();

            if(st.empty()) pre[i]=-1;
            else pre[i]=st.top();
            
            st.push(i);
            i++;

        }

        while(!st.empty()) st.pop();

        st.push(n-1); suf[n-1]=n;
       i=n-2;
       while(i>=0){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();

            if(st.empty()) suf[i]=n;
            else suf[i]=st.top();
            
            st.push(i);
            i--;

        }
        long long sum = 0;
        int mod = 1e9 + 7;
        for( i=0;i<n;i++){
          int left=i-pre[i];
          int right=suf[i]-i;
         sum = (sum + (1LL * left * right * arr[i]) % mod) % mod;
        }
        return sum;
    }
};