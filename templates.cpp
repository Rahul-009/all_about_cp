
// Sieve
const int N = 100000;
int flag[N];
vector<int> primes;
void sieve(){
	for(int i=2; i<N; i++) flag[i] = 1;

	for(int i=2; i*i<=N; i++){
		if(flag[i] == 1){
			for(int j=i+i; j<N; j+=i)
				flag[j] = 0;
		}
	}

	for(int i=2; i<N; i++){
		if(flag[i] == 1) primes.push_back(i);
	}

}

// NOD
int NOD(int n){
	int nod = 1;
	for(int i=0; primes[i]*primes[i] <= n; i++){
		int c = 1;
		while(n%primes[i]== 0){
			c++;
			n/= primes[i];
		}
		nod *= c;
	}
	// n 1 hoye jawar kotha chilo.. n!=1 mane aro 1 ta divisor ase
	if(n>1){
		nod *= 2;
	}
	return nod;
}


// SOD
int SOD(int n){
	int sod = 1;
	int p;
	for(int i=0; primes[i]*primes[i] <= n; i++){
		p = primes[i];

		while(n %primes[i] == 0){
			p*= primes[i];
			n/= primes[i];
		}

		sod *= (p-1)/(primes[i] - 1);
	}
	// n == 1 hoye jawar kotha chilo.. n!=1 mane aro 1 ta divisor ase
	if(n > 1){
		p = n*n;
		sod *= (p-1)/(n-1);
	}

	return sod;
}


// Prime Factorization
	map<int, int> fact;
	void factorize(int n){
		int cnt;

		for(int i=0; primes[i]*primes[i] <= n; i++){
			cnt = 0;
			while(n%primes[i] == 0){
				cnt++;
				n/=primes[i];
			}
			fact[primes[i]] = cnt;
		}

		if(n>1){
			fact[n] = 1;
		}
	}

// GCD
	// Time Complexity: O(Log min(a, b))
	// Auxiliary Space: O(Log (min(a,b))
	int gcd(int a, int b){
		if (a == 0) return b;    //  if(b%a == 0) return a; 
		gcd(b%a, a); // gcd(b, a%b)
	}



// Extended Euclidean Algorithm

	//method 1
	int gcd(int a, int b){
		if(b == 0) return a;

		gcd(b, a%b);
	}

	int extended_gcd(int a, int b, int& x, int& y){
		if(b==0){
			x = 1;
			y = 0;
			return a;
		}

		int x1, y1; // egula just function call korar jonno lagtese
		// actual understanding watch neso academy
		int g = extended_gcd(b, a%b, x1, y1);

		x= y1;
		y = x1 - y1*(a/b);

		return g;
	}

	// method 2
	int gcd(int a, int b){
		if(a == 0) return b;
		gcd(b%a, a);
	}

	int extended_gcd(int a, int b, int& x, int& y){
		if(a == 0){
			x = 0;
			y = 1;
			return b;
		}

		int x1, y1;
		int g = extended_gcd(b%a, a, x1, y1);

		y = x1;
		x = y1 - (b/a)*x1;

		return g;
	}

	int main(){
		int x, y;
		extended_gcd(35, 15, x, y);
	}


// Modular Multiplicative inverse
int main(){
	int x, y;
	int m = 17;
	int a = 10;
	int g = extended_gcd(a, m, x, y);
	if (g != 1) {
	    cout << "No solution!";
	}
	else {
		x = x%m ; // eta korle negative ashbe
		// ejonno nicher trick use korte hobe
	    x = (x % m + m) % m;
	    cout << x << endl;
	}
}
