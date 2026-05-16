// Tree
	// n nodes
	// n-1 edges
	// no cycle
	// one unique path for each node

// Difference between tree and graph
	//tree has unique path to all nodes | graph doesnt
	//no cycle in tree | easy to avoid infinite loop

// Tree te Graph er DFS kaaj korbe 
	// But tree te visited array er dorkar nai
	// visited array lage jeno parent node e abar na jay | otherwise loop e pore jabe

// height - node to root (maximum)
// depth == shortest distance == BFS == level == root to node

// leaf er height 0 | root er depth 0
// root theke niche namar somoy +1 kore depth pabo
// leaf theke upore uthar somoy +1 kore max niye height pabo

// diameter - longest path length 
	// find the farthest node from any node(BFS) | this must be one endpoint of diameter
	// BFS from that endpoint | done

// Rooting a tree
	// root ulta palta select korle tree balanced hoy na | complexity bere jay
	// ejonno center node ke root banate hobe

// Center of a tree
	// tree can have multiple center
	// 1. The center is always the middle or middle 2 nodes in every longest path
	// 2. remove all leaf node iteratively | last e jeta baki thakbe oitai center
		// compute the degree | remove degree 1 nodes | update degree of the others
		// Observation shobcheye beshi degree je node er oita center

// Isomorphic Tree
	// Probabilistic (hashing/heuristic based) algorithms
		// prone to error due to hashing collision 
	// Unique encoding algorithms 
		// AHU algorithm - represent a tree as a unique string
		// able to capture tree's degree spectrum

// Concept**
	// stretch diameter and check the subtrees | stretch korle subtree height er ekta pattern pawa jay
	// i and n-i node er height maximum i hote parbe
	// this will help to visualize subtrees

	
// Isomorphism

// Euler tour
// Binary lifting

// Network
	// network is represented by a weighted direct graph(arc)
		// nodes = stations/blocks
		// edges = lines (weights = capacity)
	// Capacity is the amount of flow possible
	
	// Source(Entry Block) - Contain one & only node which has no incoming edge
	// Sink/Destination(Exit Block ) - Contain one & only node which has no outgoing edge

// Flow 
	// flow = amount of water flow through pipe | number of car can road can sustain
	// the bottleneck value | the highest value a network can withstand

	// 0 <= flow <= capacity
	// incoming flow = outgoing flow
	// flow = 0 | source ar sink er khetre
	
	// value of flow = source out flow = sink in flow


// Practise Problems -
	// https://codeforces.com/gym/102694
		// A - find the diameter
		// B - find all the endpoints of diameter
		// C - distance from a to b | lca | go up the tree | do down the tree**


	// https://vjudge.net/contest/547647 (codeforces problems)
	

// Basic tree code
	// recursively go to all node
	// check if the node is leaf ? base case
	// do stuff.. 


	vector<int> g[N];
	void dfs(int vertex, int par){
		//action on vertex after enter

		for(auto child: g[vertex]){
			if(child == par) continue;
			// action on child before enter
			dfs(child, vertex);
			// action on child after exit
		}

		//action on node before exit
	}

	int main(){

		// tree input
		int n; cin >> n; // n number of nodes
		for(int i=0; i<n-1; i++){
			int x, y; cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}

	}

// calculate depth and height
	const int N = 1e5+10;
	vector<int> g[N];
	int height[N], depth[N];

	void dfs(int vertex, int par){

	    for(auto child: g[vertex]){
	        if(child == par) continue;
	        depth[child] = depth[vertex] + 1;
	        dfs(child, vertex);
	        height[vertex] = max(height[vertex], height[child]+1);
	    }
	}

	
	// another way to calculate depth
	void dfs(int vertex, int par){
		depth[vertex] = depth[par] + 1;

	    for(auto child: g[vertex]){
	        if(child == par) continue;
	        dfs(child, vertex);
	    }
	}


// pre computation using DFS | subtree problem e lage
	// subtree operation leaf theke upore jawar somoy kora lage

	const int N = 1e5+10;

	// will be given
	vector<int> g[N];
	int val[N]; 

	// sum ar even node er cnt age theke ber kore store korbo
	// O(1) e query answer dibo
	int subtreeSum[N];
	int even_cnt[N];

	void dfs(int vertex, int par){
	    
	    subtreeSum[vertex] += vertex; // val deya thakle val[vertex]
	    if(vertex%2 == 0) even_cnt[vertex]++;

	    for(int child: g[vertex]){

	        if(child == par) continue;
	        dfs(child, vertex);
	        
	        subtreeSum[vertex] += subtreeSum[child];
	        even_cnt[vertex] += even_cnt[child];
	    }
	}


// calculate subtree size
	// 1 2 0 3 4
	// sub[1] = 4
	// sub[2] = 3
	// sub[3] = 1 , sub[4] = 1

	// root must be defined | root er upor depend kore size change hote pare

	vector<int> sub_size(N, 0);
	int dfs(int node){
		vis[node] = 1;
		int curr_sz = 1;

		for(auto nbr: g[node]){
			if(!vis[nbr])
				curr_sz += dfs(nbr);
		}

		sub_size[node] = curr_sz;
		return curr_sz;
	}


// diameter
	// find max depth node with any node as root | that node must be a end point of the diameter
	// now find depth of that node using dfs | done that's ans

	// dfs is same as depth calculation example
	int main(){
    fast_io;    

    int n; cin >> n; // n number of edges
    for(int i=0; i<n; i++){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, -1);
    int mx_depth = -1;
    int mx_depth_node;

    // for finding the max depth node
    for(int i=1; i<=n; i++){
        if(mx_depth < depth[i]){
            mx_depth = depth[i];
            mx_depth_node = i;
        }
    }

    // for finding the diameter
    dfs(mx_depth_node, -1);
    mx_depth = -1;
    for(int i=1; i<=n; i++){
        if(mx_depth < depth[i]){
            mx_depth = depth[i];
        }
    }
    cout << mx_depth << endl;
}



// lowest common ancestor

	// Method - 1 : Using path
		// dfs chalaye shobar parent store korbo
		// root theke path store korbo 2ta node er jonno
		// then loop chalaye compare korbo (main er vitore)

	void dfs(int vertex, int p = -1){
	    par[vertex] = p;

	    for(auto child: g[vertex]){

	        if(child == p) continue;
	        dfs(child, vertex);
	      
	    }
	}

	vector<int> path(int v){
	    vector<int> ans;
	    while(v != -1){
	        ans.push_back(v);
	        v = par[v];
	    }
	    reverse(ans.begin(), ans.end());
	    return ans;
	}
	int main(){
	    fast_io;    

	    int n; cin >> n; 
	    for(int i=0; i<n-1; i++){
	        int x, y; cin >> x >> y; 
	        g[x].push_back(y);
	        g[y].push_back(x);
	    }

	    dfs(1);

	    int x, y; cin >> x >> y;
	    vector<int> path_x = path(x);
	    vector<int> path_y = path(y);

	    int mn_ln = min(path_x.size(), path_y.size());
	    int lca = -1;

	    for(int i=0; i<mn_ln; i++){
	        if(path_x[i] == path_y[i]){
	            lca = path_x[i];
	        }
	    }
	    cout << lca << endl;
	}


	// Method-2 : Using Binary Lifting O(logn)
		// https://www.youtube.com/watch?v=02zM-QoKoPg&ab_channel=FluentAlgorithms

	const int N = 1e5;
	vector<int> tree[N];
	vector<int> depth(N, 0);

	// dp array te 1, 2, 4 ... jump dile kothay jabe precalc kore rakhbo
	int dp[N][Logn];


	// A-B-C  |  Here 0 means 2^0 and 1(2^1) | i(2^i)
	// dp[A][0] = B
	// dp[A][1] = dp[B][0] = C

	// So,  dp[A][1] = dp[dp[A][0]][0] 

	// dfs is only for initializing dp array
	void dfs(int root, int par){

		// setting the dp array for root
		dp[root][0] = par;
		for(int i=1; i<Logn; i++){
			dp[root][i] = dp[dp[root][i-1]][i-1];
		}

		// now move to the child
		for(auto child: tree[u]){
			if(child == par) continue;
			depth[child] = depth[root] + 1;
			dfs(child, root);
		}
	}


	// u must be deeper than v
	int lca(int u, int v){
		if(depth[u] < depth[v]){
			swap(u, v);
		}

		int diff = depth[u] - depth[v];

		// diff = 0101 | chck bit | if bit = 1 jump
		// By doing this depth of u, v will be same
		for(int i=0; i<Logn; i++){
			if((1<<i) & diff){
				u = dp[u][i];
			}
		}
		if(u==v){
			return u;
		}

		// lca er upore chole gele dp[u], dp[v] equal hoye jabe
		// amra iteration lca er immediate child e stop kore dibo
		for(int i=Logn-1; i>=0; i--){
			if(dp[u][i] != dp[v][i]){
				u = dp[u][i];
				v = dp[v][i];
			}
		}

		// lca = jekhane stop korsi | oitar 1 step uporer ta
		return dp[u][0];
	}

	// Method-3 : Binary search O(logn^2)
		// u, v level same kore dibo
		// lca dist  - at least 1 , at most depth[u]
		// 1 theke depth[u]  range e bin search

		int lift(int node, int jump){
			for(int i=Logn; i>=0; i--){
				if(jump == 0 || node == -1)
					break;

				if(jump >= (1<<i)){
					jump -= (1<<i);
					node = dp[node][i];
				}
			}
			return node;
		}

		int lca(int u, int v){
			if(depth[u] < depth[v]){
				swap(u, v);
			}

			u = lift(u, lvl[u]-lvl[v]);

			int lo = 0, hi = depth[u];

			while(lo != hi){
				int mid = (lo+hi)/2;
				int x1 = lift(u, mid);
				int x2 = lift(v, mid);
				if(x1 == x2)
					hi  = mid;
				else
					lo = mid+1;
			}

			return lift(u, lo);
		}


// DP on tree references
	// https://www.youtube.com/playlist?list=PLb3g_Z8nEv1j_BC-fmZWHFe6jmU_zv-8s


// Range update/query on Tree
	// Method-1 : Segment Tree
	// segment tree sudhu Linear structure / array te kaaj kore
	// tree te segment tree er subidha nite Linear banate hobe
	// Use Eular Tour / HLD to make a tree Linear

	// Method-2 : Centroid Decomposition

// Eular tour O(logn)
	// subtree query problem e lage
	// precompute/dp diyeo query answer kora jay | but update handle kora jay na

	// algo -
		// start time , end time store korbo

	const int N = 1e5;
	vector<int> tree[N];

	vector<int> linear(2*N);
	vector<int> start(N);
	vector<int> finish(N);
		
	int t = 0;

	// variation 1 : start and end time alada
		// linear array size 2*n | shob element 2 bar store hobe
		// 1st instance - last instance range e shob subtree nodes thakbe

	void dfs(int source, int par=-1){
		start[source] = t;
		linear[t++] = source;

		for(auto child: tree[source]){
			// cout << child << endl;
			if(child == par) continue;
			dfs(child, source);
		}

		finish[source] = t;
		linear[t++] = source;
	}

	// variation 2 : start and end time same(not truely)
		// linear array size n | one instance for all node
		//
	void dfs(int source, int par=-1){
		start[source] = t;
		linear[t++] = source;

		for(auto child: tree[source]){
			// cout << child << endl;
			if(child == par) continue;
			dfs(child, source);
		}

		finish[source] = t;
	}

// HLD O(logn^2)
	// path query te lage | binary lifting diye solve kora jay
	// but again update handle korte pare na

// Eular tour + HLD
	

//Ford-Fulkerson method
	// repeatedly finds augmenting path of flow through the residual graph
	// augmenting path = path of edges with unused capacity greater than zero
	// each node holds info of flow/capacity (6/25)
	// residual graph holds residual edges
	// residual edges = ulta edge | ulta edge gulao flow/capacity store kore (-6/0)
	
	// Time complexity depends on algorithm | there are several
		// Only DFS O(flow*edges) Dumb
		// Edmonds-Karp - uses BFS
		// Capacity Scalling - picks larger path first
		// Dinic's algorithm - use DFS+BFS
		// Push Relabel - Uses a concept of maintaining "preflow"