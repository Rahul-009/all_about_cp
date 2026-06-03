// problem - Find the Duplicate Number

// bruteforce | O(n^2) time | O(1) memory | TLE
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(nums[i] == nums[j])
                    return nums[i];
            }
        }

        return -1;
    }
};

// bruteforce | O(n) time | O(n) memory
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for(int x : nums) {
            if(seen.count(x))
                return x;

            seen.insert(x);
        }

        return -1;
    }
};

// sorting | O(nlogn) time | O(1) memory
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i=1; i<nums.size(); i++)
            if(nums[i] == nums[i-1])
                return nums[i];
        
        return 0;
    }
};

// Floyd's Tortoise and Hare Algorithm | O(n) time | O(1) memory
// memorize - https://www.youtube.com/watch?v=wjYnzkAhcNk
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = 0;
        int fast = 0;

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        
        int slow2 = 0;
        
        while(slow != slow2) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }

        return slow;
    }
};