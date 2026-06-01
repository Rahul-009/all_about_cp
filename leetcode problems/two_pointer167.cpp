// Leetcode 
// Problem => Two Sum II - Input Array Is Sorted
// Link => https://leetcode.com/problems/$problem_name$/description/

// Bruteforce O(N^2) | nested loop
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        for(int i = 0; i<n; i++){
            for(int j= i+1; j<n; j++){
                if(numbers[i] + numbers[j] == target){
                    return {i+1, j+1};
                }
            }
        }

        return {};
    }
};

// Binary Search | O(n log n)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        for(int i=0; i<n; i++){
            int need = target - numbers[i];
            int left = i+1;
            int right = n-1;

            while(left <= right){
                int mid = left + (right-left) / 2;

                if(numbers[mid] == need){
                    return {i+1, mid+1};
                }

                else if(numbers[mid] < need){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }

        return {};
    }
};

// Two pointer | O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0;
        int right = n-1;

        while(left < right){
            int l = numbers[left]; 
            int r = numbers[right];
            int sum = l + r;
            if(sum == target){
                return {left+1, right+1};
            }

            if(sum < target){
                left++;
            }else if(sum > target){
                right--;
            }
        }

        return {};
    }
};