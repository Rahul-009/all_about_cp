#include<bits/bits-stdc++.h>
using namespace std;

//nCr == nC(n-r) ; so min(n-r, r) er jonno ber korlei hobe

// O(r*logn)
void ncr(int n, int r){
	long long p=1, k=1;

	if(n-r < r)
		r = n-r;
	
	if(r!=0){
		while(r){
			p *= n;
			k *= r;

			long long m = __gcd(p,k);
			p /= m;
			k /= m;

			r--;
			n--;
		}

	}else{
		p = 1;
	}

	cout << p << endl;
}

//using dp O(n*r)
//used pascal triangle
// 1 0
// 1 1 0 (dp[1] = dp[0] + dp[1] ; dp[0]=dp[0] )
// 1 2 1 0 (dp[1] = dp[0] + dp[1] ; (dp[2] = dp[1] + dp[2]) ; dp[0] = dp[0])
int ncr(int n, int r){
	if(n<r) return 0;
	if((n-r) <r) r = n-r;
	int mod = 1000000007;

	int dp[r+1]; 
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 1; i<=n; i++){
		for(int j = min(r,i); j>0; j--){ 
		// 4c2 ber korte bolse; 4c3 ber korar dorkar nai;
		// ejonno j = min(n,i) use korsi
			dp[j] = (dp[j] + dp[j-1]) % mod;
		}
	}

	return dp[r];
}

int main(){
	int n = 6, r= 3;
	ncr(n,r);
}


// Next to do 
	// catalan numbers

	// binomial coefficient

	// exclusion inclusion principle

	// derangment number