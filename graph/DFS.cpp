// DFS O(V+E)
	void dfs(int n){
		//action after entering node

		if(vis[n]) return;
		vis[n] = true;

		for(int i=0; i<adj[n].size(); i++){
			// action on child before enter
			dfs(adj[n][i]);
			// action on child after exit
		}

		//action on node before exit
	}

// better dfs
	void dfs(int n, int p){
		vis[n] = true;

		// cout << n << " " << p << endl;
		for(int i=0; i<adj[n].size(); i++){
			if(vis[adj[n][i]] && adj[n][i] == p) continue;
			if(vis[adj[n][i]]) return;

			dfs(adj[n][i], n);
		}
	}


// connected component O(V+E)
	// ekta node theke onno shob node e jawa gele oi nodegula connected component
	// shob node er jonno dfs chalabo | ekbar jegula visited hoye jabe oigular jonno 2nd time dfs cholbe na
	// total jotobar dfs cholbe totogula connected component

	// main er vitore | done | dfs e no change
	int cnt = 0; // ans
	for(int i=1; i<=n; i++){
		if(vis[i]) continue;
		dfs(i);
		cnt++;
	}

	// store all connected componenets
	void dfs(int v){
		vis[v] = true;
		current_cc.push_back(v); // vertex dhuklei store korbo
		for(auto child: g[v]){
			if(vis[child]) continue;
			dfs(child);
		}
	}

	vector<vector<int>> cc;
	vector<int> current_cc;

	for(int i=1; i<=n; i++){
		if(vis[i]) continue;
		current_cc.clear(); // current path khali korbo
		dfs(i);
		cc.push_back(current_cc); //vector push in vector
		cnt++;
	}


//Bipartite graph / bicoloring
    // all nodes will be divided into 2 sets
    // same set nodes cannot have edges between them
    // we will determine it by graph coloring
    // no adjacent two node can have same color

	queue<int> q;
	vector<int> adj[N];
	vector<int> color(N);

	bool is_bipartite(int n){
		q.push(n);
		color[n] = 1;
		while(!q.empty()){
			int v = q.front();
			q.pop();
			for(auto u: adj[v]){

				if(color[u]!=0 && color[v] == color[u]){
					return false;
				}
				if(!color[u]){
					q.push(u);
					if(color[v] == 1)
						color[u] = 2;
					else if(color[v]==2)
						color[u] = 1;
				}
			}
		}
		return true;	
	}
	
	// using DFS
	const int N = 100;
	vector<int> g[N];
	vector<int> vis(N, 0);
	vector<int> color(N, -1);

	bool dfs_bipartite(int node, int c){

	    vis[node] = 1;
	    color[node] = c;

	    for(auto nbr: g[node]){
	        if(!vis[nbr]){
	            // xor kore bit flip kortesi
	            // not use koreo kora jabe
	            if(dfs(nbr, c^1) == false)
	                return false;
	        }
	        else{
	            if(color[node] == color[child])
	                return false;
	        }
	    }

	    return true;
	}

	//Practise problems-
		 // https://www.spoj.com/problems/BUGLIFE/


// Cycle Detection
	// explanation 1
		// age visited amon node e gelei cycle exist
		// problem parent to visited | amra parent e child theke 2nd time visit kori !!
		// ejonno parent track rakha lagbe
		// So (node visted && not parent) hole cycle

	// explanation 2
		// If we can detect backedge we can say backedge is present

	// approach
		// we will search for backedge
		// we pass extra argument parent
		// if a node is visited and not parent that's backedge

	// code 1
	bool isCycle(int v, int p){
		vis[v] = true;
		bool isLoopExists = false;
		for(auto child : g[v]){

			if(vis[child] && child == p) continue;
			if(vis[child]) return true;

			isLoopExists |= isCycle(child, v);
		}

		return isLoopExists;
	}
	
	// code 2
	bool dfs_cycle(int node, int p){
	    vis[node] = 1;

	    for(auto nbr: g[node]){
	        if(!vis[nbr]){
	            if(dfs(nbr, node) == true) return true;
	        }
	        else
	            if(nbr != par) return true;
	    }

	    return false;
	}


// in out time of nodes
	//also called discovery time / leaving time
	// in time will be higher than parent
	// out time will be lower than parent 
	// we can say from this if a node is in the subtree of another node or not

	int timer;
	vector<int> in(n, -1);
	vector<int> out(n, -1);

	bool dfs(int node){
	    vis[node] = true;
	    in[node] = timer++;

	    for(auto nbr: g[node]){
	        if(!vis[nbr])
	            dfs(nbr);
	    }
	    out[node] = timer++;
	}

	// Practise Problems - (not related to in/out time)
		// https://www.codechef.com/problems/FIRESC

// bridge and ap basic - https://www.youtube.com/watch?v=sqYozZ2Y_cM&ab_channel=KartikArora

// Bridges
	// je edge delete korle graph multiple component e divide hoye jay
    // connected component will increase

    // Bruteforce O(V*(V+E))
    	// traverse all edge , remove , check connected component


    	//backedge - child node jodi age thekei visted thake
    			// and parent na hoy
    	//backedge thakle - low[node] = min(low[node], disc[nbr]);

    	// if nbr==parent skip

    	// jodi child low change hoye jay tahole parent low update korte hobe
    		// low[node] = min(low[node], low[child]);

    	// check ap or not
    		// low[nbr] > disc[node] ? bridge found
    		// the condition means node theke nbr e jawar ektai rasta ache | condition of bridge


    	// timer variable rakhbo time track rakhar jonno
    	// disc[] - tracks discovery time
    	// low[] - lowest level connection

    const int N= 100;

    int timer;
    int nodes, edges; 

    vector<int> disc(N, -1);
    vector<int> low(N, -1);
    vector<bool> vis(N, false);
    vector<int> g[N];

    vector<pair<int, int>> bridges;

    void dfs(int node, int par){

        vis[node] = true;
        disc[node] = low[node] = timer++;

        for(auto nbr: g[node]){
            if(nbr == par) continue;

            if(!vis[nbr]){
                dfs(nbr, node);
                low[node] = min(low[node], low[nbr]);

                // check bridge
                if(low[nbr] > disc[node]){
                    pair<int, int> p;
                    p = {node, nbr};

                    bridges.push_back(p);
                }
            }
            else {
                // back edge
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }

    int main(){

        cin >> nodes >> edges;

        for(int i=0; i<edges; i++){
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        for(int i=0; i<v; i++){
            if(!vis[i])
                dfs()
        }

        // finally print bridges
    }

	
// bridges and AP can be found using same code
	// the endpoint of bridges ar AP
	// just insert the endpoints of bridges in a set

	// But there is a problem
	// AP can exist without bridges 
	// so bridge code must be modified

// articulation point
	// also called Cut vertex

	// je node delete korle graph 2 ta component e divide hoye jay
	
	// Bruteforce  O(V*(V+E))
		// remove all node one by one and check component
	
	
	// Tarjan's Algorithm O(V+E)
		// u is the root of the DFS tree and it has at least two children. 
		// bridge check was low[nbr] > low[node]
    	// Ap check is low[nbr] >= low[node]

    	// source must be handled specially

		// 4ta array maintain korte hobe
		// visited[] - bool
		// parent[] - array charao track rakha jabe
		// disc[] - minimum discovery time track rakhar jonno
		// low[] - lowest level connection

		

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
        parent[node] = par;
        int child  = 0;

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

                child++; 
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


    int main(){

        cin >> nodes >> edges;
        
        // input graph

        // dfs on all unvisited node
        for(int i=0; i<nodes; i++){
            if(!vis[i]){
                dfs()
            }
        }

        // print all articulation point
        for(int i=0; i<ap.size(); i++){
            if(ap[i]) cout << i << endl;
        }
    }


// Matrix problems using DFS
	// problems - 
		// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
		// https://leetcode.com/problems/pacific-atlantic-water-flow/
		// https://leetcode.com/problems/island-perimeter
		// https://leetcode.com/problems/flood-fill
		// https://leetcode.com/problems/number-of-islands/

	// 1 1 1
	// 1 1 0
	// 1 0 1


    // dfs(int i, int j) | dfs er parameter hobe row, column 
	// erokom matrix deya thake and relation deya thakbe
	//  + relation | diagonal relation | surrounded relation
	// upor, nich, left, right | konakoni | 4 pasher 8 tai 

	// relation er upor base kore ekta graph create kore nibo

	// visited array use kori nai | question wise logic set kore dibo

	// solution of flood fill 
	// i = source row | j = source column



	void dfs(int i, int j, int initColor, int newColor, vector<vector<int>> &image){
		int n = image.size();
		int m = image[0].size();
		if(i < 0 || j<0) return;
		if(i>=n || j>=n) return;
		if(image[i][j] != initColor) return;

		image[i][j] = newColor;

		// dfs calls  depend on relation
			dfs(i-1, j, initColor, newColor, image);
			dfs(i+1, j, initColor, newColor, image);
			dfs(i, j-1, initColor, newColor, image);
			dfs(i, j+1, initColor, newColor, image);
	}

	vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor){
		int initColor = image[sr][sc];
		if(initColor != newColor){
			dfs(sr, sc, initColor, newColor, image);
		}
		return image;
	}






// Edge Deletion problem
    // ekta edge delete korle 2 tree hoye jabe

    // delete edge so that the sum of tree is as large as possible
    // reference problem - https://www.interviewbit.com/problems/delete-edge/
    const int N = 1e5+10;
	const int M = 1e9 + 7;
	vector<int> g[N];
	int vis[N];

	int val[N];
	int subtree_sum[N];
    void dfs(int v){
        subtree_sum[v] += val[v];
        for(auto child: g[v]){

            if(vis[child]) continue;
            dfs(child);
            subtree_sum[v] += subtree_sum[child]; 
        }
    }
    int main(){

        fast_io;

        int n, e; cin >> n >> e;

        for(int i=0; i<e; i++){
            int x, y; cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(1);
        ll ans = 0;

        // shob edge delete kore check korbo
        // 1(root) theke chalale tree divide hobe na | ejonno loop 2 theke chalate hobe
        for(int i=2; i<=n; i++){
            int part1 = subtree_sum[i];
            int part2 = subtree_sum[1] - part1;
            ans = max(ans, (part1 * 1LL * part2) % M );
        }
    }        

    // delete edge and maximize prime numbers
        // dfs chalao | prime node e 0, 1 store koro | use sieve if needed
        // precalculate subtreesum of 0,1  | so that kon dike prime beshi root thekei bojha jay
