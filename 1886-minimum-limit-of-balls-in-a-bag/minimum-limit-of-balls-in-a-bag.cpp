class Solution {
public:
   bool canDistribute(vector<int>& nums, int maxOperations, int penalty) {
        int operations = 0;
        for (int balls : nums) {
            if (balls > penalty) {
                operations += (balls - 1) / penalty; // Number of splits required
            }
            if (operations > maxOperations) return false; // Exceeded allowed operations
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canDistribute(nums, maxOperations, mid)) {
                result = mid; // Update the minimum penalty
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};