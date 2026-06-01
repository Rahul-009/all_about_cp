// Leetcode 
// Problem => Word Ladder
// Link => https://leetcode.com/problems/$problem_name$/description/

// Bruteforce BFS | O(N^2*L)
class Solution {
public:
    bool oneDiff(string &a, string &b){
        int diff = 0;

        for(int i = 0; i<a.size(); i++){
            if(a[i] != b[i]){
                diff++;
            }
        }

        return diff == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> words = wordList;
        words.push_back(beginWord);

        int n = words.size();
        int start = n-1;
        int target = -1;
        
        for(int i = 0; i<n; i++){
            if(words[i] == endWord){
                target = i;
            }
        }

        if(target == -1) return 0;

        vector<vector<int>> adj(n);

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(oneDiff(words[i], words[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        queue<pair<int, int>> q;
        vector<int> vis(n, 0);

        q.push({start, 1});
        vis[start] = 1;

        while(!q.empty()){
            auto [node, dist] = q.front();
            q.pop();
            if(node == target){
                return dist;
            } 
            for(int nei: adj[node]){
                if(!vis[nei]){
                    vis[nei] = 1;
                    q.push({nei, dist+1});
                }
            }
        }

        return 0;
    }
};


// solution 2 O(N*L) | for each position try each char
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        // using set for count, find functions
        unordered_set<string> st(wordList.begin(), wordList.end());

        if(!st.count(endWord)){
            return 0;
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()){
            auto [word, level] = q.front();
            q.pop();

            if(word == endWord){
                return level;
            }

            // for each position
            for(int i=0; i<word.size(); i++){
                string temp = word;

                // try all characters and seach in wordList
                for(char ch = 'a'; ch <= 'z'; ch++){
                    temp[i] = ch;

                    // if found push to queue
                    if(st.count(temp)){
                        q.push({temp, level+1});
                        st.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};

// solution 3 O(N*L) | Bidirectional BFS
class Solution {
public:
    int ladderLength(string beginWord,
                     string endWord,
                     vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(),
                                   wordList.end());

        if (!dict.count(endWord))
            return 0;

        // BFS on 2 sets at a time
        unordered_set<string> beginSet;
        unordered_set<string> endSet;

        beginSet.insert(beginWord);
        endSet.insert(endWord);

        int level = 1;

        while (!beginSet.empty() && !endSet.empty()) {

            // always expand the smaller set
            if (beginSet.size() > endSet.size())
                swap(beginSet, endSet);

            unordered_set<string> next;

            // iterate each word of beginSet
            for (string word : beginSet) {
                for (int i = 0; i < word.size(); i++) {
                    char old = word[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        word[i] = ch;
                        // two searchs met | return ans
                        if (endSet.count(word))
                            return level + 1;


                        if (dict.count(word)) {
                            next.insert(word);
                            dict.erase(word);
                        }
                    }

                    word[i] = old;
                }
            }

            // update beginSet
            beginSet = next;
            level++;
        }

        return 0;
    }
};