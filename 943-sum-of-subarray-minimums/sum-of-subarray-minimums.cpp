class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
       
     int n = arr.size();
    const int mod = 1e9 + 7;
   int i=0,prev_small,next_small,left,right; stack<int>st;
   long long subarray=0;
        while(i<n){
          while(!st.empty() && arr[st.top()]>arr[i]){
            int index=st.top(); next_small=i;
            st.pop(); 
            if(st.empty())  prev_small=-1;
             else prev_small= st.top();
            left=index-prev_small;right=next_small-index;
            long long ans=(((left*right*1LL)%mod)*arr[index]*1LL)%mod;
            subarray=(subarray+ans)%mod;
          }
          st.push(i);
          i++;
        }
        next_small = n;
        while (!st.empty()) {
            int index = st.top(); st.pop();
            if (st.empty()) prev_small = -1;
            else prev_small = st.top();
            left=index-prev_small;right=next_small-index;
            long long ans=(((left*right*1LL)%mod)*arr[index]*1LL)%mod;
            subarray=(subarray+ans)%mod;
            
        }
    
        return subarray;

    }
};