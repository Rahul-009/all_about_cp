// Modular Basics
	// M diye mod korle answer 0 theke m-1 er modhe thakbe
	
	// kono number ke choto number diye mod korle at most n/2 hote parbe | er cheye boro hobe na
	
	// n%2 == 1 hole odd

	// n % 4 == 1 | n % 4 == 3 | both odd 
	// first case  e n/2 even | second case e n/2 odd

// utility functions to make mod easy

	// positive, negative 2tar jonnoi thik answer dibe
	ll mod(ll x){
		return ((x % M) + M) % M;
	}

	// add with mod
	ll add(ll a, ll b){
		return mod(mod(a)+mod(b));
	}

	// mul with mod
	ll mul(ll a, ll b){
		return mod(mod(a)*mod(b));
	}

	// inverse modulo
	ll inv(ll x){
		return powmod(x, M-2);
	}

	// division with mod
	ll div(ll a, ll b){
		return mulmod(a, inv(b))
	}

// Notation

// 4 basic modular operations
	// add
		int ans = (a+b) % m;
	// subtract
		// negative number mod korar somoy M add kore deya lage
		int ans = (a-b+m) %m;
	// multiplication
		int ans = ((a%m) * (b%m))%m ;
	// division
		// modular inverse | 1. fermat's little theorem | 2. Extended GCD


// intuition *
	// 1. n % m <= n/2 | when m = (1 theke n-1)
		// kono number ke choto number diye mod korle at most n/2 hote parbe | er cheye boro hobe na
		int n = 6;
		for(int i=1; i<n-1; i++){
			cout << n % i << endl; 
		}

	// 2. decimal number er last k digit print koro
		// 10^k diye mod korbo

		int n = 10716;
		int k = 3;
		int m = 10;
		while(k--) m *= 10;

		cout << n % m << endl; // last k digit print korbe

	// 3. 2^k diye mod kora mane last k ta bit print kora
		int n = 128-1;
		int k = 4, m = 2;
		while(k--) m*=2;

		cout << n % m << endl;

// m = 2^32 | work with unsigned integer
	// unsigned int er capacity 2^32-1
	unsigned int n = 1e9 * (1e5+5864);

// m = 2^64 | work with unsigned long long
	// unsigned long long er capacity 2^64-1
	unsigned long long n = 1e18 * (1e5+5864);

// Fermat's little theorem | Proof important
	// find (x^m-2) for inverse

int fermat_inverse(int a, int m){
	int ans = 1;
	int M = m;
	m-=2;
	while(m){
		if(m&1){
			ans = (ans * 1LL *a)%M;
		}
		a = (a * 1LL * a)%M;
		m >>= 1;
	}
	return ans;
}

// Extended Euclidean Algorithm
	


int main(){

	fast_io;

	int a = 5;
	int m = 3;

	cout << fermat_inverse(10, 7) << endl;


}


// Problems 
	// https://www.geeksforgeeks.org/print-last-k-digits-of-ab-a-raised-to-power-b/
	// https://www.geeksforgeeks.org/find-the-maximum-possible-value-of-ai-aj-over-all-pairs-of-i-and-j/
	// Simple Math 2 - https://atcoder.jp/contests/arc111/tasks/arc111_a
		// solution
			ll modpow(ll n, ll m){
			    if(n == 0) return 1;
			    ll ans = modpow(n/2, m);
			    if(n&1)
			        ans = (ans * ans * 10 )%m;
			    else
			        ans = (ans * ans)%m;
			    return ans;
			}
			int main(){
			    fast_io;
			    ll n, m; cin >> n >> m;
			    ll ans = modpow(n, m*m);
			    cout << ans/m << endl;
			}