class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        int i=0,prev_small,next_small,width,maxarea=0; stack<int>st;
        while(i<=n){
          while(!st.empty() && (i==n ||arr[st.top()]>arr[i])){
            int ele=arr[st.top()]; next_small=i;
            st.pop(); 
            if(st.empty())  prev_small=-1;
             else prev_small= st.top();
             width=next_small-prev_small-1;
            maxarea=max(maxarea,width*ele);
          }
          st.push(i);
          i++;
        }
        return maxarea;
    }
};