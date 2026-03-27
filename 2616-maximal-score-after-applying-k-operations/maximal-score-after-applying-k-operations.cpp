class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int>maxheap;
        for(int i=0;i<n;i++){
          maxheap.push(nums[i]);
        }
        long long total=0;
        for(int i=0;i<k;i++){
            int ele=maxheap.top();
           total=total+(long long)ele;
           maxheap.pop();
           maxheap.push(ceil((double)ele / 3));
        }
        return total;
    }
};