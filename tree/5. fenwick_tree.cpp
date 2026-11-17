// Fenwick / BIT

// index gular binary representation use kore optimize kora hoy

// time complexity O(nlogn)
// space complexity O(N) | here it's better than segment tree

// Applications:
		// Binary Indexed trees are used to implement the arithmetic coding algorithm. Development of operations it supports were primarily motivated by use in that case.
		// Binary Indexed Tree can be used to count inversions in an array in O(N*logN) time.

// Logic
	// shob index er binary chinta korbo
	// binary num er rightmost 1 check korbo 
		// rightmost 1 er value er shoman node er jogfol thakbe oi index e
	// 8 = 1000  | 2^3 tar jogfol thakbe 8 e | 1-8
	// 16 = 10000 | 2^4 = 16  |1-16  
	// 13 = 01101 | 2^0 = 1 | sudhu 13
	
	// query
		// q(10) = t[10] + t[8]  | t[10] = 9+10 ; t[8] = 1..8
		// q(11) = t[11] + t[10] + t[8]

		// 11 theke 10 , 10 theke 8 e kivabe jabo?
		// 11 = 1011  | flip rightmost 1 - 1010(10)
		// 10 = 1010 | flip rightmost 1 - 1000(8)   | done
	
		// 10 = 11 - (11 & (-11));
	
	// update
		// U(idx=5, val=3) = idx 5, 6, 8, 16 change korte hobe
		
		// How to jump ?
		// 5 = 101 | ~5 = 010 | ~5 + 1 = 011 | 5 & (-5) = 101 & 011 = 001 | 101(5) + 001 = 110 = 6
		// shortcut 6 = 5 + (5 & (-5))
		// same for 6 to 8 | 8 to 16

	// build tree
		// input neyar somoy update call kore dilei hobe
	const int N = 1e5+10;
	int arr[N];
	int tree[N];
	int n;

	int query(int idx){
		int sum = 0;
		while(idx>0){
			sum += tree[idx];
			idx -= idx & (-idx);
		}
		return sum;
	}

	void update(int idx, int val){
		while(idx <= n){
			tree[idx] += val;
			idx += idx & (-idx);
		}
	}

	int main(){
		fast_io;
		
		cin >> n;
		for(int i=1; i<=n; i++){
			cin >> arr[i];
			update(i, arr[i]);
		}
		// print result
		for(int i=1; i<=n; i++){
			cout << tree[i] << endl;
		}
	}

// Before going for Binary Indexed tree to perform operations over range, one must confirm that the operation or the function is:
	// 1.Associative. i.e f(f(a, b), c) = f(a, f(b, c)) this is true even for seg-tree
	// 2. Has an inverse.
		// addition has inverse subtraction (this example we have discussed)
		// Multiplication has inverse division
		// gcd() has no inverse, so we can’t use BIT to calculate range gcd’s
		// sum of matrices has inverse
		// product of matrices would have inverse if it is given that matrices are degenerate i.e. determinant of any matrix is not equal to 0


// articles - 
	// visualize the tree - https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
	// shafayet blog - http://www.shafaetsplanet.com/?p=1961&fbclid=IwAR23aI879JfPHbIaW3y93Du6Ql_68DCTxcUY6euLJUWsLvgtvj_-b2tKJCE
	// hackerEarth - https://www.hackerearth.com/practice/notes/binary-indexed-tree-or-fenwick-tree/
	// topcoder - https://www.topcoder.com/thrive/articles/Binary%20Indexed%20Trees