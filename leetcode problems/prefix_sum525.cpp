// Leetcode 
// Problem => Contiguous Array
// Link => https://leetcode.com/problems/$problem_name$/description/


// bruteforce O(N^3) | generate all subarray
class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int n = nums.size();
        int ans = 0;

        for(int i=0;i<n;i++) {

            for(int j=i;j<n;j++) {

                int zero = 0;
                int one = 0;

                for(int k=i;k<=j;k++) {

                    if(nums[k]==0)
                        zero++;
                    else
                        one++;
                }

                if(zero==one)
                    ans=max(ans,j-i+1);
            }
        }

        return ans;
    }
};

// prefix sum | O(N^2)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int n = nums.size();

        vector<int> zero(n+1,0);
        vector<int> one(n+1,0);

        for(int i=0;i<n;i++) {

            zero[i+1]=zero[i];
            one[i+1]=one[i];

            if(nums[i]==0)
                zero[i+1]++;
            else
                one[i+1]++;
        }

        int ans=0;

        for(int l=0;l<n;l++) {

            for(int r=l;r<n;r++) {

                int z=zero[r+1]-zero[l];
                int o=one[r+1]-one[l];

                if(z==o)
                    ans=max(ans,r-l+1);
            }
        }

        return ans;
    }
};

// prefix sum + hash | O(N^2)
// sources -> https://www.youtube.com/watch?v=NUQ5Ob_xUvg
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;

        mp[0] = -1;

        int sum = 0;
        int ans = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                sum -= 1;
            }
            else{
                sum += 1;
            }

            if(mp.find(sum) != mp.end()){
                ans = max(ans, i-mp[sum]);
            }else{
                mp[sum] = i;
            }
        }

        return ans;
    }
};

// solution 3 |
// sources -> https://www.youtube.com/watch?v=agB1LyObUNE