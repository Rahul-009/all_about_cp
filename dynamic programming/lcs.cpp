// Longest Common Subsequence
	// approach 1
		// find all subsequence of both string O(2^n + 2^m)
		// compare all subsequence and find the longest one
		// O(n * 2^n)  | very bad !!

	// appraoch 2
		// using recursive DP |  O(n*m)
		// 2ta case - s theke 1 ta char remove, t theke 1 ta remove
		// 3rd case - s, t 2ta thekei 1 ta remove | jodi 2ta char equal hoy plus 1
		
		int func(int ind1, int ind2){
		   if(ind1 == 0 || ind2 == 0) return 0;
		   if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

		   int ans = func(ind1-1, ind2);
		   ans = max(ans, func(ind1, ind2-1));

		   //(s1[ind1]==s2[ind2]) will return 1 / 0 
		   ans = max(ans , func(ind1-1, ind2-1) + (s1[ind1]==s2[ind2])); 

		   return dp[ind1][ind2] = ans;
		}

	// approach 3
		// using iterative DP | tabulation method
		// dp array -1 diye initiate korar dorkar nai
		// dp[n][m] will hold the lcs
		int dp[n+1][m+1];

	    for(int i=1; i<=n; i++){
	        for(int j=1; j<=m; j++){
	            if(s1[i-1] == s2[j-1]){
	                dp[i][j] = dp[i-1][j-1] + 1;
	            }else{
	                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	            }
	        }
	    }
	    cout << dp[n][m] << endl;


// printing lcs
	// dp[n][m] theke upore jabo
	// s1[i-1] == s2[j-1] hole diagonally upore jabo
	// else left and up check korbo | jeta boro oitate jabo
	// **left, up shoman ? upore jabo : left jabo
	// tabulation(dp) print kore debug korbo

 	int lcs = dp[n][m];
    string l;
    int i = n, j=m;
    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            l.push_back(s1[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j] == dp[i][j]){
            i--;
        }else
            j--;
    }
    reverse(l.begin(), l.end());


// Variations
	// Space Optimized LCS
		// we just need 2 rows to calculate the lcs
		// that's why we will make 2*m array instead of n*m
		// first row will be previous iterations result
		// 2nd row will be calculated using 1st row
		// we will replace 1st row with 2nd | after 2nd row is complete
	
	// Minimum insertion, deletion to convert s1(n) into s2(m)
		// lcs ber korbo
		// (n-lcs) element delete korbo s1 theke
		// (m-lcs) element insert korbo s2 theke niye s1 e
		// ans = (n-lcs) + (m-lcs)

	// minimum length of super sequence of s1 and s2
		// supersequence = s1 and s2 duitai je string er subsequence
		// lcs + (m-lcs) + (n-lcs) = (m+n-lcs)

	// longest repeating subsequence
		// if doesnot overlap
			// AAPDRCDBBT  | no overlap
			// if(s[i-1]==s1[j-1] && i!=j)update dp;
	
		// if overlap ?
			// ADARCDBBT
	
	// longest pallindromic subsequence	
		// s1 given | reverse s1 store in s2
		// find lcs of s1 and s2