// for n size array subsequence size is 2^n

// print subsequence
void printSubsequences(int arr[],int n){
	int size = pow(2, n);
	for(int counter = 1 ; counter < size ; counter++){
		for(int i=0 ; i<n ; i++ ){
			if(counter & (1<<i)){
				cout << arr[i];
			}
		}
		cout << "\n";
	}
}
