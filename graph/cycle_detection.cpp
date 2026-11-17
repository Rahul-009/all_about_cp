// undirected
	// 1. dfs
	bool isCycle_dfs(int src, int par){
		vis[src] = true;
		for(auto child: g[src]){
			if(!vis[child])
				if(isCycle_dfs(child, src))
					return true;
			else{
				if(child == par) continue;
				return true;
			}
		}
		return false;
	}

	bool isCycle_dfs(int src, int par){
		vis[src] = true;
		for(auto child: g[src]){
			if(child == par) continue;
			if(vis[child]) return true;
			if(isCycle_dfs) return true;
		}
		return false;
	}

	bool isCycle = isCycle_dfs(start, -1);

	// 2. bfs
	void isCycle_bfs(int src, int par){
		queue<pair<int, int>> q;

		q.push({src, -1});
		vis[src] = true;

		while(!q.size() > 0){
			int u = q.front().first;
			int parU = q.front().second;
			q.pop();

			for(auto child: g[u]){
				if(child == par) continue;
				if(vis[child]) return true;
				
				vis[child] = true;
				q.push({child, u})
			}
		}
		return false;
	}
	
	// 3. DSU

// directed 
	// 1. dfs | backtrack path
	vector<bool> path(N, 0);
	vector<bool> vis(N, 0);

	bool DetectCycle(int node){
		vis[node] = true;
		path[node] = true;

		for(auto child: g[node]){
			auto [child_wt, child_node] = child;

			// if neighbour is in the path
			if(path[child_node]) return true;

			// if previously checked in another path
			if(vis[child_node]) continue;

			// recursive call
			if(DetectCycle(g[child_node])) return true;
		}

		path[node] = false;
		return false;
	}
	
	// 2. bfs | Kahn's Algo | TopSort
	int indegree[];

	bool kahn(int src){
		for(int u=0; u<N; u++){
			for(int v=0; v<g[i].size(); v++){
				indegree[u][v]++;
			}
		}

		queue<int> q;
		
		for(int i=0; i<N; i++){
			if(indegree[i] == 0) q.push(i);
		}

		vector<int> ans;
		while(!q.empty()){
			int curr_v = q.front();
			q.pop();
			ans.push_back(node);

			for(auto child: g[curr_v]){
				indegree[child]--;
				if(indegree[child] == 0) q.push(child)
			}
		}

		int count = ans.size()

		return count!=N; // count == N ? acyclic : cycle detected
	}













//cycle count and print
	vector<int> adj[N];
	int par[N];
	int color[N];

	vector<vector<int>> cycles;
	int cycle = 0;

	void dfs_cycle(int u, int p){
		cout << u << " " << p << endl;

		if(color[u] == 2) return;

		if(color[u] == 1){
			vector<int> v;
			int curr = p;
			v.pb(curr);

			while(curr != u){
				curr = par[curr];
				v.pb(curr);
			}

			cycles.pb(v);
			return;
		}

		color[u] = 1;
		par[u] = p;

		for(auto child: adj[u]){
			if(child == p) continue;
			dfs_cycle(child, u);
		}

		color[u] = 2;
	}