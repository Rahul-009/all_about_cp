// Minimum Spanning Tree
    // application | railway station

// Questions
    // minimum spanning tree cost = ?
    // draw/print the minimum spanning tree

// Subset of edges that forms a tree 
// Must include all nodes

// approach 1 - bad
    // find all spanning tree, 
    // find the tree with minimum total weight

// When to use which algo
    // Dense vs Sparse
    // Time Complexity

// approach 2 - Prim's | Node centerd | bfs style
// O(ElogV)
vector<int> inMST(N, 0);
vector<int> par(N, -1);
int mstCost = 0;

void bfs(int node){
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> pq;
    pq.push({0, {node, -1}}); // {wt, {node, par}}
    inMST[node] = 1;

    while(!pq.empty()){
        auto el = pq.top();
        int wt = el.first;
        int node = el.second.first;
        int par = el.second.second;
        pq.pop();

        for(auto [c_wt, c_node]: g[node]){
            if(inMST[c_node]) continue;

            inMST[c_node] = true;
            par[c_node] = node;
            mstCost += c_wt;

            pq.push({c_wt, c_node, node});
        }
    }
}

// approach 3 - kruskal's | Greedy | edge centered | DSU 
    // Take the smallest edge 
    // check if 2 associated nodes belong to same set or not
