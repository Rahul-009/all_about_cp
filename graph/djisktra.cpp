// djisktra - 
	// weighted graph shortest path
	// single source all pair
	// greedy algorithm
	// can handle cycles , directed , undirected
	// can't handle negative weights
	
	// dijsktra will perfectly work without the visited array

    // jekhane priority queue use kora jay sekhane multiset o use kora jay
    // but ekhane set o use kora jabe
    // karon same jinish duibar ashte pare 
    // normally ekbar process korlei thik answer dey

    // careful** graph e {value, weight} evabe thake
    // set e store kora lagbe {weight, value} evabe
	

	// basic template O(V + Elog(V))
		// set e insert time log(V) | set e vertex rakhbo | so vertex number er upor dependend
		// for loop edge jotogula totobar cholbe | O(Elog(V))
		// while loop per vertex ekbar cholbe | O(V + Elog(V))
	const int N = 1e5+10;
	const int INF = 1e9+10;

	vector<pair<int, int>> g[N];

	void dijsktra(int source){
	    vector<bool> vis(N, false);
	    vector<int> dist(N, INF);

	    set<pair<int, int>> st;
	    st.insert({0, source});

	    while(st.size() > 0){
	        auto node = *st.begin();
	        int curr = node.second;  // st er element{wt, val}
	        int curr_wt = node.first;
	        st.erase(st.begin());

	        if(vis[v]) continue;
	        vis[v] = 1; 
	        for(auto child: g[v]){
	            int child_v = child.first; // graph {val, wt}
	            int wt = child.second;

	            if( dist[v]+wt < dist[child_v] ){
	                dist[child_v] = dist[v] + wt;
	                st.insert({dist[child_v], child_v}); // set {wt, val}
	            }
	        }
	    }
	}

// practice problems
	// https://leetcode.com/problems/network-delay-time/
	// https://cp-algorithms.com/graph/dijkstra.html

	// Solution
	const int N = 1e5+10;
	const int INF = 1e9+10;

	int dijsktra(int source, int n, vector<pair<int, int>> g[]){
	    vector<bool> vis(N, false);
	    vector<int> dist(N, INF);

	    set<pair<int, int>> st;
	    st.insert({0, source});

	    while(st.size() > 0){
	        auto node = *st.begin();
	        int v = node.second;  // st er element{wt, val}
	        int v_dist = node.first;
	        st.erase(st.begin());

	        if(vis[v]) continue;
	        vis[v] = 1; 
	        for(auto child: g[v]){
	            int child_v = child.first; // graph {val, wt}
	            int wt = child.second;

	            if( dist[v]+wt < dist[child_v] ){
	                dist[child_v] = dist[v] + wt;
	                st.insert({dist[child_v], child_v}); // set {wt, val}
	            }
	        }
	    }
	    int ans = 0;
	    for(int i=1; i<=n; i++){
	        if(dist[i] == INF) return -1;
	        ans = max(ans, dist[i]);
	    }
	    return ans;
	}

	int networkDelayTime(vector<vector<int>> &times, int n, int k){
	    vector<pair<int, int>> g[N];
	    for(auto vec: times){
	        g[vec[0]].push_back({vec[1], vec[2]});
	    }
	    return dijsktra(k, n, g)
	}