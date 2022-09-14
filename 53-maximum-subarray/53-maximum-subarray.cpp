

class Solution {
public:


    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 1) return nums[0];

        vector<int> dp(sz, 0);
        dp[0] = nums[0];
        int max_sum = dp[0];

        int j = 0;
        for (int i = 1; i < sz; ++i) {
    //        dp[i] = max(nums[i], dp[j] + nums[i]);
            dp[i] = (nums[i] > dp[j] + nums[i] ? nums[i] : dp[j] + nums[i]);
            j++;
            max_sum = (dp[i] > max_sum ? dp[i] : max_sum);
        }
    //    int max_sum = *max_element(dp.begin(), dp.end());
        return max_sum;
    }

};