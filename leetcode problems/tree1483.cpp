// Leetcode 
// Problem => Kth Ancestor of a Tree Node
// Link => https://leetcode.com/problems/problem_name/description/


// bruteforce | O(N*Q) | TLE
class TreeAncestor {
public:
    vector<int> par;
    TreeAncestor(int n, vector<int>& parent) {
        par = parent;
    }
    
    int getKthAncestor(int node, int k) {
        while(k-- && node != -1){
            node = par[node];
        }

        return node;
    }
};

// binary lifting | O(n log n)
class TreeAncestor {
public:

    int LOG;
    vector<vector<int>> up;

    TreeAncestor(int n, vector<int>& parent) {

        LOG = 16;

        up.assign(n, vector<int>(LOG, -1));

        // init 2^0 ancestors
        for(int i = 0; i < n; i++)
            up[i][0] = parent[i];

        // inti 2^1 to 2^16 ancestors
        for(int j = 1; j < LOG; j++) {
            // for eaach node
            for(int i = 0; i < n; i++) {
                int mid = up[i][j-1];
                if(mid != -1)
                    up[i][j] = up[mid][j-1];
            }
        }
    }

    int getKthAncestor(int node, int k) {

        for(int j = 0; j < LOG && node != -1; j++) {
            if(k & (1 << j))
                node = up[node][j];
        }

        return node;
    }
};
