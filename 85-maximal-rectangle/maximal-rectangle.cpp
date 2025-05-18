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
          if(i<n)st.push(i);
          i++;
        }
        return maxarea;
    }
   



    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        
        vector<int>row(m,0);
         int maxarea=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') row[j]=row[j]+1;
                else row[j]=0;
            }
            maxarea=max(maxarea,histo(row));
        }

       
       
       
        return maxarea;
    }
};