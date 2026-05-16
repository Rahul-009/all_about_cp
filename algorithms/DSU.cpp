// Disjoint Set Union (DSU)
    // amotorized O(alpha(n)) | alpha() = reverse ackerman function
    // forest type er problem e kaaje lage
    // example - onek manush ase group group e bivokto | oder combine kore calculation kora lagbe
    
     // make - adds new node to a network/forest | independent node banay
    // find - parent of the group    
    // union - a, b ke same group e dhukao
	
	// do path compression in find
	    // shobar parent root banay dibo
	
	// Try iterative approach for find

	// do optimization using size and rank in union
	    // choto tree borotar niche lagay dibo
	

	// Basic template
	int parent[N];
	int size[N];

	void make(int v){
	    parent[v] = v;
	    size[v] = 1;
	}

	int find(int v){
	    if(v == parent[v]) return v;
	    return parent[v] = find(parent[v]); // recursive
	}

	void Union(int a, int b){
	    a = find(a);
	    b = find(b);
	    
	    if( a != b ){
	        if(size[a] < size[b]) swap(a, b);
	        parent[b] = a; // b ke a er niche jora lagay ditesi
	        size[a] += size[b];
	    }
	}

// suppose we have n nodes and k union operation 
// after union how many connected components are present
	// jotogula parent ase totogula component |
	int main(){
	    int n, k;
	    cin >> n >> k;

	    for(int i=1; i<=n; i++){
	        make(i);
	    }
	    while(k--){
	        int u, v; cin >> u >> v;
	        Union(u, v);
	    }

	    int connected_c = 0;
	    for(int i=1; i<=n; i++){
	        if(find(v) == v) connected_c++;
	    }
	}

// practise problems
	// https://www.hackerearth.com/challenges/competitive/code-monk-disjoint-set-union/problems/?
	// cp-algorithms

// Solution of 1 problemset
	// 1 - just like connected comp cnt
	// 3 - approach
		// max, min use kore kora jabe?
		// na | tahole next min, max ber korar jonno iterate kora lagbe
		// we can use multiset for that | 
		// first , last nilei max min peye jabo
		// jokhon merge kora lagbe | 2ta remove korbo | 2tar sum add korbo


	int parent[N];
    int size[N];
    multiset<int> sizes;

    void make(int v){
        parent[v] = v;
        size[v] = 1;
        sizes.insert(1);
    }
    int find(int v){
        if(v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    // multiset e value diye erase korle shob value remove hoye jabe
    // we need to remove one | use iterator 
    // to find iterator use find()
    void merge(int a, int b){
        sizes.erase(sizes.find(size[a]));
        sizes.erase(sizes.find(size[b]));

        sizes.insert(size[a] + size[b]);
    }

    // union function touch korbo na
    // utility merge function banabo, union theke call korbo
    // otherwise code maintain kora tough | clean code
    void Union(int a, int b){
        a = find(a);
        b = find(b);

        if( a != b ){
            if(size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            merge(a, b);
            size[a] += size[b];
        }
    }

    int main(){
        int n, q;
        cin >> n >> q;

        for(int i=1; i<=n; i++){
            make(i);
        }
        while(q--){
            int u, v;
            cin >> u >> v;
            Union(u, v);
            if(sizes.size() == 1){
                cout << 0 << endl;
            }else{
                int mn = *(sizes.begin());
                int mx = *(--sizes.end());
                cout << mx - mn << endl;
            }
        }
    }

