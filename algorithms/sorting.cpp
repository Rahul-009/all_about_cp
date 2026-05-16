// selection sort
	// shobcheye choto ta khuje ber korbo
	// swap kore shurute niye ashbo

	void selection(){
	    int min_ind;

	    for(int i=0; i<n-1; i++){
	        min_ind = i;
	        for(int j = i+1; j<n; j++){
	            if(arr[j] < arr[min_ind]){
	                min_ind = j;
	            }
	        }

	        if(min_ind != i){
	            swap(arr[i], arr[min_ind]);
	        }
	    }
	}


// bubble sort
	// all pair compare korbo , swap korbo
	// evabe n-1 bar korbo

	void bubble(){
	    for(int i=0; i<n-1; i++){
	        for(int j=0; j<n-1-i; j++){
	            if(arr[j] > arr[j+1]){
	                swap(arr[j], arr[j+1]);
	            }
	        }
	    }
	}

// insertion sort
	// start from 1
	// store value in temp
	// ager gular sathe ek ek kore compare korbo
	// condition mile gele ek ghor kore daane shoarabo
	// jokhon condition false hoye jabe thambo
	// temp er value faka ghore boshay dibo

	void insertion(){
	    int temp, j;

	    for(int i=1; i<n; i++){
	        temp = arr[i];
	        j = i-1;

	        while(j >= 0 && arr[j] > temp){
	            arr[j+1] = arr[j];
	            j--;
	        }

	        arr[j+1] = temp;
	    }
	}

// merge sort

	// approach 1
	void merge(int* arr, int s, int e){

	    int mid = (s+e)/2;

	    int len1 = mid - s + 1;
	    int len2 = e - mid;

	    int first[len1];
	    int second[len2];

	    // copy values
	    int mainArrayIndex = s;
	    for(int i=0; i<len1; i++){
	        first[i] = arr[mainArrayIndex++];
	    }

	    for(int i=0; i<len2; i++){
	        second[i] = arr[mainArrayIndex++];
	    }

	    // merge 2 sorted array
	    int index1 = 0;
	    int index2 = 0;
	    mainArrayIndex = s;

	    while(index1 < len1 && index2 < len2){
	        if(first[index1] < second[index2]){
	            arr[mainArrayIndex++] = first[index1++];
	        }else{
	            arr[mainArrayIndex++] = second[index2++];
	        }
	    }

	    while(index1 < len1){
	        arr[mainArrayIndex++] = first[index1++];
	    }

	    while(index2 < len2){
	        arr[mainArrayIndex++] = second[index2++];
	    }

	}

	void mergeSort(int* arr, int s, int e){
	    if(s >= e) return;

	    int mid = (s+e)/2;

	    // left part sort korbo
	    mergeSort(arr, s, mid);

	    // right part sort korbo
	    mergeSort(arr, mid+1, e);

	    // merge
	    merge(arr, s, e);
	}

	// approach 2
	int b[100];
	void merge(int* arr, int s, int e){

	    int mid = (s+e)/2;
	    int i = s;
	    int j = mid+1;
	    int main_ind = s;
	    
	    while(i <= mid && j <= e){
	        if(arr[i] < arr[j]){
	            b[main_ind++] = arr[i++];
	        }else{
	            b[main_ind++] = arr[j++];
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
	}

	void mergeSort(int* arr, int s, int e){
	    if(s >= e) return;

	    int mid = (s+e)/2;

	    // left part sort korbo
	    mergeSort(arr, s, mid);

	    // right part sort korbo
	    mergeSort(arr, mid+1, e);

	    // merge
	    merge(arr, s, e);
	}


	// iterative merge sort

	int b[100];

	// mid parameter e na nile odd case er somoy vul hobe
    void merge(int* arr, int s, int mid, int e){

        int i = s;
        int j = mid+1;
        int main_ind = s;
    
        while(i <= mid && j <= e){
            
            if(arr[i] < arr[j]){
                b[main_ind++] = arr[i++];
            }else{
                b[main_ind++] = arr[j++];
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
    }

	void mergeSort(int* arr, int s, int e){
	    int len;
	    for(len = 2; len<=n; len*=2){
	        for(int i=0; i+len-1<n; i+=len){
	            int s = i;
	            int e = i+len-1;
	            int mid = (s+e)/2;
	            merge(arr, s, mid, e);
	        }
	    }

	    // think for size 9, 5 etc.. for (!2^n)
	    if(len/2 < n){
	        merge(arr, 0, len/2-1, n-1);
	    }
	}

// Quick sort

	// pivot = last element
	#include<bits/stdc++.h>
	using namespace std;

	int partition(int arr[], int low, int high){
	    int pivot = high;
	    int pi = low-1;

	    for(int i = low; i<=high-1; i++){
	        if(arr[i] <= arr[pivot]){
	            pi++;
	            swap(arr[pi], arr[i]);
	        }
	    }

	    swap(arr[pi+1], arr[pivot]);
	    return pi+1;
	}

	void quickSort(int arr[], int low, int high){
	    if(low < high){
	        int pi = partition(arr, low, high);

	        quickSort(arr, low, pi-1);
	        quickSort(arr, pi+1, high);
	    }
	}


	int main(){
	    int n = 10;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        arr[i] = rand();
	    }

	    quickSort(arr, 0, n-1);

	    for(int i=0; i<n; i++){
	        cout << arr[i] << endl;
	    }
	}

	// pivot = start element

	// pivot = random element