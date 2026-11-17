// euler traverse each edge exactly once
// hamitonian traverse each node exactly once

// Traveling Salesman Problem
// O(n!)

// NP Hard Problem
// optimization problem N^2 * 2^N | DP

// Hamiltonian path (start != end)
// Hamiltonian cycle (start == end)

// Hamiltonian path exist | cycle may not exist
// hamiltonian cycle exist | path will exist

// bruteforce



bool dfs(int node, vector<vector<int>> &g, vector<bool>&vis, int count, int N){
    vis[node] = 1;
    count++;

    if(count == N) return 1;

    for(auto child: g[node]){
        if(!vis[child])
            if(dfs(child, g, vis, count, N)) return 1;
    }
    vis[node] = 0;
    count--;
    return 0;
}

bool hamilton(){
    vector<bool> vis(N, 0);
    int vis_count = 0;

    for(int i=0; i<N; i++){
        if(dfs(i, g, vis, vis_count, N)) return 1;
    }

    return 0
}