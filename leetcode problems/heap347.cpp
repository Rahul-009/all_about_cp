// Leetcode 
// Problem => Top K Frequent Elements
// Link => https://leetcode.com/problems/$problem_name$/description/

// frequency + heap
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;
        int n = nums.size();
        
        for(int num: nums){
            freq[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto &[num, count]: freq){
            pq.push({count, num});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

// bucket sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for(int num : nums)
            freq[num]++;

        vector<vector<int>> bucket(nums.size() + 1);

        for(auto &[num, count]: freq){
            bucket[count].push_back(num);
        }

        vector<int> ans;

        for(int f = nums.size(); f>=1; f--){
            for(int num: bucket[f]){
                ans.push_back(num);

                if(ans.size()==k) return ans;
            }
        }

        return ans;
    }
};