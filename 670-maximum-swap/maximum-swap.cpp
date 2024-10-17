class Solution {
public:
    int maximumSwap(int num) {
        vector<int>arr;
        int digit =num;
        while(num!=0){
            arr.push_back(num%10);
            num=num/10;
        }
        reverse(arr.begin(),arr.end());

        int n=arr.size();
        int index=n,sum=0;
         int i;
        for( i=0;i<n;i++){
            int maxi=arr[i];
            for(int j=n-1;j>i;j--){
                if(maxi<arr[j]){
                    maxi=arr[j];
                    index=j;
                }
            }
            if(maxi!=arr[i]) break;
        }
        if(index==n) return digit;
        swap(arr[i],arr[index]);
        for(int i=0;i<n;i++){
            sum=sum*10+arr[i];
        }
       return sum;
    }
};