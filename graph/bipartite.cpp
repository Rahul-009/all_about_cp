// Divide Graph in 2 sets
// Even cycle thakle bipartite | Odd cycle thakle not bipartite
// 2-coloring algorithm

// cancer detection, recommendation system
// Stable Marriage Problem


// using BFS
bool bipartite(int src){
    queue<int> q;
    vector<bool> color(N, -1);

    q.push(src);
    color[src] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto child: g[src]){
            // color not assigned to them
            if(color[child] == -1){
                color[child] = (color[node] + 1); // | in bool 2 means 0
                q.push(child);
            }
            // color is already assigned
            else{
                if(color[child] == color[node]) return false;
            }
        }
    }
    return true;
}

// using DFS
vector<int> color(N, -1);

bool isBipartite(int src){
    color[src] = 0;
    for(auto child: g[src]){
        if(color[child] == -1){
            color[child] = color[node] + 1;
            if(!isBipartite(child)) return false;
        }else{
            if(color[node] == color[child]) return false;
        }
    }
    return true;
}