class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
         int n = nums.size();
    vector<int> parityMismatch(n - 1, 0);
    
    for (int i = 0; i < n - 1; i++) {
        parityMismatch[i] = (nums[i] % 2 == nums[i + 1] % 2) ? 1 : 0;
    }

   
    vector<int> prefixSum(n, 0);
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + parityMismatch[i - 1];
    }

   
    vector<bool> answer;
    for (const auto& query : queries) {
        int fromi = query[0], toi = query[1];
       
        int mismatches = prefixSum[toi] - prefixSum[fromi];
        answer.push_back(mismatches == 0);
    }
    return answer;
    }
   



};