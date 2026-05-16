// string matching problem

	// given 2 string a and b of equal length. check (a==b)?
	// complexity of (a==b) is O(n)
	// because internally it checks every character by iteration
	// hashing reduces it to O(1)

// we will assign each string a hash/key using hash function

	// same string must have same hash value | 100% sure
	// same hash value means strings may be same | not 100% sure

// collision | two string has same hash



// Polynomial Rolling hash
	// converts string to int
	// hash(s) = (s[0] + s[1].p + s[2].p^2 + . . . + s[n-1].p^n-1) % m
		// p should be any number greater than the number of unique characters
		// p >= character set

	// a = 1 theke start korbo | 0 theke start kora jabe na
	// abc = 1*5^0 + 2*5^1 + 3*5^2;
	// for p =11 integer = 10 character | ll 20 character | er por overflow
	// mod korle collision howar chance bare
	// as p >= charset collision will not occur

	ll getHash(string key){
	    ll value = 0;
	    ll p = 31;
	    ll p_power = 1;

	    for(char ch: key){
	        value = (value + (ch - 'a' + 1)*p_power) % M;
	        p_power = (p * p_power) % M;
	    }

	    return value;
	}

// given a string of length n
	// pre calculate hash of whole string O(N)
	// modulo inverse preprocessing O(NlogN)
	// calculating hash of any substring O(1)


	// we will maintain a prefix array dp[N]
		// dp[0] = c.p0
		// dp[1] = c.p0 + o.p1 
		// dp[2] = c.p0 + o.p1 + d.p2
		// dp[3] = c.p0 + o.p1 + d.p2 + i.p3

	// hash(substring(l, r)) = (dp[r] - dp[l-1]) / p^l
		// if l == 0 | don't no subtraction

	const int M = 1e9 + 7;
	const int N = 1e5+10;

	int dp[N];
	int inv[N];

	int mod_inv(int a, int b){
	        b -= 2;
	        int ans = 1;
	        while(b){
	            if(b&1){
	                ans = (ans * 1LL *a)%M;
	            }
	            a = (a * 1LL * a)%M;
	            b >>= 1;
	        }
	        return ans;
	}

	void init(string s){
	    ll p = 31;
	    ll p_power = 1;

	    inv[0] = 1;
	    dp[0] = (s[0] - 'a' + 1);

	    for(int i=1; i<s.size(); i++){
	        char ch = s[i];
	        p_power = (p_power * p) % M;

	        // calculate inverse modulo p^i
	        inv[i] = mod_inv(p_power, M);

	        dp[i] = (dp[i-1] + (ch- 'a' + 1)*p_power % M);
	    }
	}

	int substringHash(int l, int r){
	    int result = dp[r];

	    cout << result << " ";

	    if(l > 0) result -= dp[l-1];
	    result = (result * inv[l]) % M;

	    cout << result << endl;
	    return result;
	}