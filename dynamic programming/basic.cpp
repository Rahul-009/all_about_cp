// memoization - ager solution mone rakha
// State
	// changeable parameter will be the states

// Top down = n theke 0 te iterate kora
// Bottom up = 1 theke n e iterate kora

// Types of problem
	// Optimization problem
		// min koto resource e kaaj kora jay
		// max koto score e exam sesh kora jay
	// Number of ways count
		// combinatorics / DP 2 vabe kora jay
	// yes/no problem eo dp use hote pare

// Approach -
	// Greedy diye solve kora jay naki check kora***
	// all possible situation check kora lagbe naki?**
	// DP er type bujha
	// constraint dekhe state ki hobe bujhte hobe
		// constraint beshi hole max problem ke min banaite hobe
		// min problem ke max banay solve kora lagbe
	// state fix kora | dp array fix kora
	// return type ki hobe fix kora | and ki return korte hobe**

// Important for debugging
	// always keep base cas exact
		// if( n == 0 ); | don't do if(n<=0);
		// n < 0 jeno na hoy oijonno recursive call er age check boshano lagbe
	// top down e problem hole bottom up try koro

// atcoder dp contest - https://atcoder.jp/contests/dp/tasks

// Top Down - recursive
	int dp[n];
	int fibo(int n){
		if(n == 0) return 1;
		if(n == 1) return 1;

		// if precalculated return , dont call the next function
		if(dp[n] != -1) return dp[n];

		// memorize
		return dp[n] = fibo(n-1) + fibo(n-2);
	}

// Bottom Up - iterative
	int dp[n];
	dp[0] = dp[1] = 1;
	for(int i=2; i<=n; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}


// knapsack is a concept
	// based on some condition we have to choose items
	// 0 1 knapsack - 1ta item full nite hobe | ordhek neya jabe na | yes or no
		// ekbar e neya jabe
		// bostay item dhukano
		// tree 0-1 property ase amon state er upor korte hobe
		// nile ki hobe(left) | na nile ki hobe(right) evabe tree banate hobe


	// unbound knapsack - No limit jotobar khushi nite parbo
		// rod cutting	
		// coin change i

	// fractional knapsack - greedy | not dynamic**


// O(2^n) converts to O(n)
// O(n!) converts to O(2^n) | bitmasking dp

// coin change
	// https://leetcode.com/problems/coin-change/
	// https://leetcode.com/problems/coin-change-ii/

// Edit Distance
// Rod Cutting
// Longest Increasing Subsequence
	// value increasing hote hobe
	int dp[N];
    for(int i=0; i<n; i++){
        dp[i] = 1;
    }
    for(int i=0; i<n; i++){
        for(int j = 0; j<i; j++){
            if(arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, dp[i]);
    }

    cout << ans;

// subset problem
	// subset sum k hoite pare kina



// yt tusher playlist - https://youtube.com/playlist?list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr
// yt tusher github - https://github.com/mission-peace/interview/tree/master/src/com/interview/dynamic
