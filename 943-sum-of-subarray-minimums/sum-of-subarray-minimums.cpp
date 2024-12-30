class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
       int n=nums.size();
        // next smaller element
    vector<int>suff(n);
    stack<int>st;int i=n-1;
    while(i>=0){
        while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
        if(st.empty()) suff[i]=n;
        else suff[i]=st.top();
        st.push(i);
        i--;
    }
    // previous smaller element
    vector<int>pre(n);
    stack<int>s; i=0;
    while(i<n){
        while(!s.empty() && nums[s.top()]>nums[i]) s.pop();
        if(s.empty()) pre[i]=-1;
        else pre[i]=s.top();
        s.push(i);
        i++;
    }
    long long subarray=0;int mod=1e9 + 7;
    for(int i=0;i<n;i++){
        int left=i-pre[i]; int right=suff[i]-i;
        long long ans=(((left*right*1LL)%mod)*nums[i]*1LL)%mod;
        subarray=(subarray+ans)%mod;
    }
    return subarray;
    //  int n = arr.size();
    // const int MOD = 1e9 + 7;

    // // Vectors for previous smaller and next smaller elements
    // vector<int> prev(n), next(n);
    // stack<int> st;

    // // Calculate previous smaller elements
    // for (int i = 0; i < n; ++i) {
    //     while (!st.empty() && arr[st.top()] >= arr[i]) {
    //         st.pop();
    //     }
    //     prev[i] = st.empty() ? -1 : st.top();
    //     st.push(i);
    // }

    // // Clear the stack for reuse
    // while (!st.empty()) {
    //     st.pop();
    // }

    // // Calculate next smaller elements
    // for (int i = n - 1; i >= 0; --i) {
    //     while (!st.empty() && arr[st.top()] > arr[i]) {
    //         st.pop();
    //     }
    //     next[i] = st.empty() ? n : st.top();
    //     st.push(i);
    // }

    // // Calculate the sum of minimums
    // long long sum = 0;
    // for (int i = 0; i < n; ++i) {
    //     long long left = i - prev[i];
    //     long long right = next[i] - i;
    //     sum = (sum + arr[i] * left % MOD * right % MOD) % MOD;
    // }

    // return sum;

    }
};