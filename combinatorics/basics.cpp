// Combinatorics

// Approach 
	// Math - factorial, inverse factorial, nCr, nPr, modular arithmatic
	// DP
	// Math + DP

// Tips-
	// Be careful about double counting

//nCr - n choose r
// C(n, r) = C(n, n-r)


// approach 1 O(n+k)
	// n! / (n-r)!*r! = (n-r+1)! / r!
	// factorial pre calculate kore rakhbo
	// r! er modular inverse ber korbo
	// then ans gun kore ber korbo


// approach 2 
	// O(n^n) to calculate pascal | O(1) nCr extraction
	// pascal's triangle | left aligned  
	// main diagonal & 1st column will be 1

	// ncr precalculate kora lagle always eta korbo

	int pascal[1001][1001]; // must be initialized with 0

	int main(){
		pascal[0][0]=1;

		for(int i=1; i<1001; i++){
			pascal[i][0] = 1;
			for(int j=1; j<i+1; j++){
				pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
			}
		}

		// 4C1 = pascal[4][1]
		// 3C2 = pascal[3][2]
	}

// approach 3
	// DP - it has overlapping subproblem and
	// almost like pascal
	ll dp[35][35];

	ll ncr(int n, int r){
	    if(n==r || r==0) return 1;
	    else if(r==1) return n;

	    else if(dp[n][r] != -1) return dp[n][r];

	    dp[n][r] = ncr(n-1, r) + ncr(n-1, r-1);
	    return dp[n][r];
	}

// approach 4
	// best approach  O(r)
	// [n * (n-1) *---* (n-r+1)] / [r * (r-1) *----* 1]
	// numerator and denominator both has exactly r terms
	// divide one by one and multiply
	// C(n, r) = C(n, n-r)
	// r , n-r | jeta choto oita porjonto loop chalabo

	int C(int n, int r){
	    int res = 1;
	 
	    if(r > n - r) r = n-r;
	 	
	 	// (n-r+1)! / r!
	 	// 1 theke r porjonto vag | n - (0 theke r-1)
	    for (int i=0; i<r; i++) {
	        res *= (n - i);
	        res /= (i + 1);
	    }
	 
	    return res;
	}

// nPr 
	// n! / (n-r)! = (n-r+1)!
	// precalculate all factorial and find nPr

// Practise Problems-
	// Team - https://codeforces.com/problemset/problem/478/B
	// Pasha and Sticks - https://codeforces.com/problemset/problem/610/A
    // Lucky number - https://codeforces.com/problemset/problem/630/C
	// Chocolate - https://codeforces.com/problemset/problem/617/B
	// Permutation Partitions - https://codeforces.com/problemset/problem/1326/C
	// Substring Removal - https://codeforces.com/problemset/problem/1096/B
	// Ayoub's function - https://codeforces.com/problemset/problem/1301/C
