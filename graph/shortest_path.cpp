// DFS - complex
// BFS
// Djikstra
    // single source, all 
    // Can solve Weighted directed, undirected graph
    // Cannot handle negative edge

    // priority queue overhead | time complexity higher than BFS, DFS
// Bellman Ford
    // n-1 bar djikstra
    // can handle negetive edge
    // cannot handle negative cycle
// Floyd Warshall
    // all source, all dest

==============================================================================
// Unweighted Undirected Graph
    // using DFS | 
        // explore all paths separately
        // cycle thakle time complexity onek bere jabe | not good


    // using BFS
    vector<int> dist(N, -1);
    vector<bool> vis(N, 0);

    void bfs(int src){
        queue<int> q;
        q.push(src);

        dist[src] = 0;
        vis[src] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto child: g[node]){
                if(!vis[child]){
                    dist[child] = dist[node] + 1;
                    vis[child] = true;
                    q.push(child);
                    // par[child] = node;
                }
            }
        }
    }

    // print shortest path
        // parent info store kore rakhte hobe just
    vector<int> par(N, -1);
    vector<int> path;

    while(dest != -1){
        path.push_back(dest);
        dest = par[dest];
    }
    reverse(path.begin(), path.end());

// For Weighted Undirected Graph
    // djikstra
    vector<int> dist(N, INT_MAX);
    vector<int> par(N, -1);
    vector<int> vis(N, 0);

    void djikstra(int src){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        vis[src] = true;
        dist[0] = 0;

        while(!pq.empty()){
            auto [wt, node] = pq.front();
            pq.pop();

            for(auto [c_wt, c_val]: g[node]){
                if(vis[c_val]) continue;
                if(dist[node] + c_wt < dist[c_val]){
                    dist[c_val] = dist[node] + c_wt;
                    pq.push({dist[c_val], c_val});
                    par[c_val] = node;
                }
            }
        }
    }

    vector<int> path;
    int dest = some_node;

    while(!dest){
        path.push_back(dest);
        dest = par[dest];
    }
    reverse(path.begin(), path.end());
    
// For Directed Acyclic Graph
    // 1. Djikstra | not efficient
    // 2. modified DFS | Track and backtrack Path | visits node multiple time
    
    
    // 3. Find Topsort | Then do dfs | Fastest | no double visit
    int N;
    const int INF = INT_MAX;
    vector<int> dist(N, INF);
    stack<int> stk;
    vector<bool> vis(N, 0);

    void topSort(int src){
        vis[src] = true;

        for(auto [child_node, child_weight]: g[src]){
            if(!vis[child_node]){
                topSort(child_node);
            }
        }
        stk.push(src);
    }

    topSort(0);

    while(!stk.empty()){
        int node = stk.top();
        stk.pop();

        for(auto [child_node, child_wt]: g[node]){
            if(dist[node] + child_wt < dist[child_node]){
                dist[child_node] = dist[node] + child_wt;
            }
        }
    }

    
