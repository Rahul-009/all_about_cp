// BFS
/*BFS traverse level by level
	 *BFS is useful for finding the shortest path
	 *the level array stores level of nodes
	 *This level is the shortest path from source */

	// ekta component thakle ekbar bfs call korlei hobe
	// but forest o thakte pare
	// forest er jonno shob component e bfs call korbo

// Basic BFS template O(V+E)
	const int N = 1e5+10;
	vector<int> g[N];
	bool vis[N];

	void bfs(int v){
	    queue<int> q;
	    q.push(v);
	    vis[v] = true;

	    while(!q.empty()){
	        int cur_v = q.front();
	        q.pop();

	        for(auto child: g[cur_v]){
	            if(vis[child]) continue;
	            
	            q.push(child);
	            vis[child] = true;
	      
	        }
	    }
	}

// BFS without visited array
	// level will be used to stop repeated visit



// calculating level
	int level[N];
	void bfs(int v){
	    queue<int> q;
	    q.push(v);
	    vis[v] = true;

	    while(!q.empty()){
	        int cur_v = q.front();
	        q.pop();

	        for(auto child: g[cur_v]){
	            if(vis[child]) continue;
	            
	            q.push(child);
	            vis[child] = true;

	            // only one line needed
	            level[child] = level[cur_v] + 1; 
	        }
	    }
	}


// printing traversal sequence
	void bfs(int v){
	    queue<int> q;
	    q.push(v);
	    vis[v] = true;

	    while(!q.empty()){
	        int cur_v = q.front();
	        q.pop();

	        cout << cur_v << " "; 

	        for(auto child: g[cur_v]){
	            if(vis[child]) continue;
	            q.push(child);
	            vis[child] = true;
	        }
	        cout << endl;
	    }
	    cout << endl;
	}

// print the shortest path
	// prothom parent track rakhbo shobar | 2nd time node e jabe na | visited array thanks
	// dest node deya thakle dest node er parent track korbo source porjonto
	// dest node deya na thakle ki korbo??

	const int N = 1e5+10;
	unordered_map<int, vector<int>> graph;
	unordered_map<int, bool> vis;
	unordered_map<int, int> parent;
	unordered_map<int, int> dist;

	void bfs(int source){
	    queue<int> q;
	    // vis.clear();
	    // parent.clear();

	    q.push(source);
	    parent[source] = -1;
	    vis[source] = true;
	    dist[source] = 0;

	    while(!q.empty()){
	        int curr = q.front();
	        q.pop();

	        for(auto child: graph[curr]){
	            if(!vis[child]){
	                vis[child] = true;
	                parent[child] = curr;
	                dist[child] = dist[curr] + 1;
	                q.push(child);
	            }
	        }
	    }
	}


	int main(){

	    fast_io;

	    int nodes, edges; cin >> nodes >> edges;
	    for(int i=0; i<edges; i++){
	        int u, v; cin >> u >> v;
	        graph[v].push_back(u);
	        graph[u].push_back(v);
	    }
	    int source = 1;
	    int dest = 8; // dest na deya thakle ki korbo

	    bfs(source);

	    // build the shortest path array
	    vector<int> ans;
	    int curr = dest;
	    ans.push_back(curr);
	    while(curr != source){
	        curr = parent[curr];
	        ans.push_back(curr);
	    }

	    // ulta order e array te dhukbe
	    reverse(ans.begin(), ans.end());

	    for(auto node: ans){
	        cout << node << endl;
	    }
	}


// spoj nankaj
	// solution process 
	// how to code clean
	// repeatative task create function
	// reapeatative data store first

	const int N = 1e5 + 10;
	const int INF = 1e9 + 10;

	vector<int> g[N];
	bool vis[8][8];
	int level[8][8];

	int getX(string s){
	    return s[0] - 'a';
	}

	int getY(string s){
	    return s[1] - '1'; // careful
	}

	vector<pair<int, int>> movements = {
	    {1, 2}, {1, -2},
	    {-1, 2}, {-1, -2},
	    {2, 1}, {2, -1},
	    {-2, 1}, {-2, -1},
	}; 

	bool isValid(int x, int y){
	    return (x >= 0 && y >= 0 && x < 8 && y < 8);
	}

	int bfs(string src, string dest){
	    int srcX = getX(src);
	    int srcY = getY(src);
	    int destX = getX(dest);
	    int destY = getY(dest);

	    queue<pair<int, int>> q;

	    q.push({srcX, srcY});
	    vis[srcX][srcY] = true;
	    level[srcX][srcY] = 0; // important | don't forget this

	    while(!q.empty()){
	        pair<int, int> v = q.front();
	        int x = v.first, y = v.second;
	        q.pop();
	        
	        for(auto movement : movements){
	            int childX = movement.first + x;
	            int childY = movement.second + y;
	            if(!isValid(childX, childY)) continue;
	            if(vis[childX][childY]) continue;
	               
	                q.push({childX, childY});
	                level[childX][childY] = level[x][y] + 1;
	                vis[childX][childY] = true;
	        }

	        // optimization;
	        if(level[destX][destY] != INF) break;
	    }

	    return level[destX][destY];
	}

	void reset(){
	    for(int i=0; i<8; i++){
	        for(int j=0; j<8; j++){
	            level[i][j] = INF;
	            vis[i][j] = 0;
	        }
	    }
	}

	int main(){
	    fast_io;
	    
	    int n; cin >> n;
	    while(n--){
	        reset();
	        string s1, s2;
	        cin >> s1 >> s2;
	        cout << bfs(s1, s2) << endl;
	    }
	}




// 0-1 bfs

	// edge gular weight 0 and 1
    // 0 wieght er jonno queue er front e push korbo
    // 1 weight er jonno queue er back e push korbo
    // at a certain time queue e 2ta level er node thake

	// basic template
	vector<int> dist(N, INF);
	vector<pair<int, int>> adj[N];
	deque<int> dq;

	void bfs(int s){
		dq.push_back(s);
		dist[s] = 0;

		while(!dq.empty()){
			int v = dq.front();
			dq.pop_front();

			for(auto edge: adj[v]){
				int u = edge.first;
				int wt = edge.second;
				if(dist[v] + wt < dist[u]){
					dist[u] = dist[v] + wt;
					
					if(wt == 1) dq.push_back(u);
					else dq.push_front(u);
				}
			}
		}
	}
    
    // practise problems
		//1. https://www.codechef.com/problems/REVERSE
		//2. https://cp-algorithms.com/graph/01_bfs.html

    // Solution - Chef and reversing (1)
        // let all weights are 0
        // lets assume some reverse edge with weight 1
        // Now calculate shortest path
        // the number of 1 weight edge will be the answer
        
        // each node will be processed 2 times

	const int N = 1e5+10;
	const int INF = 1e9 + 10;

	vector<pair<int, int>> g[N];
	vector<int> lev(N, INF);
	int n, m;

	void bfs(int v){
	    deque<int> dq;
	    dq.push_back(1);
	    lev[1] = 0;

	    while(!dq.empty()){
	        int cur_v = dq.front();
	        dq.pop_front();

	        for(auto child: g[cur_v]){
	            int child_v = child.first;
	            int wt = child.second;

	            if(lev[cur_v]+wt < lev[child_v]){
	                lev[child_v] = lev[cur_v] + 1;
	                
	                if(wt == 1){
	                    dq.push_back(child_v);
	                }else{
	                    dq.push_front(child_v);
	                }
	            }  
	        }
	    }
	}
	int main(){
	    fast_io;
	    int n, e; cin >> n >> e;

	    for(int i=0; i<e; i++){
	        int x, y; cin >> x >> y;
	        g[x].push_back({y, 0});
	        g[y].push_back({x, 1});
	    }
	}

// multi source bfs
    // 1 2 3 4 5 6
    // 1 theke 4 dist choto | naki 2 theke 4 dist choto
    // kon dik diye gele age jawa jabe
    // ei type er problem e multi source bfs kora lage
    
    // shob source first e queue e dhukabo
    // source gulake same level consider korbo

    //code chef : snakes and transition from capitalism to socialism
     
	int val[N][N];
	bool vis[N][N];
	int lev[N][N];
	int n, m;

	vector<pair<int, int>> movements = {
	    {0, 1}, {0, -1}, {1, 0}, {-1, 0},
	    {1, 1}, {-1, -1}, {1, -1}, {-1, 1},
	}

	int bfs(){
	    int mx = 0;
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            max = max(ans, val[i][j]);
	        }
	    }

	    queue<pair<int, int>> q;
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(mx == val[i][j]){
	                q.push({i, j});
	                lev[i][j] = 0;
	                vis[i][j] = true;
	            }
	        }
	    }

	    int ans = 0;
	    while(!q.empty()){
	        auto v = q.front();
	        int v_x = v.first;
	        int v_y = v.second;
	        q.pop();

	        // ekhane for loop diye adjacent 8ta ghor check kortese
	        // vector e pos store na korle 8 bar if else lekha lagto | nasty code
	        for(auto movement: movements){
	            int child_x = movement.first + v_x;
	            int child_y = movement.second + v_y;
	            if(!isValid(child_x, child_y)) continue;
	            if(vis[child_x][child_y]) continue;

	            q.push({child_x, child_y});
	            lev[child_x][child_y] = lev[v_x][v_y] + 1;
	            vis[child_x][child_y] = true;
	            ans = max(ans, lev[child_x][child_y]);
	        }
	    }

	    return ans;
	}

	void reset(){
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            vis[i][j] = 0;
	            lev[i][j] = INF;
	        }
	    }
	}

	int main(){
	    fast_io;

	    int t; cin >> t;
	    while(t--){
	        reset(); // reset vis and lev | important
	        cin >> n >> m;
	        for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                cin >> val[i][j];
	            }
	        }
	        cout << bfs()
	    }
	}