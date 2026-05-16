// floyd warshall 
    // multi source all pair shortest path
    // can handle negative weight
    // can't handle negative cycle
        // why | cause distance komtei thake continuously | fixed point reach kora jay na

    // dynamic programming approach | memoization
    // need adjacency matrix

    // works both for directed and undirected | weighted and unweighted
    // k node allow kore shortest path ber korbo | k barate thakbe
    // eksomoy dekhbo k baraleo shortest path change hoche na | then we will stop
    

// algo - O(V^3)
    // calculate dist of one node via all node
    // all node theke to 1 step e dest e jawa jay na
    // dist pre calculate kora thakbe dp[][] te | 1 step e extract kore nibo
    
    // dp array er diagonal always 0 | cause 0,0 1,1 2,2 egula ja ase tai
    // via node er row and column ager iteration er same thakbe | no change
    // 0 - 3 via 1 | row 1 and col 1 calculate korleo change hobe na
    
    // 0-3 via 1 | dp[0][3] = dp[0][1] + dp[1][3]


// Handling Negative edge-
    // dist[i][k] or dist[j][k] jekono ekta INF mane path exist kore na
    // but negative cycle thakle oita INF theke choto hoye jabe 
    // and oitake valid path dhore code run hobe

// detecting negative cycle
    // if dist is <0 for any node that has negative cycle
    // if negative cycle found | stop | we will never get correct result
    // after floyd warshall done, check if any value is <0 or not

    const int N = 510;
    const int INF = 1e9 + 10;
    int dist[N][N];

    int main(){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(i == j) dist[i][j] = 0;
                else dist[i][j] = INF;
            }
        }

        int n, m; cin >> n >> m;
        for(int i=0; i<m; i++){
            int x, y, wt; cin >> x >> y >> wt;
            dist[x][y] = wt;
        }

        // floyd warshall
            // for each via update all cell of the matrix
            // that means visit all possible i-j via one node then another then another ..
        for(int via=1; via<=n; via++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][via]+dist[via][j]);
                }
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][j] == INF){
                    cout << "I ";
                }else{
                    cout << dist[i][j] << " ";
                }
            }
            cout << endl;
        }
    }

// Handling negative edge 
    // dist[i][k] or dist[j][k] jekono ekta INF mane path exist kore na
    // but negative cycle thakle oita INF theke choto hoye jabe 
    // and oitake valid path dhore code run hobe

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                // this check is needed for negative edge
                if(dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
   }


// Practice problems -
    // https://codeforces.com/problemset/problem/295/B
    // cp-algorithm

// Solution of 1
   // normally ekta ekta kore include kore path calculate kori
   // but ekhane bolse ekta ekta kore remove kore path ber korte

   // so amra jei order e remove korte bolse oitar ulta side theke add korbo
   // **think** - ulta side theke add kore calculate korle ultimately ans peye jabo

    const int N = 510;
    const int INF = 1e9 + 10;
    ll dist[N][N];

    int main(){
        int n; cin >> n;
        for(int i=1; i<=n; i++){
            for(int j=0; j<=n; j++){
                cin >> dist[i][j];
            }
        }
        vector<int> del_order(n);
        for(int i=0; i<n; i++){
            cin >> del_order[i];
        }
        reverse(del_order.begin(), del_order.end());
        vector<ll> ans;
        // 0 means level 1 | karon 0 mane del_oreder[0] niye distance
        for(int k=0; k<n; k++){
            int k_v = del_order[k];
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    ll new_dist = dist[i][k_v] + dist[k_v][j];
                    dist[i][j] = min(dist[i][j], new_dist);
                }
            }
            ll sum = 0;
            for(int i=0; i<=k; i++){
                for(int j = 0; j<=k; j++){
                    sum += dist[del_order[i]][del_order[j]];
                }
            }
            ans.push_back(sum);
        }
        
        reverse(ans.begin(), ans.end());
        for(auto val: ans){
            cout << val <<endl;
        }
    }

// References -
    // take u forward - https://www.youtube.com/watch?v=YbY8cVwWAvw&ab_channel=takeUforward
    // luv