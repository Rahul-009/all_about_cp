// Leetcode 
// Problem => Longest Increasing Subsequence 300


// Bruteforce | O(2^N)
class Solution {
public:
    int solve(vector<int>& nums, int index, int prev) {
        if (index == nums.size())
            return 0;

        int notTake = solve(nums, index + 1, prev);

        int take = 0;
        if (prev == -1 || nums[index] > nums[prev]) {
            take = 1 + solve(nums, index + 1, index);
        }

        return max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        return solve(nums, 0, -1);
    }
};

// dp } O(N^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // init with 1 dp array
        vector<int> dp(n, 1);

        int ans = 1;

        // find longest increasing subsequence ending at i
        for (int i = 1; i < n; i++) {

            // from 0 to i-1
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};


// print the longest increasing subsequence
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    int n = nums.size();

    // dp[i] = LIS length ending at i
    vector<int> dp(n, 1);

    // parent[i] = previous index in LIS
    vector<int> parent(n, -1);

    int lisEnd = 0;

    for (int i = 1; i < n; i++) {

        for (int j = 0; j < i; j++) {

            if (nums[i] > nums[j] &&
                dp[j] + 1 > dp[i]) {

                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }

        if (dp[i] > dp[lisEnd])
            lisEnd = i;
    }

    cout << "LIS Length = " << dp[lisEnd] << "\n";

    // Reconstruct LIS
    vector<int> lis;

    int curr = lisEnd;

    while (curr != -1) {
        lis.push_back(nums[curr]);
        curr = parent[curr];
    }

    reverse(lis.begin(), lis.end());

    cout << "LIS = ";

    for (int x : lis)
        cout << x << " ";

    cout << "\n";

    return 0;
}       