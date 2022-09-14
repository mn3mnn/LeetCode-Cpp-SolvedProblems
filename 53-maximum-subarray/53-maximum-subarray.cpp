

class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 1) return nums[0];

        vector<int> dp(sz, 0);
        dp[0] = nums[0];

        for (int i = 1; i < sz; ++i) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        //  dp[i] = (nums[i] > dp[i - 1] + nums[i] ? nums[i] : dp[i - 1] + nums[i]);
        }

        return *max_element(dp.begin(), dp.end());
    }

};