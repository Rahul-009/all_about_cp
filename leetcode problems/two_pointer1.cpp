// Leetcode 
// Problem => Two Sum 
// Link => https://leetcode.com/problems/$problem_name$/description/


// Bruteforce O(N^2)

// Sort + Two pointer | O(n*logn)

// Sort + binary search | O(n*logn)

// Hash map | O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for(int i=0; i<nums.size(); i++){
            int need = target - nums[i];

            // if present in map return
            if(mp.find(need) != mp.end()){
                return {mp[need], i};
            }

            // store in map
            mp[nums[i]] = i;
        }
        return {};
    }
};