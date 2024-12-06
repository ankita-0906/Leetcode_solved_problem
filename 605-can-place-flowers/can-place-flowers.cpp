class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
       int len= arr.size(),i=0,cnt=0; 

       //hendling if length of array is 1
       if(len==1 && arr[0]==0){
        cnt++; return cnt>=n;
       }

       while(i<len){
        if( i==0 && arr[i]==0 && arr[i+1]==0){
          cnt++; arr[i]=1;
        } 
        else if( i==len-1 && arr[i]==0 && arr[i-1]==0){
        cnt++; arr[i]=1;
        }
        else if( i!=0 && i!=len-1 && arr[i]==0 && arr[i-1]==0 && arr[i+1]==0){
        cnt++;arr[i]=1;
        } 
        
         i++;
       }
       return cnt>=n;
    }
};