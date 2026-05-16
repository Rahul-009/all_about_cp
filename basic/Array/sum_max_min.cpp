#include<bits/stdc++.h>
using namespace std;


// finding min and max from array
void getMinMax(int arr[],int n){
	int min = INT_MAX;
	int max = 0;
	for(int i=0; i<=n ; i++){
		if(arr[i]<min){
			min = arr[i];
		}
	}

	for(int i=1; i<=n ; i++){
		if(arr[i]>max){
			max = arr[i];
		}
	}

	cout <<"min = "<<min <<'\n';
	cout <<"max = "<<max <<'\n';
}

//Sum of array
int sumArray(int arr[],int n){
	int sum = 0;
	for(int i=1 ; i<=n ; i++){
		sum += arr[i];
	}

	return sum;
}

int main(){
 	int n; cin >> n;
 	int arr[n+2];

 	for(int i=1; i<=n ; i++){
 		cin >> arr[i];
 	}

 	for(int i=1; i<=n ; i++){
 		cout << arr[i] << '\n';
 	}

 	int sum = sumArray(arr,n);
 	cout << sum <<endl;

 	return 0;

}