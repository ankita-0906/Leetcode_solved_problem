class Solution {
public:
   int histo(vector<int>& arr) {
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
   



    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        
        vector<vector<int>>pre(n,vector<int>(m));

        for(int j=0;j<m;j++){
            int sum=0;
          for(int i=0;i<n;i++){
             if(matrix[i][j]!='0') sum=sum+matrix[i][j]-'0';
             else sum=0;
             pre[i][j]=sum;
            
          }
          
        }
        int maxarea=0;
        for(int i=0;i<n;i++){
           maxarea=max(maxarea,histo(pre[i]));
        }
        return maxarea;
    }
};