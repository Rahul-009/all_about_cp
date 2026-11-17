// yt resources => coder army
    // kadane's algo

// divide array in 2 subarray with equal sum
    // method 1 -> brute force | compare (0 to i sum ) and (i to n sum) equal or not | O(n^2)
    for(int i=0; i<n-1; i++){
        for(int j=0; j<=i; j++) sum1+=arr[j];
        for(int j=i+1; j<n; j++) sum2+=arr[j];

        if(sum1 == sum2) return 1; 
    }
    // method 2 -> prefix sum | calculate 0 to i sum | sum2 = total_sum - sum1 | O(n)
    total_sum = 0;
    for(int i=0; i<n; i++){
        total_sum+=arr[i];
    }
    int prefix = 0;
    for(int i=0; i<n; i++){
        prefix += arr[i];
        ans = totalsum - prefix;

        if(ans == prefix) return 1;
    }
    return 0;

    // method 3 => suffix sum

// largest sum contiguous subarray
    // method 1 -> bruteforce | all subarray sum | O(n^2)
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        int prefix = 0;
        for(int j=i; j<n; j++){
            prefix+=arr[j];
            maxi = max(maxi, prefix);
        }
        return maxi;
    }

    // method 2 -> prefix sum
        // keep adding until sum becomes -ve|
        // if sum becomes negative make sum = 0
    
    int maxi INT_MIN;
    int prefix = 0;

    for(int i=0; i<n; i++){
        prefix += arr[i];
        maxi = max(maxi, prefix);
        if(prefix < 0) prefix = 0;
    }

    return maxi;

// max different between 2 element
    // bruteforce O(n^2)
    int ans = INT_MIN;
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            ans = max(ans, arr[j]-arr[i]);
        }
    }

    // suffix max | O(N)
    vector<int> suffMax(n);
    int suffMax[n-1] = arr[n-1];
    for(int i = n-2; i>=0; i--){
        suffMax[i] = max(arr[i], suffMax[i+1]);
    }


// Trapping Rain water (leetcode 42)
    // method 1 -> O(n) time | O(n) space
    // prefix sum | suffix sum 
    vector<int> height;
    int leftmax[n], rightmax[n];
    leftmax[0] = 0; 
    for(int i=0; i<n; i++){
        leftmax[i] = max(leftmax[i-1], height[i]);
    }
    rightmax[n-1] = 0;
    for(int i=n-1; i>=0; i--){
        rightmax[i] = max(rightmax[i+1], height[i]);
    }
    int water = 0;
    for(int i=0; i<n; i++){
        minHeight = min(leftmax[i], rightmax[i]);
        if(minHeight - height[i] >= 0)
            water += minHeight - height[i];
    }
    return water;

    // method 2 -> O(1) space
    int leftmax = 0, rightmax = 0, water;
    int maxHeight = height[0], index = 0;
    for(int i=1; i<n; i++){
        if(height[i] > maxHeight){
            maxHeight = height[i];
            index = i;
        }
    }
    // left to max height
    for(int i = 0; i<index; i++){
        if(leftmax > height[i])
            water += leftmax - height[i];
        else leftmax = height[i];
    }
    // right to max height
    for(int i=0; i<index; i++){
        if(rightmax > height[i])
            water += rightmax - height[i];
        else rightmax = height[i];
    }
    return water;

    // method 3 => two pointer 

// 3 sum (gfg)
    // method 1 => bruteforce O(n^3)
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k = j+1; k<n; k++){
                if(arr[i]+arr[j]+arr[k] == target) return 1;
            }
        }
    }
    return 0;

    // method 2 => sort and binary search | O(n^2*logn)
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            int x = target - arr[i] - arr[j];
            // binary search x
        }
    }
    return 0;

    // method 3 => sort and two pointer O(n^2)
    for(int i=0; i<n-2; i++){
        int x = target - arr[i];
        int start = i+1, end = n-1;
        while(start < end){
            if(arr[start] + arr[end] == x) return 1;
            else if(arr[start] + arr[end] > x) end--;
            else start++;
        }
    }
    return 0;


// 4 sum (gfg)

