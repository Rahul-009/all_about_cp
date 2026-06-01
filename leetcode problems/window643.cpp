// Leetcode 
// Problem => maximum Average Subarray I
// Link => 

// bruteforce O(n^2)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = -1e9;
        
        int n = nums.size();
        for(int i=0; i<=n-k; i++){
            int sum = 0;
            for(int j=i; j<i+k; j++){
                sum += nums[j];
            }
            ans = max(ans, (double)sum/k);
        }

        return ans;
    }
};

// sliding window O(n) | Best solution
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = 0;

        //first window sum
        for(int i=0; i<k; i++){
            sum += nums[i];
        }

        long long maxSum = sum;

        //slide window
        for(int i = k; i < nums.size(); i++){
            sum += nums[i];
            sum -= nums[i-k];

            maxSum = max(maxSum, sum);
        }

        return (double)maxSum / k;
    }
};

// prefix sum O(n)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();

        vector<long long> prefix(n + 1, 0);

        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        double ans = -1e9;

        for(int i = 0; i <= n - k; i++) {

            long long sum =
                prefix[i + k] - prefix[i];

            ans = max(ans, (double)sum / k);
        }

        return ans;
    }
};