#include<bits/stdc++.h>
using namespace std;

// int gcd(int a, int b){
// 	if(a%b == 0) return b; 
// 	return gcd(b, a%b);
// }


// binary exponentiation recursive method
int binExpRecur(int a, int b){
	if(b == 0) return 1;

	long res = binExpRecur(a, b/2);
	if(b&1){
		return a * res * res;  // eta use korbo 
	 // return a * binExpRecur(a, b/2) * binExpRecur(a, b/2);
		// problem : 2ta same function bar bar call hoitese
		//complexity bere jaitese
		// solution : function call kore store kore rakhbo then value gun korbo
	}else{
		return res * res;
	}
}
int M = 1e9 + 7;
int binExpRecur(int a, int b){
	if(b == 0) return 1;

	int res = binExpRecur(a, b/2);
	// int use korle calculation fast hobe
	// space kom lagbe
	if(b&1){
		return (a * ((res * 1LL * res)%M)) % M;	
		//ekhane long long e calculate hobe
		//then mod hoye integer er range e chole ashbe 
	}else{
		return (res * 1LL * res) % M;
	}
}

//Binary exponentiation iterative method
	int binExpIter(int a, int b){
		if(b==0) return 1;
		if(b==1) return a%M;

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


int main(){
	double d1 = 1e20; //all okay
	double d2 = 1e24; //precision loss
	cout << fixed << setprecision(30) << d1 <<'\n';
	cout << fixed << setprecision(30) << d2 << '\n';

	// double onek boro number store korte pare but accurate hoy na
	// ejonno pow() function use na kora better
	// a^b er value ber korar jonno binary exponentiation lage


	// time complexity O(n)
	int a = 2, b= 13;
	int ans = 1;
	for(int i=0; i<b; i++){
		ans *= a;
	}
	cout << ans

	//power frequently ber kora lage tai time complexity komano lagbe
	//solution bin exponentiation

	cout << binExpRecur(a,b) << '\n';
	cout << pow(a,b);

}