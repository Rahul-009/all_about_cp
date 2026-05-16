// Sparse Table

// 1, 2, 4, 8, 12
// evabe 2 er power er length er minimum ber kore rakhbo


// overlap matter kore na amon calculation e onek effective 
// overlap friendly - min, max, gcd

// O(N*log(N))  time and space both
// query in O(1)

// update operation thakle O(N) hoye jabe
// update thakle sqrt decomp / segment tree use korbo


// Basic implementation
	const int MAX_N = 100005;
    const int LOG = 17;
    int a[MAX_N];
    int m[MAX_N][LOG]; // row, column change kore implement korbo | due task
    int bin_log[MAX_N];

    int query(int l, int r){

        int length = r-l+1;

        int k = (int)log2(length);// this can give precision error

        // solution-1
        int k = 0;
        while((1 << (k+1) )<=length){
            k++;
        }

        // solution-2
        int k = 31 - __builtin_clz(length); // leading zero cnt dey

        //solution-3 | precomputation
        int k = bin_log[length]; // bin_log will be precomputeted


        return min(m[l][k], m[r-(1<<k) + 1][k]);
    }

    int main(){
        fast_io;

        int n; cin >> n;

        // precomputation as the solution of log2
        bin_log[1] = 0;
        for(int i=2; i<=n; i++){
            bin_log[i] = bin_log[i/2]+1;
        }

        for(int i=0; i<n; i++){
            cin >> a[i];
            m[i][0] = a[i];
        }

        for(int k=0; (1<<k) <= n; k++){
            for(int i=0; (i + (1<<k) - 1) < n; i++){
                m[i][k] = min(m[i][k-1], m[i + (1<<(k-1))][k-1]);
            }
        }

        int q; cin >> q;

        while(q--){
            int l, r;
            cout << query(l, r) << endl;
        }
    }
