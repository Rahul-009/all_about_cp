// how many digit of X^Y
	int x, y; cin >> x >>y;
	cout << pow(x,y) << endl;

	int dig = y*log10(x)+1;
	cout << dig << endl;

// how many digits of n!
ll fact(int n){
	ll sum = 1;
	for(int i=1; i<=n; i++){
		sum*=i;
	}

	return sum;
}
int main(){
	fast;

	int n; cin>>n;
	int ans = floor(log10(fact(n))) +1;

	cout << fact(n) << endl;
	cout << ans << endl;
}


// trailing zeros of factorial
	// method 1
int Trailing_Zeros(int n){
	int count = 0;
	while(n){
		count += n/5;
		n = n/5;
	}
	return count ;
}

	// method 2
int Trailing_zero2(int n){
	int count = 0;

	for(int i=5; n/i >= 1; i*=5){
		count += n/i;
	}

	return count;
}