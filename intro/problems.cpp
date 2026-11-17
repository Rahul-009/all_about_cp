// reverse integer (leetcode 7)
    // method 1
    int reverse(int x) {
        string s = to_string(x);

        int start = 0, end = s.size()-1;
        while(start < end){
            swap(s[start], s[end]);
            start++; end--;
        }
        long long temp = stoll(s);
        long long ans = 0;

        if(x < 0) ans -= temp;
        else ans += temp;

        if(ans < INT_MIN || ans > INT_MAX) return 0;

        return ans;
    }

    // method 2
    int ans = 0, rem;
    while(x != 0){
        rem = x%10;
        x/=10;
        ans = ans*10+rem;
    }

// power of two
    // method 1 
    while(n%2 == 0){
        n/=2;
    }
    return n == 1 ? 1 : 0;

    // method 2
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }


// pallindrome number
    // method 1 => convert to string and check

    // method 2
        if(x < 0) return 0;
        
        int temp = x;
        int rev = 0;
        while(x != 0){
            if(rev > INT_MAX/10) return 0;
            rev = rev * 10 + (x%10);
            x/=10;
        }

        if(rev == temp) return 1;
        return 0;

// complement of base 10 integer (leetcode 1009)

// Nim Game (leetcode 292)
    // check n = 1, 2, 3, 4, 5, 6, 7, 8 by hand
    // find pattern and solve
    if(n%4 == 0) return 0;
    return 1;
        