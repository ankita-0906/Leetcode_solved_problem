class Solution {
public:
    int lastStoneWeight(vector<int>& arr) {
        int n=arr.size();
        priority_queue<int>maxheap;
        for(int i=0;i<n;i++) maxheap.push(arr[i]);
        while(maxheap.size()>1){
            int first=maxheap.top();  maxheap.pop();
            int sec=maxheap.top();  maxheap.pop();

            if(abs(first-sec)>0) maxheap.push(abs(first-sec));
        }
        if(maxheap.size()==0) return 0;

        return maxheap.top();
    }
};