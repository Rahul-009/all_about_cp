// segregate 0 and 1 (gfg)
    // method 1 -> sort and conquer O(n^2) or O(nlogn)
    // method 2 -> count 1 and 0 | multiple O(n) loop
    // method 3 -> single O(n) loop | 2 pointer and swap
    int start = 0, end = n-1;
    while(start < end){
        if(arr[start] == 0) start++;
        else{
            if(arr[end] == 0){
                swap(arr[start], arr[end]);
                start++; end--;
            }else end--;
        }
    }

// Two Sum in sorted array (leetcode 167)
    // method1 -> nested loop | check all sum | O(n^2)
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(num[i]+num[j] == target) return 1;
        }
    }
    // method2 -> binary search on difference | O(nlogn)
    for(int i=0; i<n-1; i++){
        x = target - num[1];
        start = i+1;
        end = n-1;
        if(start > end){

        }

    }
    // method3 -> two pointer O(n)
    start = 0, end = n-1;
    while(start > end){
        if(arr[start]+arr[end] == target) return 1;
        else if(arr[start]+arr[end] < target) start++;
        else end--;
    }
    return 0;

// Pair with given difference
    // method1 -> brute force O(n^2)
    // method2 -> binary search on answer | O(nlogn)
    // method3 -> two pointer O(n)
    start = 0, end = 1;
    while(end < n){
        if(arr[end] - arr[start] == target) return 1;
        else if(arr[end]-arr[start] < target) end++;
        else start++;
    }
    return 0;

