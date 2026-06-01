// Leetcode 
// Problem => 3Sum
// Link => https://leetcode.com/problems/$problem_name$/description/


// Bruteforce | O(N^3) | sort ans and store in set (handle duplicate)

// Hashmap O(N^2)

// Sort + two pointer | O(N^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        for(int i=0; i<n-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int left = i+1;
            int right = n-1;

            while(left<right){
                long long sum = (long long)nums[i] + nums[left] + nums[right];

                if(sum == 0){
                    ans.push_back({nums[i], nums[left], nums[right]});

                    while(left < right && nums[right] == nums[right-1])
                        right--;

                    while(left < right && nums[left] == nums[left+1])
                        left++;

                    left++; right--;
                }
                else if(sum < 0){
                    left ++;
                }
                else{
                    right--;
                }
            }
        }
        return ans;
    }
};