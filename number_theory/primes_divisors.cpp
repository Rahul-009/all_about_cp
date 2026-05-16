// Divisors
	// shob even number er divisor 2
	// odd number er divisor kokhono 2 hobe na
	
	// shob odd number er multiple er sequence
		// ... odd even odd even ... | 
		// even er multiple always even


// Primes
	// 7 * 11 * 13 = 1001
	// 11 * 13 = 143
	// 7 * 13 = 91
	// 2 3 5 7 11
	// 3, 7 last digit hole maximum time prime hoy | not always**
	// 2, 5 last digit hole never be prime
	// 22, 33 ... is never prime
	
	// methods for checking prime
		// sieve of eratosthenes
		// millar-rabin primality test
		// AKS primality test

//brute force  O(N)
	int n = 36;
	int cnt = 0;
	int sum = 0;
	for(int i=2; i<=n; i++){
		if(n%i == 0){
			cout << i << '\n';
			cnt++;
			sum += i;
		}
	}

//sqrt method  O(N^1/2)
	for(int i=1; i<=sqrt(n); i++){  
	// 1 diye to shob number vaag jay ; bolod ra check kore ; ami bolod
		if(n%i == 0){
			cout << i << '\n';
			cnt++;
			sum += i;
		}
	}

	//variation of sqrt method
	for(int i=2; i * i <= n; i++){
		if(n % i == 0){
			cout << i << " " << n\i << '\n';
			cnt ++;
			sum += i;
			if( i != n/i){
				cnt++;
				sum += n/i;
			}
		}


//prime check

	int n; cin >> n;
	if(n==1){
		cout << 0 << endl;
		return;
	}
	bool is_prime = true;

	//O(N)
	for(int i = 2; i<=n; i++){ 
		if(n % i == 0){
			is_prime = false;
			break;
		}
	}
	//O(N^1/2)
	for(int i = 2; i<= sqrt(n); i++){ 
		if(n % i == 0){
			is_prime = false;
			break;
		}
	}
	//O(N^1/2)
	for(int i = 2; i * i<= n; i++){ 
		if(n % i == 0){
			is_prime = false;
			break;
		}
	}
	cout << is_prime;

//Prime factorization
	//O(N)
	vector<int> prime_factors;
	for(int i = 2; i<=n; i++){
		while ( n % i == 0){
			prime_factors.push_back(i);
			n /= i;
		} 
	}
	//O(sqrt(n))
	for(int i = 2; i<= sqrt(n); i++){ 
		while(n % i == 0){
			prime_factors.push_back(i);
			n /= i;
		}
	}	
	if(n > 1){
		prime_factors.push_back(n);
	}


//Sieve Algorithm
	int N = 1e5+10;
	vector<bool> isPrime(N ,1);
	vector<int> lp(N ), hp(N );

	//sieve algorithm code
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i<N; i++){
		if(isPrime[i] == true){
			// j= 2*i ; so prime number er jonno nicher loop e lp hp pabo na
			lp[i] = hp[i] = i;// ejonno manually prime number gula handle er jonno ei line

			for(int j = 2*i; j < N; j+= i){
				isPrime[j] = false;

				//highest prime factor of a number 
				hp[j] = i;

				//lowest prime factor of a number
				if(lp[j] == 0)
					lp[j] = i;
			}
		}
	}

	//variations  1) i*i < N  ; 2) int j = i*i
	//every variations have shortcomings

	for(int i=1; i< 100; i++){
		cout << isPrime[i] << " "; // print is prime or not
	 	cout << lp[i] << ' ' << hp[i] << endl; // print lp and hp
	}

	// sqrt method o korle O(q * sqrt(n)) lagto
	// nicher method e O(q*1)
	int q; cin >> q;
	while(q--){
		int num;
		cin >> num;
		if(isPrime[num]){
			cout << "prime\n";
		}else{
			cout << "not prime\n";
		}
	}

	//prime factorization
	int num; 
	cin >> num;

	vector<int> prime_factors;
	map<int, int> prime_factors2;
	unordered_map<int, int> prime_factors3;
	
	while(num > 1){
		int prime_factor = hp[num]; //ekhane lp[num] niyeo kora jabe
		while(num % prime_factor == 0){
			num /= prime_factor;

			//if we want to use vector O(1)
			prime_factors.push_back(prime_factor);

			//if we want to use map O(logn)
			prime_factors2[prime_factor]++;

			//if we want to use unordered map O(N)
			prime_factors3[prime_factor]++;
		}
	}

	//prints the vector version
	for(auto factor: prime_factors){ 
		cout << factor << " ";
	}
	//prints the map version
	for(auto factor: prime_factors3){
		cout << factor.first << " " << factor.second << endl;
	}


//divisors with sieve
	vector<int> divisors[N];
	int sum[N] = {};

	//N porjonto shob divisor ber kore store korbe O(nlogn)
	// 1e5 er beshi hole N time onek beshi lagbe
	for(int i=2; i<N; i++){
		for(int j=i; j<N; j+=i){
			divisors[j].push_back(i);
			sum[j] += i;
		}
	}

	//divisor print korbe
	for(int i=1; i<100; i++){
		for(int div : divisors[i]){
			cout << div << " ";
		}
		cout << endl;
	}

}


// O(O(√n))
// int sumofFactors1(int n)
// {
//     if(n == 1)
//       return 1;
 
//     // Sum of divisors
//     int result = 0;
  
//     // find all divisors which divides 'num'
//     for (int i = 2; i <= sqrt(n); i++)
//     {
//         // if 'i' is divisor of 'n'
//         if (n % i == 0)
//         {
//             // if both divisors are same
//             // then add it once else add
//             // both
//             if (i == (n / i))
//                 result += i;
//             else
//                 result += (i + n/i);
//         }
//     }
  
//     // Add 1 and n to result as above loop
//     // considers proper divisors greater
//     // than 1.
//     return (result + n + 1);
// }

// // O(O(√n log n)) // this is better
// int sumofFactors2(int n)
// {
//     int res = 1;
//     for (int i = 2; i <= sqrt(n); i++)
//     {
 
         
//         int curr_sum = 1;
//         int curr_term = 1;
//         while (n % i == 0) {
 
//             // THE BELOW STATEMENT MAKES
//             // IT BETTER THAN ABOVE METHOD
//             //  AS WE REDUCE VALUE OF n.
//             n = n / i;
 
//             curr_term *= i;
//             curr_sum += curr_term;
//         }
 
//         res *= curr_sum;
//     }
 
//     // This condition is to handle
//     // the case when n is a prime
//     // number greater than 2.
//     // test with 26, 20 commenting below lines
//     if (n >= 2)
//         res *= (1 + n);
 
//     return res;
// }