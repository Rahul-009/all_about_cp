// Inversion Count for an array indicates – 
// how far (or close) the array is from being sorted in ascending order
// If the array is already sorted, then the inversion count is 0
// but if the array is sorted in reverse order, the inversion count is the maximum.

// arr[i] > arr[j] | i < j

// {8, 4, 2, 1}
// inversions : 6
// (8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).

// approach 1 - bruteforce
	// O(N^2)
	int inv_cnt = 0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j])
                inv_cnt++;
        }
    }


// approach 2 - merge sort
    // O(NlogN)
    int b[100];
    int merge(int* arr, int s, int mid, int e){
        int inv_cnt = 0;

        int i = s;
        int j = mid+1;
        int main_ind = s;
        
        while(i <= mid && j <= e){
            if(arr[i] < arr[j]){
                b[main_ind++] = arr[i++];
            }else{
                b[main_ind++] = arr[j++];

                inv_cnt = inv_cnt + (mid - i + 1);
            }
        }

        while(i <= mid){
            b[main_ind++] = arr[i++];
        }

        while(j <= e){
            b[main_ind++] = arr[j++];
        }

        for(int i=s; i<=e; i++){
            arr[i] = b[i];
        }

        return inv_cnt;
    }

    int mergeSort(int* arr, int s, int e){
        int inv_cnt = 0;
        if(e > s){
            int mid = (s+e)/2;

            inv_cnt += mergeSort(arr, s, mid); 
            inv_cnt += mergeSort(arr, mid+1, e);

            // merge
            inv_cnt += merge(arr, s, mid, e);    
        }
        return inv_cnt;
    }

// approach 3 - multiset 
    // O(N^2)
	int main(){
	    fast_io;
	    int n; cin >> n;
	    int arr[n];

	    for(int i=0; i<5; i++){
	        cin >> arr[i];
	    }
	    multiset<int> ms;
	    ms.insert(arr[0]);

	    int inv_cnt = 0;
	    for(int i=1; i<n; i++){
	        ms.insert(arr[i]); // O(lgn)
	        auto it = ms.upper_bound(arr[i]);

	        inv_cnt += distance(it, ms.end());
	    }
	    cout << inv_cnt << endl;
	}

// approach 4 - AVL tree
    // O(NlogN)
    

// approach 5 - BIT
    // O(N)
