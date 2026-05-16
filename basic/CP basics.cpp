INT_MAX
INT_MIN
LLONG_MAX
LLONG_MIN


// 1. Array declare korar somoy init value sudhu 0 set kora jay

	int arr[100] = {} // shob 0 hoye jabe
	int arr[100] = {1} // sudhu prothom index 1 hobe, bakigula 0 thakbe

// value for pi
	const double pi = 2*acos(0.0);

// Precedence
	double
	float
	long long int
	long int
	int 
	char 

	double a= 3/2;
	cout << 3/2.0 ;
	cout << 3/2 ;

//Ranges
	
	-10^9 < int < 10^9 					4bytes
	-10^18 < long long int < 10^18		8bytes
	long double	3.4E-4932 to 1.1E+4932	10bytes
	double	1.7E-308 to 1.7E+308		8bytes
	float	3.4E-38 to 3.4E+38			4bytes

	int a = 100000;
	int b = 100000;
	int c = a * b; // 1e5 * 1e5 = 1e10 ; integer overflow ; wrong answer
	long long d = a * b; //integer e calculation hobe ; then long int e assign hobe; wrong answer 
	long long e = a * 1LL * b; //now write ; LL er precedence beshi ; ll e calculate hobe

// operator precedence

	//check cppreference , javatpoint 

	// precedence same hole ki hobe? associativity check
	cout << 7 / 2 * 3; // 9
	cout << 3 * 7 / 2; // 10


//pointer uses
	// method 1
	int add(int& x, int& y){
		x= 10;
		y = 20;
		x= x+y;
		return 0;
	}
	int x, y;
	int main(){ 
		cout << add(x, y) << endl;
		cout << x << y << endl; 
	}

	// method 2
	int add(int *x, int *y){
		*x = 10; // * na dile error
		*y = 20; // * na dile error

		*x= *x+*y;
		return 0;
	}
	int x, y;
	int main(){ 
		cout << add(&x, &y) << endl;
		cout << x << y << endl; 
	}

// scope
	int x = 20;

	int main(){
		int x = 10;
		cout << ::x << endl; // 20
		cout << x << endl; // 10
	}

// index mone rekhe sorting
	// vector of pair method
		vector<pair<int, int>> vec(n);
		// prothome value rakhbo pore index rakhbo done
		for(int i=0; i<n; i++){
			cin >> x;
			vec.push({x, i});
		}
		sort(vec.begin(), vec.end()); // pair.first diye sort hobe

	// efficient way
		vector<int> p(n);
		vector<int> ordp(n);

		iota(ordp.begin(), ordp.end(), 0); //0, 1, 2, .... , n 
		sort(ordp.begin(), ordp.end(), [&](auto x, auto y){return p[x]<p[y];});

//Factorial code & modulo
	int n;
	cin >> n;
	// 20 porjonto long long e thik output dibe
	// 21 input dilei overflow hobe
	// long long was the biggest data type
	// Now what ?  MODULO
	long long fact =1;
	for(int i=1; i<=n; i++){
		fact *= i;
	}
	cout << fact;

	/*
	Given a number N. print its factorial
	constraints 1 <= N <= 100

	print answer modulo M
	where M = 47
	*/
		int fact =1;
		int M = 47;
		for(int i=1; i<=n; i++){
			fact = (fact * i) % M ; // check khata
		}
		cout << fact;

// modular arithmatic equations (note khata check)

// string concatenation
	string s = " ";

	for(int i=0; i<n; i++){
		s = s + 'i'; 		// O(s.size())  ekhane age string er copy banache then oi copy te concatenate hoche
		s.push_back(i); 	// O(1) ekhane kono copy hoche na
	}

//Array size issue
	const int N = 1e7;
	int arr[N]; 
	// main() er vitor declare korle SEGMENTATION FAULT ; stack memory te jabe ; 8mb limit ; 1e5
	// globally declare korle data segment e jabe ; kono limit nai
	// ejonno boro size er array always globally declare korbo


// Time complexity
	// 10^8 operations 	1s 
	// 10^9 operation 	10s
	// 10^10 operation 	100s  	1min 40s
	// 10^11 operation 	1000s 	15 min

	int n = 100000; // 10^5

 	// O(n) +O(n) +O(n) +O(n) +O(n) +O(n) 
		for(int i=0; i<n; i++){
			cout << i << "\n";
		}
		for(int i=0; i<n; i++){
			cout << i << "\n";
		}
		for(int i=0; i<n; i++){
			cout << i << "\n";
		}
		for(int i=0; i<n; i++){
			cout << i << "\n";
		}
		for(int i=0; i<n; i++){
			cout << i << "\n";
		}
		for(int i=0; i<n; i++){
			cout << i << "\n";
		}

	// 1 + 2 + 3 + 4 + .... + n = n(n+1)/2 ; O(n^2)  n=1e5 er jonno cholbe na

		int ct =0; // stores the number of operations
		for(int i=0; i<n; i++){
			for(int j=0; j<i; j++){
				ct ++ ; 	
			}
		}
		cout << ct ;

	//Given an array of size N; print sum
	//of array for t test cases
		// 1<= T <=100000
		// 1<= N <= 100000
	//Sum of N over all test cases is < 10^7 --- this means total operation er number 10^7 er kom; so O(n^2) e code ta cholbe
		// last line ta na thakle O(n^2) e cholto na


//Space complexity
	int a = 5;
	int b = 10;
	int c = a + b; 

	// uporer shob gula mile O(1)

	int arr[n]; //O(n) 
	int arr[n][n]; // O(n^2)


// Pre computation Technique problems

	// Given T test cases and in each test case a number
	// N. Print its factorial for each test case % M
	// where M = 10^9 +7

	// Constarints
	 // 1 <= T <= 10^5
	 // 1 <= N <= 10^5


		const int M = 1e9 + 7;
		const int N= 1e5 + 10;
		long long fact[N];
		// Brute force method O(n*t) 10^5 * 10^5 = 10 ^ 10 TLE
		int t; cin >> t ;
		while (t--){
			int n;
			cin >> n;
			int fact =1;
			for(int i=1; i<=n; i++){
				fact = (fact * i) % M;
			}
			cout << fact << endl;
		}


		// Using pre computation O(N+T) O(N) 10^5 + 10^5 = 2*10^5 pass
		int t; cin >> t;
		fact[0] = fact[1] = 1;

		for(int i = 2; i<N; i++){
			fact[i] = (fact[i-1] * 1LL * i) % M ;
		}

		while(t--){
			int n;
			cin >> n;
			cout << fact[n] << endl;
		}

	//Given array of N integers. Given Q queries and in each query a number X, 
	//print count of that number in array.

	// Constarints
	 // 1 <= a[i] <= 10^7
	 // 1 <= N <= 10^5
	 // 1 <= Q <= 10^5

		const int N = 1e7 +10;
		int hash[N];

		//bruteforce O(N) + O(Q*N) TLE
		int n; cin >> n;
		int arr[n];
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}

		int q; cin >> q;
		while(q--){
			int x; cin >> x;
			int ct = 0;
			for(int i=0; i<n; i++){
				if(arr[i]== x)
					ct++;
			}
			cout << ct << endl;
		}

		// pre computation and hashing O(N + Q) passed
		int n; cin >> n;
		int arr[n];
		for(int i=0; i<n; i++){
			cin >> arr[i];
			hash[a[i]]++;
		}

		int q; cin >> q;
		while(q--){
			int x; cin >> x;
			
			cout << hash [x] << endl;
		}

	// https://www.hackerrank.com/challenges/crush/problem

	const int N = 1e7 + 10;
	long long arr[N];

	// Bruteforce O( m*n + n)
		int n, m; 
		cin >> n >> m;

		while(m--){
			int a, b, d;
			cin >> a >> b >> d;
			for(int i= a; i<=b; i++){
				arr[i]+=d;
			}
		}

		long long mx = -1;
		for(int i = 1; i<=n; i++){
			if(mx < arr[i]){
				mx = arr[i];
			}
		}
		cout << mx << endl;

	// Prefix sum + pre computation O(N+M)
		int n, m; 
		cin >> n >> m;

		// arr[a] + = d ; arr[b+1] -= d
		while(m--){
			int a, b, d;
			cin >> a >> b >> d;
			arr[a] += d;
			arr[b+1] -= d;
		}

		//prefix sum
		for(int i = 1 ; i<=n; i++){
			arr[i] += arr[i-1];
		}

		long long mx = -1;
		for(int i = 1; i<=n; i++){
			if(mx < arr[i]){
				mx = arr[i];
			}
		}
		cout << mx << endl;
 