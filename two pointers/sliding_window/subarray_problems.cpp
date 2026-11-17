// subarray product less than k
    int product = 1, start = 0, end = 0;
    int n = nums.size();

    while(end < n){
        product *= nums[end];

        while(product>=k && start<=end){
            product /= nums[start];
            start++;
        }

        count+= 1 + (end - start);
    }

// minimum size subarray sum
    int sum = 0;
    int ans = INT_MAX;
    int start = 0, end = nums.size();
    int n = nums.size();
    while(end < n){
        sum += nums[end];
        while(sum >= target){
            ans = min(ans, end-start+1);
            sum -= nums[start++];
        }
        end++;
    }
    return ans == INT_MAX ? 0 : ans;

// minimum window substring
    // bruteforce | find all substring and check
    unordered_map<char, int> m;

    // make only the needed char positive
    for(int i=0; i<t.size(); i++){
        m[t[i]]++;
    }

    int start = 0, end = 0, 
    int ans = INT_MAX, index = -1; // valid window start index and window length
    int n = s.size();

    int need = t.size();
    while(end < n){
        // increase window size
        m[s[end]]--;
        if(m[s[end]]>=0) // if pos decrease need 
            need--;

        // decrease window size
        while(!need && start <= end){
            if(ans > end-start+1){
                ans = end - start + 1;
                index = start;
            }
            m[s[start]]++;
            if(m[s[start]] > 0) 
                need++;
            start++;
        }
        end++;
    }

    if(index == -1) return "";
    string str = "";

    for(int i=index; i<index+ans; i++){
        str+=s[i];
    }

    return str;

// length of longest subarray with atmost K frequency
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int start = 0, end = 0;
        int maxLen = INT_MIN;
        int n = nums.size();

        while(end < n){
            m[nums[end]]++;
           
            while(m[nums[end]] > k && start < end){
                m[nums[start]]--;
                start++;
            }
            maxLen = max(maxLen, end-start+1);
            end++;
        }

        return maxLen;
    }

// Count subArray where max element appear at least K times
    int maxEle = 0, n = nums.size();
    for(int i=0; i<n; i++)
        maxEle = max(maxEle, nums[i]);
    int total = 0;
    int count = 0, start = 0, end = 0;

    while(end < n){
        if(nums[end] == maxEle)
            count++;
        
        while(count == k){
            total += n-end;
            if(nums[start] == maxEle)
                count--;
            start++;
        }
        end++;
    }
    return total;
    
// subarray with k different integer
    // method 1
        // sub2 = find subarray with atleast 2 different integer = sub(2) + sub(3) + sub(4) + ......
        // sub3 = find subarray with atleast 3 different integer = sub(3) + sub(4) + sub(5) + .......
        // ans = sub3 - sub2 (exactly 2 different int)

        int total = 0;

        // For atleast K times
        unordered_map<int, int> freq;
        int start = 0, end = 0, n = nums.size(), count = 0;
        while(end < n){
            freq[nums[end]]++;
            if(freq[nums[end]] == 1) count++;
            
            while(count == k){
                total+=n-end; // addition
                freq[nums[start]]--;
                if(freq[nums[start]] == 0) count--;
                start++;
            }
            end++;
        }

        // For atleast K+1 times
        start = 0, end = 0, count = 0;
        freq.clear();
        k++;
        while(end < n){
            freq[nums[end]]++;
            if(freq[nums[end]] == 1) count++;
            
            while(count == k){
                total-=n-end; // subtract
                freq[nums[start]]--;
                if(freq[nums[start]] == 0) count--;
                start++;
            }
            end++;
        }


    // method 2
        // sub2 = atmost 2 diff integer = sub(0) + sub(1) + sub(2)
        // sub1 = atmost 1 diff integer = sub(0) + sub(1) 
        // ans = sub2 - sub1 (exactly 2 different integer)

