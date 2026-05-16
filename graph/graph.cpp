// References-
	// william fiset - https://youtube.com/playlist?list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P
	// luv youtube
	// love babbar

/*
storing graph
	unweighted graph always adj list

	// vector of vector
	vector<vector>
	
	weighted graph kom weight adj list of pairs
	too many weights | store int matrix

DFS
	connected components
	bipartite graph | cycle detection
	
	In/out graph time of nodes
	graph matrix problems
	calculating subtree size

DFS on tree
	single source shortest path using DFS
	Lowest common ancestor
	height, depth, diameter | longest path in tree
	pre computation | sum, cnt
	subtree and edge deletion

BFS - single source one pair shortest path

0-1 BFS - tricky dfs

Multi source BFS

dijsktra - single source all pair shortest path
	// can handle only positive weight

Bellman ford - single source all pair shortest path
	// can handle negative weight
	// can detect negative cycle

floyd warshall - multi source all pair shortest path

*/


/*

// Isomorphic graph
	// G1 and G2 isomorphic ? means whether they are structurally same or not
	// Isomorphism is hard for graph
	// there are some defined algo for tree isomorphism

Backedge - edge that connects a node with ancestor which is not it's parent
	
Graph Disconnect
	1. Articulation Point 
	2. Bridges
 
DAG - Directed Acyclic Graph

Trail - A walk in which no E is repeated (V can be repeated) 
Walk - any random traversal (V and E can be repeated)

Eular Circuit - A trail that starts and ends at same node
	 
Eular Graph-
	A graph which has a eular circuit
	All edges in a graph must be present in a single component
	All other components should not have any edge and hence should be of size 1 vertex only
	All vertices should have even degree

Semi-Eulerian graph
	Every edge is visited once
	start node != end node
		exactly 2 vertices must have odd degree(start & end)


*/


// Representation

	//1. unordered_map (memory efficient)
		// jeshob node er edge nai oigula store hobe na
	

	int nodes; cin >> nodes;
    int edges; cin >> edges;
    unordered_map<int, vector<int>> adj;

    for(int i=0; i<edges; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // print all edges
    for(auto x: adj){
        cout <<  x.first << " ";
        for(int i=0; i<x.second.size(); i++){
            cout <<  x.second[i] << " ";
        }
        cout << endl;
    }

    // 2nd step
    unordered_map<int, vector<pair<int, int>>> graph;
	unordered_map<int, int> dist;
	unordered_map<int, bool> vis;

	int main(){

		int n, e, wt; cin >> n >> e;

		for(int i=0; i<e; i++){
			int u, v; cin >> u >> v >> wt;
			graph[u].push_back({v, wt});
		}

		for(auto node: graph){
			cout << node.first << endl;
			for(auto child: node.second){
				cout << child.first << " " << child.second << endl;
			}
		}
	}

    //2. array of vectors
    	// problem node 0, 1, 2, 3 | sequential hote hobe
    	// jesob node er edge nai orao list e thakbe

    int nodes, edges; cin >> nodes >> edges;

    vector<int> g[nodes];

    for(int i=0; i<edges; i++){
        int u, v;
        cin >> u >> v ;
        g[u].push_back(v);
        g[v].push_back(u);
    } 

    // iterate over adj list
    for(int i=0; i<nodes; i++){
        for(int j=0; j<g[i].size(); j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }


    //3. vector of vector

    //4. 2D array / matrix





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





