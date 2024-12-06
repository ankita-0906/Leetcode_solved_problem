class Solution {
public:
    int maxCount(vector<int>& arr, int n, int maxsum) {
        sort(arr.begin(),arr.end());
        int sum=0,cnt=0,index=0,len=arr.size();
        for(int i=1;i<=n;i++){
         if(index<len && i==arr[index]){
            while(index<len && i==arr[index]) index++;
         }
         else if(sum+i<=maxsum){
            sum=sum+i; cnt++;
         }
         //if(sum>maxsum) break;
        }
        return cnt;
    }
};