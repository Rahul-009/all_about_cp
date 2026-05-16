// structure of segment tree
	// same as binary tree
	// array size 2 er power na hole closest 2 er power niye build korte hobe

// construction
	// tree size will be 4*n  | why ?
	// check this blog - https://codeforces.com/blog/entry/49939

// memory efficient implementation

// finding the max | number of times
// compute gcd / lcm
// counting the number of zeroes | searching for k-th zero
// searching for an array prefix
// first element greater than a given amount
// finding subsegment with maximal sum

//saving entire subarrays in each vertex
	//smallest number greater or equal to a specified number


// point update
// point query
	ll get(int i, int x, int lx, int rx){
        if(rx-lx == 1) return operations[x];

        int m = (lx+rx)/2;
        ll res;
        if(i < m){
            res = get(i, 2*x+1, mid, rx);
        }else
            res = get(i, 2*x+2, lx, mid);

        return res;
    }
// range update | lazy optimization
// range query

// Lazy propagation
	// optimization to make range updates faster
	// In general for update in a range we need to call update multiple times
	// But we will not call update instatntly
	// we wait and build a lazy array | and update several queries at once


// 2D segment tree


// implementation 
	// build O(n*logn)
	// query O( Q*2*logn)
	// memory O(n*logn)
	

	// recursive (without structure)
	const int N = 100001;
	int arr[N];
	int tree[3*N];  // findout why
	int n, q;  

	// lx, rx inclusive
	void init(int x, int lx, int rx){ 	// O(N)
		if(rx == lx){
			tree[x] = arr[lx];
			return;
		}

		int left = 2*x;
		int right = 2*x + 1;
		int mid = (lx+rx)/2;

		init(left, lx, mid);
		init(right, mid+1, rx);

		tree[x] = min(tree[left], tree[right]);
	}

	void update(int i, int val, int x, int lx, int rx) // O(logn)
	{
	    if (i > rx || i < lx)	//বাইরে চলে গিয়েছে
	        return;  			
	    if (lx >= i && rx <= i) {  //রিলেভেন্ট সেগমেন্ট
	        tree[x] = val;  
	        return;
	    }
	    int Left = x * 2; 
	    int Right = x * 2 + 1;
	    int mid = (lx + rx) / 2;
	    update(i, val, Left, lx, mid);
	    update(i, val, Right, mid + 1, rx);
	    tree[x] = min(tree[Left], tree[Right]);
	}

	void update(int i, int v){
		update(i, v, 1, 1, n);
	}

	int query(int l, int r, int x, int lx, int rx){  // O(logn)
		if(lx > r || rx < l) return INT_MAX;
		if(lx >= l && rx <= r) return tree[x];

		int left = 2*x;
		int right = 2*x+1;
		int mid = (lx+rx)/2;

		int leftans = query(l, r, left, lx, mid);
		int rightans = query(l, r, right, mid+1, rx);

		return min(leftans, rightans);
	}

	int query(int l, int r){
		return query(l, r, 1, 1, n);
	}


	// Iterative (efficient)
	const int N = 1e5;

	int n;
	int t[2*N];

	// lx inclusize , rx exclusive
	void build(){
	    for(int i=n-1; i>0; i--){
	        t[i] = t[i << 1] + t[i << 1 | 1];
	    }
	}

	void modify(int p, int val){
	    for(t[p+=n] = val; p > 1; p >>= 1){
	        t[p >> 1] = t[p] + t[p^1];
	    }
	}

	int query(int l, int r){
	    int res = 0;
	    for(l += n, r+=n; l<r; l>>=1, r>>=1){
	        if(l & 1) res += t[l++];
	        if(r & 1) res += t[--r];
	    }
	    return res;
	}

	int main(){

	    fast_io;

	    cin >> n;

	    for(int i=0; i<n; i++){
	        cin >> t[n+i];
	    }

	    build();
	    modify(0, 1);
	    cout << query(3, 11) << endl;
	}


// Range update

	// option - 1

	// Only works for Commutative and associative operations
	// operation er sequence maintain hoy na

	struct segtree{
	    int size;
	    vector<ll> operations;

	    void init(int n){
	        size = 1;
	        while(size < n) size *= 2;
	        operations.assign(2*size, 0LL);
	    }

	    // lx inclusive, rx exclusive
	    // jei node shob index cover kore oitate jog kore return
	    // deep e jabo na | until single element thake
	    void add(int l, int r, int v, int x, int lx, int rx){
	        if(lx >= r || l >= rx) return;
	        if(lx >= l && rx <= r){
	            operations[x] += v;
	            return;
	        }

	        int m = (lx+rx)/2;
	        add(l, r, v, 2*x+1, lx, m);
	        add(l, r, v, 2*x+2, m, rx);
	    }

	    void add(int l, int r, int v){
	        add(l, r, v, 0, 0, size);
	    }


	    // path er shob node er jogfol hobe answer
	    ll get(int i, int x, int lx, int rx){
	        if(rx-lx == 1){
	            return operations[x];
	        }

	        int m = (lx + rx)/2;
	        ll res;
	        if(i < m){
	            res = get(i, 2*x+1, lx, m);
	        }else {
	            res = get(i, 2*x+2, m, rx);
	        }

	        return res + operations[x];
	    }

	    ll get(int i){
	        return get(i, 0, 0, size);
	    }
	};


// For non-commutative operations
	// Lazy propagation use korbo (option - 1)
		// operation er sequence thik thake
		// we need to track which has operation and which has not
		// we can keep boolean array for this | special variable will also do

	
	// recursive without array
	const int N = 1e5+1;
	int n, q; 
	int arr[N+1];

	struct node{
		ll prop, sum;
	};

	node tree[3*N];

	void init(int x, int lx, int rx){
		if(lx == rx){
			tree[x].sum = arr[lx];
			return;
		}

		int left = 2*x;
		int right = 2*x+1;
		int mid = (lx+rx)/2;

		init(left, lx, mid);
		init(right, mid+1, rx);

		tree[x].sum = tree[left].sum + tree[right].sum;
	}

	void update(int l, int r, int val, int x, int lx, int rx){
		if(lx > r || rx < l) return;

		if(lx>=l && rx <=r){
			tree[x].sum += ( val * (rx-lx+1) );
			tree[x].prop += val;
			return;
		}

		int left = 2*x;
		int right = 2*x+1;
		int mid = (lx+rx)/2;

		update(l, r, val, left, lx, mid);
		update(l, r, val, right, mid+1, rx);

		tree[x].sum = tree[left].sum + tree[right].sum;
	}

	ll query(int l, int r, int carry, int x, int lx, int rx){
		if(lx > r || rx < l)return 0;

		if(lx>=l && rx<=r){
			return tree[x].sum + (carry*(rx-lx+1));
		}

		int left = 2*x;
		int right = 2*x+1;
		int mid = (lx+rx)/2;

		ll s1 = query(l, r, carry+tree[x].prop, left, lx, mid);
		ll s2 = query(l, r, carry+tree[x].prop, right, mid+1, rx);

		return s1+s2;
	}

	// recursive with lazy array
	// we can use propagate function to reduce code
	const int N = 1e5;

	int tree[3*N];
	int lazy[3*N];
	int arr[N];

	void build(int x, int lx, int rx){
		if(lx == rx){
			tree[x] = arr[lx];
			return;
		}

		int mid = (lx+rx)/2;
		build(2*x, lx, mid);
		build(2*x+1, mid+1, rx);

		tree[x] = tree[2*x] + tree[2*x+1];
	}

	void update(int x, int lx, int rx, int l, int r, int val){
		if(lazy[x] != 0){
			tree[x] += (rx-lx+1)*lazy[x];

			// child e propagate korbo
			if(rx != lx){
				lazy[2*x] += lazy[x];
				lazy[2*x+1] += lazy[x];
			}

			// nije 0 hoye jabe
			lazy[x] = 0;
		}

		if(rx<l || lx>r) return;

		if(rx<=r && lx>=l){
			tree[x] += val*(rx-lx+1);
			if(rx != lx){
				lazy[2*x] += val;
				lazy[2*x+1] += val;
			}
			return;
		}

		int mid = (lx+rx)/2;
		update(2*x, lx, mid, l, r, val);
		update(2*x+1, mid+1, rx, l, r, val);

		tree[x] = tree[2*x] + tree[2*x+1];
	}

	int query(int x, int lx, int rx, int l, int r){
		if(lx > r || rx < l) return 0;

		if(lazy[x] != 0){
			tree[x] += lazy[x]*(rx-lx+1);
			if(lx != rx){
				lazy[2*x] += lazy[x];
				lazy[2*x+1] += lazy[x];
			}
			lazy[x] = 0;
		}

		if(rx<=r && lx>=l){
			return tree[node];
		}

		int mid = (lx+rx)/2;

		int p1 = query(2*x, lx, mid, l, r);
		int p2 = query(2*x+1, mid+1, rx, l, r);

		return p1+p2;
	}


// codeforces > edu > segtree2 > step 2 > A  
	// ekhane lazy propagation hoche
	// kono jayga tei real value thaktese na
	// query korar somoy root e giye real answer pabo 
	// root e jete jete operations gula complete hobe

	struct segtree{
	    int size;
	    vector<ll> operations;
	    vector<ll> mins;

	    void init(int n){
	        size = 1;
	        while(size < n) size *= 2;
	        operations.assign(2*size , 0LL);
	        mins.assign(2*size, 0LL);
	    }

	    void add(int l, int r, int val, int x, int lx , int rx){
	        if(rx <= l || lx >= r) return;
	        if(lx >= l && rx <= r){
	            operations[x] += val;
	            mins[x] += val;
	            return;  
	        } 

	        int m = (lx+rx)/2;
	        add(l, r, val, 2*x+1, lx, m);
	        add(l, r, val, 2*x+2, m, rx);

	        mins[x] = min(mins[2*x+1], mins[2*x+2]) + operations[x];
	    }

	    void add(int l, int r, int val){
	        add(l, r, val, 0, 0, size);
	    }

	    ll get(int l, int r, int x, int lx, int rx){
	        if(rx <= l || lx >= r){
	            return LLONG_MAX;   
	        }
	        if(lx >= l && rx <= r){
	            return mins[x] ;  
	        } 

	        int m = (lx+rx)/2;
	        ll m1 = get(l, r, 2*x+1, lx, m);
	        ll m2 = get(l, r, 2*x+2, m, rx);

	        return min(m1, m2) + operations[x];
	    }

	    ll get(int l, int r){
	        return get(l, r, 0, 0, size);
	    }

	};


// shafayet blog - http://www.shafaetsplanet.com/?p=1557
// codeforces - https://codeforces.com/blog/entry/18051
// codeforces - https://codeforces.com/blog/entry/1256 (easier)
// https://www.hackerearth.com/practice/notes/segment-tree-and-lazy-propagation/
