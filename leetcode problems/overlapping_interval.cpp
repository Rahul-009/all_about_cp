// problem - Insert interval

Intervals:

1----2

   3----5
       6--7
         8----10

New:
      4-------8

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        vector<vector<int>> ans;
        int i = 0;
        int n = intervals.size();

        // Case 1: intervals before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        // Case 2: overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        ans.push_back(newInterval);

        // Case 3: intervals after newInterval
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};