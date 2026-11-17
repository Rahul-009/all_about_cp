// fibo (leetcode 509)
    int fibo(int n){
		if(n == 0) return 1;
		if(n == 1) return 1;

		return fibo(n-1) + fibo(n-2);
	}

	// iterative
	int fibo(int n){
       	if(n<=1) return n;

       	int first=0;
       	int second=1;

    	for(int i=1;i<n;i++){
        	int temp=first+second;
        	first=second;
        	second=temp;
       	} 
       	return second;
    }

// climbing stairs (leetcode 70)
    // without memoization | TLE
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
    
        return climbStairs(n-1) + climbStairs(n-2);
    }

    // memoization
    class Solution {
    public:
        vector<int> memo = vector<int>(50, -1);
        int climbStairs(int n) {
            if(n == 1) return 1;
            if(n == 2) return 2;
            if(memo[n] != -1) return memo[n];

            return memo[n] = climbStairs(n-1) + climbStairs(n-2);
        }
    };
