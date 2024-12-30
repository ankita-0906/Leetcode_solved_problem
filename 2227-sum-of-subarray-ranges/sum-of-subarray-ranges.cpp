class Solution {
public:
   long long subarray_max(vector<int>& nums,int n){
    //next greater element
    vector<int>suff(n);
    stack<int>st;int i=n-1;
    while(i>=0){
        while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
        if(st.empty()) suff[i]=n;
        else suff[i]=st.top();
        st.push(i);
        i--;
    }
    // previous greater element
    vector<int>pre(n);
    stack<int>s; i=0;
    while(i<n){
        while(!s.empty() && nums[s.top()]<nums[i]) s.pop();
        if(s.empty()) pre[i]=-1;
        else pre[i]=s.top();
        s.push(i);
        i++;
    }
    long long subarray=0;
    //int mod=1e9+7;
    for(int i=0;i<n;i++){
        int left=i-pre[i]; int right=suff[i]-i;
        long long ans=((left*right*1LL)*nums[i]);
        subarray=subarray+ans;
    }
    return subarray;
   }
   long long subarray_min(vector<int>& nums,int n){
    //next smaller element
    vector<int>suff(n);
    stack<int>s;int i=n-1;
    while(i>=0){
        while(!s.empty() && nums[s.top()]>=nums[i]) s.pop();
        if(s.empty()) suff[i]=n;
        else suff[i]=s.top();
        s.push(i);
        i--;
    }
    // previous smaller element
    vector<int>pre(n);
    stack<int>st; i=0;
    while(i<n){
        while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
        if(st.empty()) pre[i]=-1;
        else pre[i]=st.top();
        st.push(i);
        i++;
    }
    long long subarray=0;
    //int mod=1e9+7;
    for(int i=0;i<n;i++){
        int left=i-pre[i]; int right=suff[i]-i;
        long long ans=((left*right*1LL)*nums[i]);
        subarray=subarray+ans;
    }
    return subarray;
   }
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        return(subarray_max(nums,n)-subarray_min(nums,n));
    }
};