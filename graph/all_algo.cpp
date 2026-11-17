// yt playlist => https://youtube.com/playlist?list=PLGjplNEQ1it-0w_PkFtKzH0ZExo6Lvm6R&si=-Xh1Cgbfwrz21Uck
// Coder Army
// Sraddha DSA playlist
// Love Babbar

// DFS
void dfs(int src){
    vis[src] = true;

    for(auto child : g[src]){
        if(!vis[child]){
            dfs(child);
        }
    }
}

// BFS | multi-source | 0-1
void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while(!q.empty()){
        curr_node = q.front();
        q.pop();

        for(auto child: g[curr_node]){
            if(vis[child]) continue;

            q.push(child);
            vis[child] = true;
        }
    }
}

// Djikstra | path relaxation
void djikstra(int src){
    priority_queue<pair<int, int>> pq;
    vector<int> vis(N, 0);
    vector<int> dist(N, INF);
    pq.push({0, src});
    vis[src] = true;

    while(!pq.empty()){
        auto [curr_wt, curr_node] = pq.front();
        pq.pop();

        for(auto child: g[curr_node]){
            auto [child_wt, child_node] = child;
            if(vis[child_node]) continue;
            vis[child_node] = true;

            if(dist[curr_node] + child_wt < dist[child_node]){
                dist[child_node] = dist[curr_node] + child_wt
                pq.push({child_wt, child_node});
            }
        }
    }
}

// Bellman Ford
void bellman(int src){
    dist[src] = 0;

    for(int k=0; k<n-1; k++){
        for(int i=0; i<n; i++){
            auto [u, v, wt] = edges[i];                

            if(dist[u] != INF && dist[u] + v_wt < dist[v]){
                dist[v] = dist[u] + v_wt;
            }
        }
    }
}

// Floyd Warshall
void floyd(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for(int via=0; via<n; via++){
        for(int u=0; u<n; u++){
            for(int v=0; v<n; v++){
                dist[u][v] = min(dist[u][v], dist[u][via] + dist[via][v]);
            }
        }
    }
}

// DSU

void unionByRank()

void find()


// Prims
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

// Kruskal
    int findParent(int u){
        if(u == parent[u])
            return u;

        return parent[u] = findParent(parent[u]);
    }

    void unionbyRank(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }else if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    int spanningTree(vector<vector<int>> adj[]){
        vector<int> parent(N);
        vector<int>rank(N, 0);

        for(int i=0; i<N; i++){
            parent[i] = i;
        }

        // priority queue {wt, u, v}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                pq.push({adj[i][j][1], {i, adj[i][j][0]}});
            }
        }

        int cost = 0;
        int edges = 0;
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int par = pq.top().second.second;
            pq.pop();

            if(findParent(u) != findParent(v)){
                const += wt;
                unionByRank(u, v);
                edges++;
            }

            if(edges == N-1) break; // optimization
        }
        return cost;
    }

// Top sort | 1.stack 2. kahns 
    stack<int> stk;

    // 1 | stack
    void topSort(int src){
        vis[src] = true;

        for(auto child: g[src]){
            if(vis[src]) continue;
            dfs(child);
        }
        stk.push(child);
    }

    // 2 | kahn's

    // find indegree of all vertex
    for(int i=0; i<N; i++){
        for(auto child: g[i]){
            indegree[child]++;
        }
    }
    // push zero-indegree vertex into queue
    queue<int> q;
    for(int i=0; i<N; i++){
        if(indegree[i] == 0) q.push(i);
    }
    // pop element from queue | decrease indegree of child
    // push zero indegree child after decrease
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto child: g[node]){
            indegree[child]--;
            if(indegree[child] == 0) q.push(child);
        }
    }

// Articulation Point | Tarjan's ((disc[node] <= low[nbr]))
    // single cycle ka part na hole AP (not always) | cycle wala logic nahi use karna hai
    // find bridge | associated nodes are AP (not always)
    const int N = 100;

    int timer = 0;
    int nodes, edges;

    vector<int> disc(nodes, -1);
    vector<int> low(nodes, -1);
    vector<bool> vis(nodes, false);
    vector<bool> ap(nodes, false);

    // articulation point vector eo push kora jaito
        // it will be memory efficient

    vector<int> g[N];
    // dfs to check articulation point
    void dfs(int node, int par){

        vis[node] = true;
        disc[node] = low[node] = timer++;

        for(auto nbr: g[node]){
            if(nbr == par){
                continue;
            }

            if(!vis[nbr]){
                dfs(nbr, node);
                // dfs kore return korar por eta hobe
                low[node] = min(low[node], low[nbr]);

                // check AP
                if(low[nbr] >= disc[node] && par != -1){
                    ap[node] = true;
                }
            }
            else{ // back edge
                low[node] = min(low[node], disc[nbr]); 
            }
        }

        // handling source
        if(parent == -1 && child>1){
            ap[node] = true;
        }
    }

// Bridges | Tarjan's (disc[node] < low[nbr])
    const int N = 100;

    int timer = 0;
    int nodes, edges;

    vector<int> disc(nodes, -1);
    vector<int> low(nodes, -1);
    vector<bool> vis(nodes, false);
    vector<vector<int>> bridge;

    vector<int> g[N];

    // dfs to check articulation point
    void dfs(int node, int par){

        vis[node] = true;
        disc[node] = low[node] = timer++;

        for(auto nbr: g[node]){
            // neighbor == parent | ignore
            if(nbr == par){
                continue;
            }

            if(!vis[nbr]){
                dfs(nbr, node);
                // dfs kore return korar por eta hobe
                low[node] = min(low[node], low[nbr]);

                // check bridge
                if(low[nbr] > disc[node] && par != -1){
                    bridge.push_back({node, nbr});
                }
            }
            // if visited backedge detected | update low[]
            else{ 
                low[node] = min(low[node], disc[nbr]);
                // low[node] = min(low[node], low[nbr]); 
            }
        }

        // handling source
        if(parent == -1 && child>1){
            ap[node] = true;
        }
    }

// Strongly Connected Component 

    // method-1 Kosaraju's | reverse DFS 
        // Get nodes in stack
        // Transpose the graph | Vertex same just edge reversed
        // Do DFS on Transpose graph 

    void topoSort(int curr, vector<bool> &vis, stack<int> &s){
        vis[curr] = true;
        for(int nbr: adj[curr]{
            if(!vis[nbr]) topoSort(nbr, vis, s);
        })
        s.push(curr)
    }

    void dfs(int curr, vector<bool> &vis, vector<vector<int>> &transpose){
        vis[curr] = true;
        cout << curr << " ";

        for(auto child: transpose[curr]){
            if(!vis[child])
                dfs(child, vis, transpose);
        }
    }

    void kosaraju(){
        // step 1 - stack/topsort O(V+E)
        stack<int> s;
        vector<bool> vis(N, false);

        for(int i=0; i<N; i++){
            if(!vis[i])
                topoSort(i, vis, s);
        }
        
        // step 2 - transpose O(V+E)
        vector<vector<int>> transpose(N);
        for(int u=0; u<v; u++){ // u-->v
            vis[u] = false;
            for(int v: g[u])
                transpose[v].push_back(u); // v-->u
        }

        // step 3 - dfs O(V+E)
        while(s.size() > 0){
            int curr = s.top();
            s.pop();

            if(!vis[curr]){
                dfs(curr, vis, transpose); //scc print
                cout << endl;
            }
        }
    }   

    // method-2 Tarjan's
    vector<int> adj[];
    vector<bool> vis(N, 0);
    vector<int> disc(N, 0);
    vector<int> low(N, 0);
    vector<vector<int>> ans;
    int timer = 0;
    stack<int> stk;
    bool inStack[N];

    void dfs(int node){
        vis[node] = 1;
        disc[node] = low[node] = timer;
        stk.push(node);
        inStack[node] = true;

        for(auto nbr: adj[node]){
            if(!vis[nbr]){
                timer++;
                dfs(nbr);
                low[node] = min(low[node], low[nbr]);
            }
            // if visited
            else{
                if(inStack[nbr]){
                    low[node] = min(low[node], disc[nbr])
                }
            }
        }

        if(disc[node] == low[node]){
            vector<int> temp;
            while(!stk.empty()){
                if(stk.top() == node) {
                    temp.push_back(node);
                    inStack[node] = 0;
                    stk.pop();
                    break;
                }
                temp.push_back(s.top());
                inStack[s.top()] = 0;
                s.pop();
            }

            // sort(temp.begin(), temp.end());
            ans.push_back(temp);
        }
    }

    vector<vector<int>> tarjans(int N, vector<int> adj[]){
        for(int i=0; i<N; i++){
            if(!vis[i]){
                dfs(i);
            }
        }
        return ans;
    }

// euler circuit path

// hamiltonian path
