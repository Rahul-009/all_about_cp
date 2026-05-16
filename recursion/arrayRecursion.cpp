// find if array is sorted or not
	bool isSorted(int arr[], int index){
		if(index == arr.length-1) return true;

		return (arr[index] < arr[index+1]) && sorted(arr, index+1);
	}

// linear search
	bool search(int arr[], int target, int index){
		if(index == arr.length) return false;

		return arr[index] == target || search(arr, target, index + 1);
	}

	int search(int arr[], int target, int index){
		if(index == arr.length)
			return -1;
		
		if(arr[index] == target)
			return index;

		return search(arr, target, index + 1);
	}