// Top sort is not unique | there can be several answers
// O(V+E)
// linear ordering of its vertices
// edges must be directed

// Uses -
	// university classes and prerequisites
	// program dependencies
	// To find deadlock in OS

// Works on DAGs only | cannot sort cyclic graph
// By definition every tree has a topological order

// How to detect cycle
	// Tarjan's connected component algorithm


// Method 1 (kahn's algorithm) O(V+E)
	// indegree ber korte hobe shob vertex er
	// print that vertex which has 0 indegree
	

	// Basic code
		// Only works for DAG
		// cycle thakle jhamela korbe
	const int N = 100;

    vector<int> g[N];
    vector<int> result;
    int indegree[N];

    void kahn(int node){
        // stores nodes which has indegree 0
        queue<int> q; 

        for(int i=0; i<n; i++){
            if(in[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int curr = q.front();
            result.push(curr);
            q.pop();

            for(int nbr: g[curr]){
                in[node]--;
                if(in[node] == 0)
                    q.push(nbr);
            }
        }
    }

    // cycle thakle ki korbo?
    	// cycle thakle indegree 0 node paoa jabe na
    	// shob node queue e dhukar agei queue empty hoye loop break hoye jabe
    	// result array er size == nodes ? no cycle : cycle


// Method 2
	// stack and dfs

	

// practise problems
	// https://www.spoj.com/problems/TOPOSORT/  | use priority queue instead queue
	