//Binary Search 	O(logn)
// array / vector must be sorted
// if input is not sorted ; age sort kore nite hobe

	int n, s; cin>>n>>s;
	int arr[n+2];

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int lo = 0, hi = n-1;
	int mid;

//Method 1
	// while(hi>=lo){
	// 	mid = (lo+hi)/2;		// mid = lo+ (hi-lo)/2; (method 2)

	// 	if(arr[mid]== s){
	// 		cout << mid<<endl;
	// 		break;
	// 	}else if(arr[mid]<s){
	// 		lo= mid +1;
	// 	}else{
	// 		hi = mid-1;
	// 	}
	// }

//Method 3
	while(hi-lo > 1){
		mid = (hi+lo)/2;
		if(arr[mid]<s){
			lo = mid+1;
		}else{
			hi = mid;
		}
	}
 
	if(arr[lo] == s){
		cout << lo << endl;
	}else if(arr[hi] == s){
		cout << hi << endl;
	}else {
		cout << -1 << endl;
	}


//lower bound using binary search 
//lower bound - element present thakle oitar index
			//- element present na thekle oitar immediate boro tar index
int lower_bound(vector<int> &v, int element){
	int lo = 0, hi = v.size()-1;
	int mid;

	while(hi - lo > 1){
		mid = (hi+lo)/2;

		if(v[mid] < element){
			lo = mid + 1;
		}else{
			hi = mid;
		}
	}
	if(v[lo]>=element){
		return lo;
	}else if(v[hi]>=element){ 
		return hi;
	}else{
		return -1;
	}
}

//upper bound using binary search 
// always immediate bor tar index
int upper_bound(vector<int> &v, int element){
	int lo = 0, hi = v.size()-1;
	int mid;

	while(hi - lo > 1){
		mid = (hi+lo)/2;

		// element er porer ta khujbo ; so == hole porer ta te chole jabo
		if(v[mid] <= element){		
			lo = mid + 1;
		}else{
			hi = mid;
		}
	}
	if(v[lo] > element){
		return lo;
	}else if(v[hi] > element){ 
		return hi;
	}else{
		return -1;
	}
}

