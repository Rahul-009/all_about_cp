// problem - Non overlapping Intervals

// Classic avtivity selection problem
// sort by end time | remove the task that ends last
/*
[1,100]
[2,3]
[4,5]
[6,7]

sorting by end time
[2,3]
[4,5]
[6,7]
[1,100]

this maximize the number of non overlapping intervals

*/


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        int count = 1;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i][0] >= prevEnd) {
                count++;
                prevEnd = intervals[i][1];
            }
        }

        return intervals.size() - count;
    }
};