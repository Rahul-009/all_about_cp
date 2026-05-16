// Trail - A walk in which no E is repeated (V can be repeated) 
// Walk - any random traversal (V and E can be repeated)

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


// Algo O(V+E) 
	// 1. connectivity check | component koyta(dfs)
	// 2. Count odd degree nodes




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
	for(int i=0;i<V;++i)
		if(adj[i].size()>0)
		{
			node = i;	//Found a node to start DFS
			break;
		}
	if(node == -1)	//No start node was found-->No edges are present in graph
		return true; //It's always Eulerian

	DFS(node,visited);
	//Check if all the non-zero vertices are visited
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