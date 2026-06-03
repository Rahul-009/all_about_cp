// Partition Equal Subset Sum


// recursion without DP
class Solution {
public:

    bool solve(int index, vector<int>& nums, int target) {

        // target achieved
        if (target == 0)
            return true;

        // out of bounds
        if (index >= nums.size())
            return false;

        // invalid target
        if (target < 0)
            return false;

        bool incl = solve(index + 1, nums, target - nums[index]);
        bool excl = solve(index + 1, nums, target);

        return incl || excl;
    }

    bool canPartition(vector<int>& nums) {

        int sum = accumulate(nums.begin(), nums.end(), 0);

        // if odd sum, can't be partitioned into 2 equal subsets
        if (sum % 2)
            return false;

        return solve(0, nums, sum / 2);
    }
};

// recursion with DP
class Solution {
public:

    vector<vector<int>> dp;

    bool solve(int index,
               vector<int>& nums,
               int target) {

        if (target == 0)
            return true;

        if (index >= nums.size())
            return false;

        if (target < 0)
            return false;

        if (dp[index][target] != -1)
            return dp[index][target];

        bool include =
            solve(index + 1,
                  nums,
                  target - nums[index]);

        bool exclude =
            solve(index + 1,
                  nums,
                  target);

        return dp[index][target] = include || exclude;
    }

    bool canPartition(vector<int>& nums) {

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2)
            return false;

        int target = sum / 2;

        dp.assign(nums.size(),
                  vector<int>(target + 1, -1));

        return solve(0, nums, target);
    }
};

// 1D DP iterative
class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2)
            return false;

        int target = sum / 2;
        int n = nums.size();

        vector<vector<bool>> dp(n + 1,
                                vector<bool>(target + 1, false));

        for (int i = 0; i <= n; i++)
            dp[i][0] = true;

        for (int i = 1; i <= n; i++) {

            for (int s = 1; s <= target; s++) {

                dp[i][s] = dp[i - 1][s];

                if (s >= nums[i - 1]) {
                    dp[i][s] =
                        dp[i][s] ||
                        dp[i - 1][s - nums[i - 1]];
                }
            }
        }

        return dp[n][target];
    }
};

