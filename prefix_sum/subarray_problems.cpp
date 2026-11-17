// yt resources ->  1. coder army

// zero sum subarray (gfg)
    // method 1 => bruteforce | O(n^3)
    int total = 0;
    for(int i=0; i<n; i++){
        for(int j = i+1; j<n; j++){
            int sum = 0;
            for(int k = i; k<=j; k++){
                sum += arr[k];
            }
            if(sum == 0) total++;
        }
    }

    // method 2 => O(n^2)
    int total = 0;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            if(sum == 0) total++;
        }
    }

    // method 3 => O(n) | prefix sum + hashing(map) count
    long long total = 0;
    unordered_map<long long int, long long int>m;
    long long int prefixSum = 0;
    // initialize by 0, 1
    m[0] = 1;
    for(int i=1; i<n; i++){
        prefixSum += arr[i];
        if(m.count(prefixSum)){
            total += m[prefixSum];
            m[prefixSum]++;
        }else m[prefixSum] = 1;
    }

// subarray sum equals K  
    // method => prefix sum + hash count 
    unordered_map<int, int> m;
    m[0] = 1; // this is important 
    int prefixSum = 0;
    int total = 0;

    for(int i=0; i<nums.size(); i++){
        prefixSum += nums[i];
        if(m.count(prefixSum - k)){
            total += m[prefixSum-k];
            m[prefixSum]++;
        }else{
            m[prefixSum]++;
        }
    }
    return total;

// subarray sum divisible by k (leetcode)
    // method 1 => bruteforce O(n^2)
    // method 2 => prefix sum + remainder track
    unordered_map<int, int> m;
    m[0] = 1;

    int prefixSum = 0, rem, total = 0;

    for(int i=0; i<nums.size(); i++){
        prefixSum += nums[i];
        rem = prefixSum % k;

        if(rem < 0)  // if remainder is negative, make it positive
            rem = k + rem;

        if(m.count(rem)){
            total += m[rem];
            m[rem]++;
        }else m[rem] = 1;

        return total;
    }

// subarray product less than k (leetcode)

// count subarray with score less than K
