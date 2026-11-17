// Trail - A walk in which no E is repeated (V can be repeated) 
// Walk - any random traversal (V and E can be repeated)

// Eular Path - A path in a graph that visit every edge exactly once
	// DO not exist in all graph 

// Eular Circuit - A trail that starts and ends at same node
	 
// Eular Graph-
// 	A graph which has a eular circuit
// 	All edges in a graph must be present in a single component
// 	All other components should not have any edge and hence should be of size 1 vertex only
// 	All vertices should have even degree

// Semi-Eulerian graph
// 	Every edge is visited once
// 	start node != end node
// 		exactly 2 vertices must have odd degree(start & end)

// euler is all about edges | ignore vertex | traverse all edge is enough | unvisited vertex is okay
// all edges must be part of a single component or
// all non zero degree nodes should be connected
// zero or two nod can have odd-degree & remaining node should have even degree

// EC exist EP will also exist
// EP exist EC may not exist


// Euler Circuit: 2
	// Calculate the degree of each node
	// All node should have even edge
	// All non-zero degree node should be connected


// Euler Path: 1
	// Calculate the degree of each node
	// zero or two can have odd degree, remaining have even edge
	// All non-zero degree node should be connected


	vector<bool> vis(N, 0);
	void dfs(int src){}

	int euler(){
		// calc degree
		vector<int> deg(V, 0);
		int odd_deg = 0;
		for(int i=0; i<N; i++){
			deg[i] = g[i].size();
			if(deg[i] % 2) odd_deg++;
		}
		if(odd_deg != 2 && odd_deg != 0)
			return 0;

		// dfs
		for(int i=0; i<N; i++){
			if(deg[i]){
				dfs(i);
				break;
			}
		}

		// connectivity check
		for(int i=0; i<N; i++){
			if(!vis[i] && deg[i]) return 0;
		}

		if(odd_deg == 0) return 2; // euler circuit
		return 1; // euler path
	}


	
// Algo O(V+E) 
	// 1. connectivity check | component koyta(dfs)
	// 2. Count odd degree nodes

	// Step 1: start DFS from any non-zero degree node
	//

unordered_map<int,vector<int>> adj;

void DFS(int curr,vector<bool>& visited)
{
	visited[curr]=true;
	for(auto it: adj[curr])
	{
		if(!visited[it])
			DFS(it,visited);
	}
}

bool Connected_Graph()
{
	vector<bool> visited(V+1,false);
	int node = -1;	//Node to start DFS

	// start DFS from any non-zero degree node
	for(int i=0;i<V;++i)
		if(adj[i].size()>0)
		{
			node = i;	//Found a node to start DFS
			break;
		}
	if(node == -1)	//No start node was found-->No edges are present in graph
		return true; //It's always Eulerian

	DFS(node,visited);

	// Check if all the non-zero vertices are visited
	// if any not visited has non zero degree return false
	for(int i=0;i<V;++i)
		if(visited[i]==false and adj[i].size()>0)
			return false;	//We have edges in multi-component
	return true;
}

int find_Euler()
{
	if(!Connected_Graph())	//multi-component edged graph
		return 0;		//All non-zero degree vertices should be connected

	//Count odd-degree vertices
	int odd = 0;
	for(int i=0;i<V;++i)
		if(adj[i].size() & 1)
			odd += 1;

	if(odd > 2)	//Only start and end node can have odd degree
		return 0;

	return (odd==0)?2:1;	//1->Semi-Eulerian...2->Eulerian
}

void findEuler_Path_Cycle()
{
	int ret = find_Euler();
	if(ret==0)
		cout<<"Graph is NOT a Euler graph\n";
	else if(ret==1)
		cout<<"Graph is Semi-Eulerian\n";
	else
		cout<<"Graph is Eulerian (Euler circuit)\n";
}