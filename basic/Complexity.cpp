#include<iostram>
using namespace std;

int main(){

	// Time complexity te logn thakle 2base dhorbo
	// O(n^2) || k ta loop thakle O(n^k)
	for(int i=0 ; i<n ; i++){ //O(n)
		for(int j=0 ; j<n ; j++){ //O(n)

		}		
	}

	// O(logn)
	while (i > 0){
		a += i;
		i /= 2;	
	}

	// O(logn^2)
	for(int i=0 ; i<n ; i*=2){  //O(logn)
		for(int j=0 ; j<n ; j*=2){ //O(logn)

		}	
	}

	// O(nlogn) 
	for(int i=0 ; i<n ; i++){ //O(n)
		for(int j=0 ; j<n ; j*=2){ //O(logn)

		}
	}

	// O(n(n-1)) = O(n^2-n) = O(n^2)
	for(int i=0 ; i<n ;i++){ //O(n)
		for(int j=0 ; j<i ;j++){ //O(n-1)

		}
	}

	// O(logk(n))
	for(int i=0 ; i<n ; i++){
		i *= k;
	}
	
   // O(log(logn))	  
   for (int i = 2; i <=n; i = pow(i, c)) { 
       // some O(1) expressions
   }
   //Here we can use cuberoot or any other constant root
   for (int i = n; i > 1; i = sqrt(i)) { 
       // some O(1) expressions
   }
}