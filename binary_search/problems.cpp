// first and last position of element in sorted array (leetcode 34)
    // method 1 => linear search from front | linear search from back

    // method 2 => binary search
    int start=0, end = nums.size()-1, first=-1, last = -1, mid;

    // find first
    while(start <=end){
        mid = start + (end-start)/2;
        if(nums[mid] == target){
            first = mid;
            end = mid-1;
        }
        else if(nums[mid]<target) 
            start = mid+1;
        else 
            end = mid-1;
    }

    // find last
    start = 0, end = nums.size()-1;
    while(start <=end){
        mid = start + (end-start)/2;
        if(nums[mid] == target){
            last = mid;
            start = mid+1;
        }
        else if(nums[mid]<target) 
            start = mid+1;
        else 
            end = mid-1;
    }

    vector<int> ans(2);
    ans[0] = first;
    ans[1] = last;

    return ans;

// search insert position (leetcode 35)
    int start = 0, end = arr.size()-1;
    int index = arr.size();
    int mid
    while(start <= end){
        mid = start + (start - end)/2;

        if(arr[mid] == target){
            index = mid; 
            break;
        }else if(arr[mid] > target){
            index = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return index;

// sqrt(x) (leetcode 69)
    int start = 1, end = x;
    int mid;
    int ans;
    while(start <= end){
        int mid = start + (end-start)/2;

        if(mid*mid == x ){
            ans = mid;
            break;
        }else if(mid*mid < x){
            ans = mid;
            start = mid+1;
        }else{
            start = mid-1 ;
        }
    }
    return ans;

// peak index in mountain
    int start = 0, end = arr.size()-1, mid;
    while(start<=end){
        mid = end + (start-end)/2;

        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            return mid;
        else if(arr[mid] > arr[mid-1])
            start = mid+1;
        else end = mid-1;
    }
    return -1;

// find minimum in rotated sorted array (leetcode 153)
    // method 1 =>
    int ans = arr[0];
    int start=0, end=n-1, mid;

    while(start <= end){
        int mid = start + (end-start)/2;

        // left side sorted
        if(arr[mid] >= arr[0]){
            start = mid + 1;
        }
        // right side sorted
        else if(arr[mid] < arr[0]){
            ans = arr[mid];
            end = mid - 1;
        }
    }

    // method 2 =>
    int findMin(vector<int>& nums) {

        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {

            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r]) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }

        return nums[l];
    }


    
// search in a rotated array (leetcode 33)

    // method 1
    int search(vector<int>& nums, int target) {

        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {

            int mid = start + ( end - start) / 2;

            if (nums[mid] == target)
                return mid;

            // Left half sorted
            if (nums[start] <= nums[mid]) {

                if (nums[start] <= target && target < nums[mid]) {
                     = mid - 1;
                } else {
                    start = mid + 1;
                }
            }

            // Right half sorted
            else {
                if (nums[mid] < target && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }

    // method 1 reformated
    int start = 0, end = size()-1;
    int mid;

    while(start <= end){
        int mid = start + (end-start)/2;

        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] >= arr[0]){
            if(arr[start] <= target && arr[mid]>= target)
                end = mid - 1;
            else start = mid + 1;
        }else{
            if(arr[mid] <= target && arr[end] >= target){
                start = mid + 1;
            }else end = mid - 1;
        }
    }

// Kth missing positive integer
    int start = 0, end = n-1, ans = arr.size();
    int mid;

    while(start <= end){
        mid = start + (end - start)/2;
    
        if(arr[mid]-mid-1 >= k){
            ans = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }

    return ans+k;

// Book allocation (gfg)

// Painter partition (gfg)

// Ship Packages (leetcode 1011)

// agressive cow (gfg)

// koko eating banana (leetcode 875)
    bool canFinish(vector<int>& piles, int h, int k) {

        long long hours = 0;

        for(int pile : piles) {
            hours += ceil((double)pile / k);

            if(hours > h)
                return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = high;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(canFinish(piles, h, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }


// magnetic force (leetcode 1552)