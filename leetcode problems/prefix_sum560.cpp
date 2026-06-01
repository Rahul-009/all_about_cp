// Leetcode 
// Problem => Subarray Sum Equals K
// Link => https://leetcode.com/problems/$problem_name$/description/

// Bruteforce | O(N^3)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        int cnt = 0;

        for(int i=0; i<n; i++) {

            for(int j=i; j<n; j++) {

                int sum = 0;

                for(int p=i; p<=j; p++) {
                    sum += nums[p];
                }

                if(sum == k)
                    cnt++;
            }
        }

        return cnt;
    }
};

// prefix sum | O(N^2)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();

        vector<int> prefix(n+1, 0);

        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i] + nums[i];
        }

        int cnt = 0;

        for(int l=0; l<n; l++){
            for(int r=l; r<n; r++){
                int sum = prefix[r+1] - prefix[l];
                if(sum == k) cnt++;
            }
        }

        return cnt;
    }
};

// Prefix sum + hash map | O(N)
// soure => https://www.youtube.com/watch?v=YxRmeRyVQm4
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0;
        int cnt = 0;

        for(int x: nums){
            sum += x;

            if(mp.find(sum-k) != mp.end()){
                cnt += mp[sum-k];
            }

            mp[sum]++;
        }

        return cnt;
    }
};