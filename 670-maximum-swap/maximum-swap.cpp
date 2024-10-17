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
        vector<int> rightMaxIndex(n); // Track the rightmost largest digit index

    // Start by assuming the last digit is the largest
    int maxIdx = n - 1;
    rightMaxIndex[n - 1] = n - 1;

    // Traverse from right to left and track the largest digit
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > arr[maxIdx]) {
            maxIdx = i;
        }
        rightMaxIndex[i] = maxIdx;
    }

    // Find the first position where a swap can improve the number
    for (int i = 0; i < n; i++) {
        // If the current digit is smaller than the largest digit to its right, swap them
        if (arr[i] < arr[rightMaxIndex[i]]) {
            swap(arr[i], arr[rightMaxIndex[i]]);
            break; // Only one swap is allowed
        }
    }
       // if(index==n) return digit;
        //swap(arr[i],arr[index]);
        for(int i=0;i<n;i++){
            sum=sum*10+arr[i];
        }
       return sum;
    }
};