#include <bits/stdc++.h>
using namespace std;

// prefix sum problems
	// Equilibrium array
	// subarray with sum 0

int main() {

//Prefix sum 1
	// arr[i] er pf sum pabo pf[i-1] e

	int n; cin >> n;
    int arr[n+2] = {};
    for(int i=1; i<=n; i++){
    	cin >> arr[i];
    }

	int pf[n] = {};

	for(int i=1; i<=n; i++){
		pf[i] = pf[i-1] + arr[i];
	}

	// printing arr with corresponding pf sum val
    for(int i=0; i<n; i++){
        cout << arr[i] << "\t" << pf[i] << "\n";
    }	

//Prefix sum 2 (better way)
  	//ekhane arr[i] er pf sum pabo pf[i] e 

    //finding the prefix sum
    for(int i=0; i<n;i++){
        pf[i+1] = pf[i] + arr[i];
    }

    // printing arr with corresponding pf sum val
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << "\t" << pf[i] << "\n";
    }


//Given an array arr[] of size n. Given Q queries and in each query given L and R, 
//print sum of array elements from index L to R.

    //Brute force sum    O(q*n)
	int q; cin >> q;

    while(q--){
    	int sum =0;
    	for(int i=l; i<=r; i++){
    		sum += arr[i];
    	}

    	cout << sum << "\n";
    }

    //Procces for Prefix sum 1    O(q)
	while(q--){
		int l, r; cin >> l >> r;

		if(l==1) cout << pf[r-1] << endl;
		else cout << pf[r-1] - pf[l-2] << endl;
	}

	//Proccess for prefix sum 2(better)   O(q)
    while(q--){
        cin >> a >> b;
        cout << pf[b+1] - pf[a] << "\n";
    }

}

//Prefix sum of 2D array
    int n; cin >> n;
    int row=n, col=n; //Just to clear the idea (unnecessary)

    int arr[row+2][col+2]={};  // arr[n+1][n+1]

    for(int i=1; i<=n; i++){    //for row
        for(int j=1; j<=n; j++){    //for column
            cin >> arr[i][j];
        }
    }	
	
	//calculating pf sum
	int pf[n+2][n+2] = {};
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            pf[i][j] = arr[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
        }
    }

	// Printing array and corresponding pf sum val
    for(int i=1; i<=n; i++){    
        for(int j=1; j<=n; j++){    
            cout << arr[i][j] << "\t" << pf[i][j] << "\n";
        }
    }


//Find pf sum from (a,b) to (c,d) for q queries (2D array)
	int a, b, c, d;
    int q; cin >> q;

	//The code below has time complexity O(q*n^2) TLE
	//Brute force process

    // while(q--){
    //     cin >> a >> b >> c >> d ;
    //     int sum =0;

    //     for(int i=a; i<=c; i++){
    //         for(int j=b; j<=d; j++){
    //             sum += a[i][j];
    //         }
    //     }
    // }

	//Now We will calculate prefix sum outside WHILE O(n^2)

    int pf[n+2][n+2] = {};
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            pf[i][j] = arr[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
        }
    }
    
    while(q--){
        cin >> a >> b >> c >> d ;
        cout << pf[c][d] - pf[a-1][d] - pf[c][b-1] + pf[a-1][b-1] << "\n"; 
    }