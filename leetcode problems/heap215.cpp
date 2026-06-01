// Leetcode 
// Problem => Kth Largest Element in a Array
// Link => https://leetcode.com/problems/$problem_name$/description/

// sorting | O(n*logn)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n-k];
    }
};

// sorting II | O(n*logn)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        return nums[k-1];
    }
};

// Min heap | O(n+klogn)  | better than sorting
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int num: nums){
            pq.push(num);

            if(pq.size() > k){
                pq.pop();
            }
        }

        return pq.top();
    }
};


// Quick select O(n)

// counting sort/frequency array | O(n) | works for small numbers
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        vector<int> freq(20001, 0);

        for(int num : nums)
            freq[num + 10000]++;

        for(int i = 20000; i >= 0; i--) {

            k -= freq[i];

            if(k <= 0)
                return i - 10000;
        }

        return -1;
    }
};