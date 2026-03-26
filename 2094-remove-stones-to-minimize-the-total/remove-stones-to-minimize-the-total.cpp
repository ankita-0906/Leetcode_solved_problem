class Solution {
public:
    int minStoneSum(vector<int>& arr, int k) {
        priority_queue<int>maxheap(arr.begin(),arr.end()); 
        int n=arr.size();
        for(int i=0;i<k;i++){
         int maxi=maxheap.top(); maxheap.pop();
         maxheap.push(maxi-floor(maxi/2));
        }
        int sum=0;
        while(!maxheap.empty()){
            sum=sum+maxheap.top(); maxheap.pop();
        }
        return sum;

    }
};