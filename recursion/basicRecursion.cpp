// Recursion
	// function that calls itself
	// function call takes place in the stack
	
// Why recursion
	// do not occupy space for eternity | kaaj sesh hole memory free kore dey
	// recursion can be converted into iteration
	// helps in solving bigger/complex problems in simple way
	// divide bigger problem in smaller problem

// Problem
	// run howar somoy stack e onek jayga lage
	// bar bar stack operation, function call er jonno time waste hoy

// Visalizing recursion**
	// draw recursion tree
	// use debugger**


// approach
	// try to break the problem in smaller problem
	// form the recurrence relation if needed
	// try to figure out the recursion tree
		//see the flow of functions | how they are getting in stack
		// identify & focus on left and right tree calls
	// see how the values are returned
	
	// lastly fix return type, argument type and body
	// Do not over think **


// Types of Recurrence Relation
	// Linear recurrence - fibonacci
		// each time something is subtracted | not a huge difference

	// Divide & Conquer recurrence - Binary search
		// each time the search space divided by a factor
		

// tail recurtion
	// last statement function call hote hobe
	void print(int n){
		if(n == 5) return;
		cout << n << endl;

		print(n + 1); // last statement
	}

// head recurtion
	int fibo(int n){
		if(n == 0) return 1;
		if(n == 1) return 1;

		return fibo(n-1) + fibo(n-2);
		// ekhane last statement function call na
		// last statement function call 2tar result add kora and return kora
		// function er return value var e store kore jog kore return korle bujha jabe
	}

// concept
	void func(int n){
		if(n == 0) return;
		cout << n << endl;
		func(n--); // infinite loop | use --n
	}

// Some basic problems
	// fibonacci O(2^n) | actually goldenRatio^n

	// Binary search
	int search(int arr[], int target, int start, int end){
		if(start > end) return -1;

		int mid = start + (start-end)/2;

		if(arr[mid] == target) return mid;

		if(target < arr[mid]){
			return search(arr, target, start, mid-1);
		}
		return search(arr, target, mid+1, end);
	}

	// print n to 1
	// print 1 to n
	// product of n to 1
	// sum of n to 1
	// sum of digits
	// product of digits
	// reverse a number
		// approach 1
		int sum = 0;
		void rev1(int n){
			if(n==0) return;
			int rem = n%10;
			sum = sum*10 + rem;
			rev1(n/10);
		}

		// approach 2
			// ekta function use koreo kora jeto | age digit ber kore nito hoto main er vitore 
		int rev2(int n){
			int digits = (log10(n)) +1;
			return helper(n, digits);
		}
		int helper(int n, int digits){
			if(n%10 == n) return n;

			int rem = n%10;
			return rem + pow(10, digits-1) + helper(n/10, digits-1);
		}
	// pallindrome
		bool palin()
	// count no of zeroes in a number

		int zero(int n, int c){
			if(n == 0) return c; // c returned once
			// this c will be returned by every function until it reach top

			int rem = n % 10;
			if(rem == 0){
				return helper(n/10, c+1); 
			}
			return helper(n/10, c); 
		}



https://github.com/kunal-kushwaha/DSA-Bootcamp-Java/blob/main/assignments/10-recursion.md