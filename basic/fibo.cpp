#include<bits/stdc++.h>
using namespace std;

// fibonacci rule : || f(n) = f(n-1) + f(n-2) ||

// using recursion
// f(0) = 0 | f(1)=1 | f(2)=1 | ....
int fibo(int n){
	if(n <= 1) return n;
	return fibo(n-1) + fibo(n-2);
}

int main(){
	int n; cin >> n;
	int f1 = 0, f2 = 1;
	int nextTerm;

// fibo upto N terms
	// for(int i=1; i<=n; i++){
	// 	if( i == 1 ) {
	// 		cout << f1 << " ";
	// 		continue;
	// 	}

	// 	if( i == 2 ) {
	// 		cout << f2 << " ";
	// 		continue;
	// 	}

	// 	nextTerm = f1 + f2;
	// 	f1 = f2;
	// 	f2 = nextTerm;

	// 	cout << nextTerm << " ";
	// } 

// fibo upto a certain number

	// cout << f1 << " " << f2 <<" ";

	// nextTerm = f1 + f2;

	// while(nextTerm <= n){
	// 	cout << nextTerm << " ";
	// 	f1 = f2;
	// 	f2 = nextTerm;
	// 	nextTerm = f1 + f2;
	// }

}