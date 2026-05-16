// Recursion
	// nije nijeke call korbe

	//Equivalent to forward loop
	void numPrint(int n){
		if(n==0) return;
		cout << n << '\n';
		numPrint(n-1);
	}

	//Equivalent to backward loop
	void numPrint2(int n){
		if(n==0) return;
		numPrint2(n-1);
		cout << n << '\n';
	}

	//factorial code
	int fact(int n){
		if(n==0) return 1;
		return fact(n-1) * n;
	}

	//find N-th sum of an array
	int sum(int n, int arr[]){
		if(n<0) return 0;
		cout << arr[n] << "\n";
		return sum(n-1, arr) + arr[n];
	}

	//digit sum
	int digitSum(int n){
		if(n==0) return 0;
		return digitSum(n/10) + (n % 10);
	}





//Backtracking 
	// recursion with condition
	// restore previous state after returning a function
	// array reference pass korte hobe | otherwise prottek call e new array create hobe


// Practise Problems -
	// https://leetcode.com/problems/generate-parentheses/
	// https://leetcode.com/problems/k-th-symbol-in-grammar/
	// https://codeforces.com/problemset/problem/1462/D
	// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
	// https://leetcode.com/problems/subsets/
	// https://codeforces.com/gym/102892/problem/3


	// solution for generate parenthesis
		// n deya thakbe | n pair of bracket diye koyta sequence banano jabe
	vector<string> valid;

	void generate(string &s, int open, int close){
		// base condition
		if(open == 0 && close ==0){
			valid.push_back(s);
			return;
		}
		if(open > 0){
			s.push_back('(');
			generate(s, open-1, close);

			s.pop_back(); // backtracking
		}
		if(close > 0 && open < close){
			s.push_back(')');
			generate(s, open, close-1);

			s.pop_back(); // backtracking
		}
	}

	// subset generation
		// 2^n subset for n numbers | n will be given
		// each level e ekta element nibo | arekta call e nibo na
	vector<vector<int>> subsets;

	void subGenerate(vector<int> &subset, int i, vector<int> &nums){
		if(i==nums.size()){
			subsets.push_back(subset);
			return;
		}

		//i-th element not in subset
		subGenerate(subset, i+1, nums);

		//i-th element in subset
		subset.push_back(nums[i]);
		subGenerate(subset, i+1, nums);

		subset.pop_back(); 	//backtracking step;
	}
