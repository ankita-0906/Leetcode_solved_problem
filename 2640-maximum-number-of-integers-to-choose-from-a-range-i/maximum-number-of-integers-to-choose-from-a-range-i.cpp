class Solution {
public:
    int maxCount(vector<int>& arr, int n, int maxsum) {
        //sort(arr.begin(),arr.end());
        int sum=0,cnt=0;
        for(int i=1;i<=n;i++){
         if(find(arr.begin(),arr.end(),i)==arr.end() && sum+i<=maxsum){
            sum=sum+i;cnt++;
         }
         
        }
        return cnt;
    }
};