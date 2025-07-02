class Solution {
public:
   long long solve(vector<int>& piles, int k, int h) {
    long long sum = 0;
    for (int i = 0; i < piles.size(); i++) {
        // Integer division trick for ceiling
        if(piles[i]%k==0) sum=sum+(long long)(piles[i]/k);
        else sum=sum+(long long)(piles[i]/k)+(long long)(1);
    }
    return sum;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = *max_element(piles.begin(), piles.end()), ans = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Check if the total time for the current eating speed 'mid' is within h hours
        if (solve(piles, mid, h) <= h) {
            ans = mid;  // Update answer
            high = mid - 1;  // Try smaller eating speeds
        } else {
            low = mid + 1;  // Try larger eating speeds
        }
    }
    return ans;
}

};