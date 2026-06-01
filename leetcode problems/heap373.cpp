// Leetcode 
// Problem => Find K pairs with smallest sums
// Link => https://leetcode.com/problems/$problem_name$/description/


// min heap | O(k log k)
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<vector<int>> ans;
        using T = tuple<long long, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        int n = nums1.size();
        int m = nums2.size();

        // init the pq with the first col
        for(int i = 0; i<min(n, k); i++){
            pq.push({(long long)nums1[i] + nums2[0], i, 0});
        }

        while(k-- && !pq.empty()){

            // take the smallest pair and remove
            auto [sum, i, j] = pq.top();
            pq.pop();

            ans.push_back({nums1[i], nums2[j]});

            // insert the next col of the smallest pair
            if(j+1 < m){
                pq.push({(long long)nums1[i] + nums2[j+1], i, j+1});
            }
        }

        return ans;
    }
};