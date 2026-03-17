class Solution {
public:
    int nthUglyNumber(int n) {
       vector<int>arr(n+1,0);
       arr[1]=1;
       int i2=1,i3=1,i5=1;
       for(int i=2;i<=n;i++){
        int ugly2=arr[i2]*2;
        int ugly3=arr[i3]*3;
        int ugly5=arr[i5]*5;

        arr[i]=min({ugly2, ugly3,ugly5});

        if(arr[i]==ugly2) i2++;
        if(arr[i]==ugly3) i3++;
        if(arr[i]==ugly5) i5++;
       }
       return arr[n];
    }
};