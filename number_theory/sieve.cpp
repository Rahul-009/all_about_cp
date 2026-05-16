// sieve methods O(N)
vector<bool> flag(n, 1);

// method 1
flag[0] = flag[1] = 0
for(int i=2; i<n; i++){
	if(flag[i])
		for(int j = i*2; j<n; j+=i)
			flag[j] = 0;	
}


//method 2
for(int i=3; i<n; i+=2){ // sqrt(n) porjonto chalaleo hobe
	if(flag[i])
		for(int j = 2*i; j<n; j+=i)
			flag[i] = 0;
}
cout << 2 << endl;
for(int i=3; i<n; i++){
	if(flag[i])
		cout << i << endl;
}


//method 3
int val = sqrt(n) + 1;
for(int i=2; i<val; i++){	//sqrt(n)
	if(flag[i])
		for(int j=i; j*i <=n; j++)  //n 
			flag[i*j] = 0;
}


//Goldbach's Conjecture

/* prime1 + prime2 (for sob n>=4 er jonno paoa jabe)
(4<= n <=2^15) er jonno 32768 ta prime niye kaaj korlei hoy
ejonno sieve diye 32768 ta prime ber kore nibo
*/
int i, res=0;
for(int i=2; i<=n/2; i++)
	if(flag[i] && flag[n-i])
		res++;


// divisor count O(nlogn)
int divisors[n + 1];
for (int i = 1; i <= n; ++i)
 for (int j = i; j <= n; j += i)
  ++divisors[j];

 // divisor sum O(nlogn)
int sumdiv[n + 1];
for (int i = 1; i <= n; ++i)
 for (int j = i; j <= n; j += i)
  sumdiv[j] += i;

// eular totient function
int totient[n + 1];
for (int i = 1; i <= n; ++i) totient[i] = i;
for (int i = 2; i <= n; ++i)
 if (totient[i] == i)
  for (int j = i; j <= n; j += i)
   totient[j] -= totient[j] / i;


//factorials factors
int expFactor(int n, int p){
	int x = p;
	int exp = 0;
	while(n/x > 0){
		exp += n/x;
		x*=p;
	}

	return exp;
}
int main(){
	sieve();
	int x; cin >> x;
	int sum = 1, i = 0;

	while(primes[i]<x){
		int n = expFactor(x, primes[i]);
		cout << n << " ";
		sum *= (n+1);
		cout << sum << endl;
		i++;
	}

	cout << sum << endl;
}




// divisor sum using sutro
ll sum_div(ll n){
	ll val = sqrt(n) + 1;
	unsigned ll sum = 1;
	ll p, s;

	for(int i=0; primes[i] < val ; i++){

		if(n%primes[i] == 0){
			p = 1;

			while(n%primes[i] == 0){
				n/=primes[i];
				p *= primes[i];
			}

			p*=primes[i];
			s= (p-1)/(primes[i]-1);
			sum = sum*s;
		}
		
		if(n == 1) break;
	}

	if(n>1){
		p = n*n;
		s = (p-1)/(n-1);
		sum *= s; 
	}

	return sum ;
}


// divisor sum using sutro 2

// Goldbach's Conjecture
int findSol(int n){
	int i, res = 0;
	for(int i=2; i<=n/2; i++){
		if(flag[i] && flag[n-i])
			res++;
	}

	return res;
}


// storing the primes
vector<int> primes;

void sieve(){
	int val = sqrt(N) + 1;

	for(int i=2; i<=N; i++) flag[i]=1;

	for(int i=2; i<val; i++)
		if(flag[i])
			for(int j=i ; j*i<=N; j++)
				flag[i*j] = 0;
			

	for(int i = 2; i<=N; i++)
		if(flag[i]) 
			primes.push_back(i);

}


// segmented sieve
#include<bits/stdc++.h>
using namespace std;


/*  STEPS

1 ) MAX porjonto prime ber kore store kore rakhbo
2 ) sqrt(r) porjonto prime number gular multf lagle katbo
3 ) array size (r-l+1) ; print korbo (i+l) ; kono number er index hobe (i-l)

*/

#define MAX 100001
 
vector<int>  sieve(){
	vector<bool> is_prime(MAX, true);
	is_prime[0]= is_prime[1]= false;
	for(int i=2; i*1LL*i <= MAX;i++){
		if(is_prime[i] == true){
			for(int j = i*i; j<=MAX; j+=i){
				is_prime[j] = false;
			}
		}
	}

	vector<int> primes;

	// normal way
	// for(int i=0; i<MAX; i++){
	// 	if(is_prime[i]){
	// 		primes.push_back(i);
	// 	}
	// }

	// optimized way
	primes.push_back(2); // ekmatro jor prime 2
	for(int i=3; i<MAX; i+=2){ // odd gular jonno loop chalalei hobe
		if(is_prime[i]){
			primes.push_back(i);
		}
	}

	// for(auto x : primes){
	// 	cout << x << endl;
	// }
	return primes;
} 

int main(){
	vector<int> primes = sieve();

	int t; cin >>t;
	while(t--){
		int l, r; cin>> l >> r; 

		bool is_prime[r-l+1];

		for(int i=0; i<r-l+1; i++){
			is_prime[i] = 1;
		}

		if(l == 1){
			is_prime[0] = false;
		}else if(l == 0){
			is_prime[0] = is_prime[1] = false;
		}

		for(int i=0; primes[i]*1LL*primes[i] <= r; i++){
			long long base = (l/primes[i]) * primes[i];
			if(base < l){
				base = base + primes[i]; 
			}

			// cout << base << " " << primes[i]<< endl;
			for(int j = base; j<=r; j+=primes[i]){
				is_prime[j-l] = false;
			}

			if(base == primes[i]){
				is_prime[base-l] = true;
			}
		}

		for(int i=0; i<=r-l; i++){
			if(is_prime[i]){
				cout << i+l << " ";
			}
		}

		cout << endl;
	}
}