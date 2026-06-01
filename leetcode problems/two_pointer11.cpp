// Leetcode 
// Problem => Container with most water
// Link => https://leetcode.com/problems/$problem_name$/description/


// Brute force | O(N^2)

// Brute force + Pruning | O(N^2)

// Two pointer | O(N)
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        int left = 0;
        int right = n - 1;

        int ans = 0;

        while(left < right){
            int area = (right - left) * min(height[left], height[right]);

            ans = max(ans, area);

            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
};