// DP means ekta kaaj ekbar kora
// ager kaaj mone rakha

// O(exponential) ke O(n) banay  --- recursion/bottom up
// O(factorial) ke O(2^n) banay	 --- bit masking


// Fibonacci code

#include<bits/stdc++.h>
using namespace std;

int dp[N]; // state er size er soman or boro hoite hobe

//Top down approach
int fibo(int n){	// ekhane n hoche function er state
	if(n == 0) return 1;
	if(n==1) return 1;
	if(dp[n] != -1) return dp[n];

	return dp[n] = fibo(n-1) + fibo(n-2);
}

int main(){
	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;

	cout << fibo(n);


	//Bottom up approach
	dp[0] = 1;
	dp[1] = 1;
	for(int i=2; i<=n; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	cout << dp[n];
}


//https://atcoder.jp/contests/dp/tasks

// Frog 1

#include<bits/stdc++.h>
using namespace std;

const int N = 1e7 +10;
int h[N];
int dp[N];

int func(int i){
	if(i == 0) return 0;
	if(dp[i] != -1) return dp[i];
	int cost = INT_MAX;

	//way 1
	cost = min(cost, func(i-1) + abs(h[i] - h[i-1]));

	//way 2
	if(i > 1)
		cost = min(cost, func(i-2) + abs(h[i] - h[i-2]));

	return dp[i] =  cost;

}

int main(){
	memset(dp, -1, sizeof(dp));
	int n; 
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> h[i];
	}
	cout << func(n-1);
}