// Leetcode 
// Problem => Range Sum Query - immutable
// Link => https://leetcode.com/problems/range-sum-query-immutable/description/

// Brute force O(n^2)
class NumArray {
public:
    vector<int> arr;
    NumArray(vector<int>& nums) {
        arr = nums;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for(int i = left; i <= right; i++) {
            sum += arr[i];
        }
        return sum;
    }
};


// prefix sum O(n)
class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n);
        prefix[0] = nums[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0)
            return prefix[right];
        return prefix[right] - prefix[left - 1];
    }
};