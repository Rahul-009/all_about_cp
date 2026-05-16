// GCD = greatest common divisor

	// __gcd(0, a) = a
	// __gcd(1, a) = 1

	// consecutive 3 odd number er gcd 1

	// Time Complexity: O(Log min(a, b))
	// Auxiliary Space: O(Log (min(a,b))
	
// LCM = least common multiple
	// lcm * gcd = a * b

// builtin functions;
	// __gcd(a, b) 			| works for int
	// __gcd<ll>(a, b) 		| for long long
	// __gcd<int64_t>(a, b)

// Practise Problems
	// https://www.codechef.com/problems/GCDQ
	// https://codeforces.com/problemset/problem/1617/B


// Extended Euclidean Algorithm

	//method 1
	int gcd(int a, int b){
		if(b == 0) return a;

		gcd(b, a%b);
	}

	// same as before | just changed order
	int gcd(int a, int b){
		if (a == 0) return b;    //  if(b%a == 0) return a; 
		gcd(b%a, a); // gcd(b, a%b)
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