// Leetcode 
// Problem => Longest Substring without repeating character
// Link => https://leetcode.com/problems/$problem_name$/description/


// hash + window
// hash using set / vector

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> st;

        int l = 0;
        int ans = 0;

        for(int r= 0; r < s.size(); r++){
            while(st.count(s[r])){
                st.erase(s[l]);
                l++;
            }

            st.insert(s[r]);
            ans = max(ans, r-l+1);
        }

        return ans;
    }
};


// storing last position
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // string includes ASCII symbols
        vector<int> lastPos(256, -1);

        int l = 0;
        int ans = 0;

        for(int r = 0; r<s.size(); r++){
            if(lastPos[s[r]] != -1){
                l = max(l, lastPos[s[r]] + 1);
            }

            lastPos[s[r]] = r;
            ans = max(ans, r-l+1);
        }

        return ans;
    }
};