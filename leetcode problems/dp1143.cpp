// Leetcode 
// Problem => Longest Common Subsequence 

// Bruteforce | O(2^N+M)
class Solution {
public:

    int solve(string& s1, string& s2, int i, int j) {

        if (i == s1.size() || j == s2.size())
            return 0;

        if (s1[i] == s2[j]) {
            return 1 + solve(s1, s2, i + 1, j + 1);
        }

        return max(
            solve(s1, s2, i + 1, j),
            solve(s1, s2, i, j + 1)
        );
    }

    int longestCommonSubsequence(string text1,
                                 string text2) {

        return solve(text1, text2, 0, 0);
    }
};

// DP | O(N*M)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j],
                                   dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};

// print the longest common subsequence
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {

    string text1 = "abcde";
    string text2 = "ace";

    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j],
                               dp[i][j - 1]);
            }
        }
    }

    cout << "Length = " << dp[n][m] << "\n";

    string lcs = "";

    int i = n;
    int j = m;

    while (i > 0 && j > 0) {

        if (text1[i - 1] == text2[j - 1]) {

            lcs.push_back(text1[i - 1]);

            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());

    cout << "LCS = " << lcs << "\n";

    return 0;
}