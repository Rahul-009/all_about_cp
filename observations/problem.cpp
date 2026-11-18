// Elimination game (leetcode 390)
    // method 1 => loop
    int lastRemaining(int n) {
        bool left = true;
        int head=1, step=1, remain=n;
        while(remain>1){
            if(left || remain&1){
                head += step;
            }
            step *= 2;
            remain /= 2;
            left = !left;
        }
        return head;
    }

    // method 2 => recursive
    int lastRemaining(int n) {
        if (n == 1) return 1;
        return 2 * (n / 2 + 1 - lastRemaining(n / 2));
    }

// GCD of Strings (leetcode)
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1) return "";

        int g = gcd(str1.size(), str2.size());
        return str1.substr(0, g);
    }

// Move zeroes (leetcode)
    // method 1 => O(n) time | o(n) space
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        int cnt_z = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0) cnt_z++;
            else temp.push_back(nums[i]);
        }

        while(cnt_z--) temp.push_back(0);

        for(int i=0; i<n; i++){
            nums[i] = temp[i];
        }
    }

    // method 2 => O(n) time | O(1) space
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 0;

        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }   
    }

    // method 3 => O(n^2) | bubble 0 from end
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        for(int i=n-2; i>=0; i--){
            if(nums[i] == 0){
                int j = i;
                while(j < n-1){
                    swap(nums[j], nums[j+1]);
                    j++;
                }
            }
        }   
    }

// length of last word (leetcode 58)
    int lengthOfLastWord(string s) {
        int len = 0;
        int i = s.size()-1;

        while(i>=0 && s[i] == ' '){
            i--;
        }

        while(i>=0 && s[i] != ' '){
            len++; i--;
        }
        return len;
    }

// Monotonic array (leetcode)

// Can place Flowers (leetcode 605)
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        bool flag = 0;
        int cnt = 0;
        int size = flowerbed.size();

        if(n == 0) return 1;
        if(size == 1){
            if(!flowerbed[0]) cnt++;
            return cnt == n? 1: 0;
        }

        if(flowerbed[0] == 0 && flowerbed[1] == 0){
            flowerbed[0] = 1;
            cnt++;
            if(cnt == n) return 1;
        }

        for(int i=1; i<size-1; i++){
            if(flowerbed[i] == 1) continue;
            if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                flowerbed[i] = 1;
                cnt++;
                if(cnt == n) return 1;
            }
        }

        if(flowerbed[size-1] == 0 && flowerbed[size-2] == 0){
            flowerbed[size-1] = 1;
            cnt++;
            if(cnt == n) return 1;
        }

        return 0;
    }

// longest common prefix (leetcode 14)

// remove element (leetcode 27)

// majority element (leetcode 169)
    // Boyer-moore algorithm
    int majorityElement(vector<int>& nums) {
    int freq = 0, ans = 0;
    for(int i = 0; i < nums.size(); i++){
        if(freq == 0){
            ans = nums[i];
        }
        if(ans == nums[i]){
            freq++;
        }else{
            freq--;
        }
    } 
    return ans;  
    }

