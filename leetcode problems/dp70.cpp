// Leetcode 
// Problem => Climbing Stairs
// Link => https://leetcode.com/problems/$problem_name$/description/


// Normal dp
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;

        vector<int> dp(n+1);

        dp[1] = 1;
        dp[2] = 2;

        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};

// Space optimized DP 
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int prev2 = 1; // dp[1]
        int prev1 = 2; // dp[2]

        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};