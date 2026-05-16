// Bellman Ford
	// Big brother of Dijsktra

// Single source all pair shortest path
// can handle negative weight | dijsktra can't
// can detect negative cycle

// Reference - https://www.youtube.com/watch?v=ijpVpsmpJtQ&ab_channel=CodeHelp-byBabbar

// algo - O(VE) = O(n^2)
	// n-1 (n == node)bar path relaxation korbo
	// n-1 er por final val pabo | then ar update howar kotha na
	// n-th bar relax kore value update hole negative cycle present
	// parent_dist + child_wt < child_dist | update child_dist
	// optimization | parent_dist == INF kina eta check korte hobe | INF hole relax kore labh nai




#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

const int INF = 1e9;

int bellman(int n, int m, int src, int dest, vector<vector<int>> &edges){
	vector<int> dist(n+1, INF);
	dist[src] = 0;

	// 0 theke <n-1
	for(int i=0; i<n-1; i++){
		for(int j=0; j<=m; j++){
			int u = edges[j][0];
			int v = edges[j][1];
			int wt = edges[j][2];

			if(dist[u] != INF && (dist[u]+wt < dist[v] )){
				dist[v] = dist[u] + wt;
			}
		}

	}

	// check for negative cycle
	bool flag = 0;
	for(int j=0; j<=m; j++){
		int u = edges[j][0];
		int v = edges[j][1];
		int wt = edges[j][2];

		if(dist[u] != INF && (dist[i]+wt < dist[v] )){
			flag = 1;
			break;
		}
	}

}

int main(){

	fast_io;


}