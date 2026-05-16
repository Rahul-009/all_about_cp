#include<bits/stdc++.h>
using namespace std;

// print all subarray
void subArray(int arr[], int n){
	// Starting point
	for(int i=0 ; i < n ; i++){

		// Ending point
		for(int j=i ; j<n ; j++){

			// Printing Element
			for(int k=i ; k<=j ; k++) cout << arr[k] << " ";
				cout << endl ;

		}
	}
}


// max subarray sum 

// 1. Brute force O(n^2)
int max_subarray_sum(int arr[], int n){
	int mx = 0;
    for(int i=1; i<=n; i++){
        int sum = 0;
        for(int j=i; j<=n; j++){
            sum += arr[j];
            // cout << sum << "\n";  	// to check the sum
            if(mx < sum) mx = sum;
        }
    }
    return mx;
}

// 2. divide and conquer O(nlogn)
int max_subArraySum(int arr[], int n){
	if(n==1) return arr[0];

	int m = n/2;
	int lss = max_subArraySum(arr, m);
	int rss = max_subArraySum(arr+m, n-m);
	int leftsum = INT_MIN;
	int rightsum = INT_MIN;
	int sum = 0;

	for(int i=m-1; i>=0; i--){
		sum += arr[i];
		leftsum = max(leftsum, sum);
	}

	sum = 0;
	for(int i=m; i< n; i++){
		sum += arr[i];
		rightsum = max(rightsum, sum);
	}

	int ans = max(lss, rss);
	return max(ans, leftsum+rightsum);
}

// 3. Kadane's Algo O(n)
int max_sub_sum(int arr[], int n){
    int max_current = arr[0];
    int max_global = arr[0];

    for(int i=1; i<=n; i++){
        max_current = max(arr[i], max_current+arr[i]);
        // cout << max_current << "\t"; 	// to check the max_current
        if(max_global < max_current) max_global = max_current;
    }

    return max_global;
}


int main(){

	//array input
	int n; cin >> n;
    int arr[n+2];

    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
    }
}