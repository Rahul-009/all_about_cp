// Sqrt decomposition O(3* sqrtN) | O(sqrtN)

// sqrtN ta block e bhaag korbo | sqrtN element in each block
// sqrt(20) = 4.XXX | etake ceil kore % banabo

// can handle update operation O(sqrtN)

// Basic code

// 0,1,2,3  4,5,6,7  8,9,10,11  12,13,14,15	  | this is main array
//    s1      s2        s3          s4        | this is the block array


// forget the answer of previous query
// Mo's remembers the answer of the prev query

// Basic Code
    const int MAX_N = 10000;
    const int SQRSIZE = 100;
    int block[SQRSIZE];
    int a[MAX_N];
    int n; 

    void preprocess(){
        int blk_idx = -1;
        int blk_size = ceil(sqrt(n));

        for(int i=0; i<n; i++){
            if(i % blk_sz == 0){
                blk_idx++;
            }
            block[blk_idx] += a[i];
        }   
    }


    void update(int idx, int val){
        int blk_size = ceil(sqrt(n));
        int blockNum = idx/blk_sz;

        block[blockNum] += val - arr[idx];
        arr[idx] = val;
    }


    int query(int l, int r){
        int sum = 0;

        // first block | can be partial
        while(l < r && l%blk_sz != 0){
            sum += arr[l];
            l++;
        }

        // middle blocks  | taking full block sum
        while(l + blk_sz-1 <= r){
            sum += block[l/blk_sz];
            l += blk_sz;
        }

        // last block | can be partial
        while( l<=r ){
            sum += arr[l];
            l++;
        }

        return sum;
    }

    int main(){
        fast_io;

        cin >> n;
        for(int i=0; i<n; i++) cin >> a[i];
        
        preprocess();
        cout << query(l, r) << endl; // l, r input
    }


// Mo's Algorithm O(Q*sqrtN)

    // offline technique
    // r age increment kora lagbe | tarpor l increment korte hobe
	// remove korar age frequency check kora lagbe
    // each query is sorted in ascending order of block number of L
    // ties are ordered by ascending order of R

    const int block_sz = 100;
	struct query{
	    int l,
	    int r;
	};
	bool compare(query a, query b){
	    if(a.l/block_sz != b.l/block_sz)
	        return a.l/block_sz < b.l/block_sz;

	    return a.R < b.R;
	}
	int main(){
	    fast_io;
	    int n; cin >> n;
	    int arr[n];

	    int k; cin >> k;
	    query q[k];
	    sort(q, q+k, comp);
	    for(int i=0; i<k; i++){
	        int l = q[i].l;
	        int r = q[i].r;

	        while(currR <= r){
	            currSum += a[currR];
	            currR++;
	        }
	        while(currL < l){
	            currSum -= a[currL];
	            currL ++;
	        } 
	        while(cuurL > l){
	            currSum += a[cuurL];
	            currL--;
	        }
	        while(cuurR > R+1){
	            currSum -= a[cuurR-1];
	            currR--;
	        }
	        cout << currSum << endl;
	    }
	}

