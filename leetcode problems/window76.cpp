// Leetcode 
// Problem => Minimum window substring
// Link => https://leetcode.com/problems/$problem_name$/description/


// Bruteforce | O(N)
class Solution {
public:
    bool valid(vector<int>& window, vector<int>& need) {
        for(int i = 0; i < 128; i++) {
            if(window[i] < need[i])
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {

        vector<int> need(128, 0);

        for(char c : t)
            need[c]++;

        int bestLen = INT_MAX;
        int bestStart = 0;

        int n = s.size();

        for(int i = 0; i < n; i++) {

            vector<int> window(128, 0);

            for(int j = i; j < n; j++) {

                window[s[j]]++;

                if(valid(window, need)) {

                    if(j - i + 1 < bestLen) {
                        bestLen = j - i + 1;
                        bestStart = i;
                    }

                    break; // no need to extend further
                }
            }
        }

        return bestLen == INT_MAX
            ? ""
            : s.substr(bestStart, bestLen);
    }
};

// hash + window | O(N)
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);

        for(char c : t)
            need[c]++;
        
        int required = 0;

        for(int x: need){
            if(x > 0){
                required++;
            }
        }

        vector<int> window(128, 0);

        int formed = 0;
        int l = 0;
        int bestLen = INT_MAX;
        int bestStart = 0;

        for(int r=0; r<s.size(); r++){
            char c = s[r];
            window[c]++;

            if(need[c]>0 && window[c] == need[c])
                formed++;

            while(formed == required){
                if(r-l+1 < bestLen){
                    bestLen = r-l+1;
                    bestStart = l;
                }

                // remove left char
                char leftChar = s[l];
                window[leftChar]--;

                if(need[leftChar] > 0 && window[leftChar] < need[leftChar])
                    formed--;

                l++;
            }
        }

        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
};

// filtered sliding window 
class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> need;

        for(char c : t)
            need[c]++;

        int required = need.size();

        vector<pair<int,char>> filtered;

        for(int i = 0; i < s.size(); i++) {
            if(need.count(s[i]))
                filtered.push_back({i, s[i]});
        }

        unordered_map<char,int> window;

        int formed = 0;
        int l = 0;

        int bestLen = INT_MAX;
        int bestStart = 0;

        for(int r = 0; r < filtered.size(); r++) {

            char c = filtered[r].second;

            window[c]++;

            if(window[c] == need[c])
                formed++;

            while(formed == required) {

                int start = filtered[l].first;
                int end   = filtered[r].first;

                if(end - start + 1 < bestLen) {
                    bestLen = end - start + 1;
                    bestStart = start;
                }

                char leftChar = filtered[l].second;

                window[leftChar]--;

                if(window[leftChar] < need[leftChar])
                    formed--;

                l++;
            }
        }

        return bestLen == INT_MAX
            ? ""
            : s.substr(bestStart, bestLen);
    }
};