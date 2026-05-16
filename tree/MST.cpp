// minimum spanning tree O(nlogn)
    // 1. Prim's algorithm
    // spanning means all nodes are connected
    // minimum means sum of weights is minimum

    #include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> result;
unordered_map<int, vector<pair<int, int>>> graph;
// keynode1 |  {node, wt}, {node2, wt}, {node3, wt}
    // keynode2 |  {node, wt}, {node2, wt}, {node3, wt}
    // keynode3 |  {node, wt}, {node2, wt}, {node3, wt}

int main(){

    int nodes, edges; cin >> nodes >> edges;
    int n = nodes;
    int m = edges;

    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<int> key(n);
    vector<bool> mst(n);
    vector<int> parent(n);

    for(int i=0; i<n; i++){
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int i=1; i<n; i++){
        int mini = INT_MAX;
        int u;

        for(int j = 0; j<n; j++){
            if(mst[j] == false && key[j] < mini){
                u = j;
                mini = key[j];
            }
        }

        mst[u] = true;

        for(auto it: graph[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v] == false && w < key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    // printing the answer
    for(int i=1; i<n; i++){
        result.push_back({{parent[i], i}, key[i]});
    }

    cout << endl;
    for(int i=0; i<n-1; i++){
        cout << result[i].first.first << " "
        << result[i].first.second << " "
        << result[i].second << endl;
    }

}
    


// 2. Kruskal algorithm
    // choto edge gula add kora shuru korbo
    // jei edge add korle tree e cycle create hote pare oita skip korbo
    // jokhon shob node connect hoye jabe tokhon extra edge thakleo add korbo na

    // But how to check if it creates loop or not
    // Using DSU - almost O(1) e jante parbo 2ta node same component er part naki
    // only 2ta alada component er node connect kora jabe
        
        // graph er shob node niye DSU banabo
        // shobai nijei nijer parent hobe
        // tarpor ekta ekta kore add korbo minimum edge gula nibo

    const int N = 1e5+10;
    int parent[N];
    int sz[N];

    void make(int v){
        parent[v] = v;
        sz[v] = 1;
    }

    int find(int v){
        if(parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }

    void Union(int a, int b){
        a = find(a);
        b = find(b);

        if(a != b){
            if(sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        } 
    }

    int main(){
        int n, m; cin >> n >> m;
        vector<pair<int, pair<int, int>>> edges;
        for(int i=0; i<m; i++){
            int u, v, wt;
            cin >> u >> v >> wt;
            edges.push_back({wt, {u, v}});
        }
        sort(edges.begin(), edges.end());

        for(int i=1; i<=n; i++) make(i);

        int total_cost = 0;
        for(auto &edge: edges){
            int wt = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            if(find(u) == find(v)) continue;
            Union(u, v);
            total_cost += wt;
            cout << u << " " << v << endl;
        }
        cout << total_cost << endl;
    }