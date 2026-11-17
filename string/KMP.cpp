// longest prefix, longest suffix
    vector<int> lps(s.size(), 0);
    int pre = 0, suf = 1;
    while(suf < s.size()){
        // pref, suff match
        if(s[pre] == s[suf]){
            lps[suf] = pre + 1;
            pre++, suf++;
        }
        // do not match
        else{
            if(pre == 0){
                lps[suf] = 0;
                suf++;
            }else{
                pre = lps[pre-1];
            }
        }
    }
    return lps[s.size()-1];

// String matching
    // sliding window O(nm)
        int n = haystack.size(), m = needle.size();

        for(int i=0; i<=n-m; i++){
            int first = i; // pointer for haystack
            int second = 0; // pointer for needle

            // check needle is present in haystack
            while(second < m){
                if(haystack[first] != needle[second]) break;
                else{
                    first++;
                    second++;
                }
            }

            // needle found in haystack
            if(second == m)
                return first - second;
        }

        return -1;

    // method 2 => KMP O(n)
        lpsfind(vector<int> &lps, string s){
            int pre = 0, suf = 1;
            while(suf < s.size()){
                if(s[pre] == s[suf]){
                    lps[suf] = pre+1;
                    suf++; pre++;
                }
                else{
                    if(pre == 0){
                        lps[suf] = 0;
                        suf++;
                    }else{
                        pre = lps[pre-1];
                    }
                }
            }
            return lps[s.size()-1];
        }

        // store lps of needle
        vector<int> lps(needle.size(), 0);
        lpsfind(lps, needle);

        // now go through haystack
        int first = 0, second = 0;
        while(second < needle.size() && first < haystack.size()){
            // match
            if(needle[second] == haystack[first]){
                second++; first++;
            }
            // do not match
            else{
                if(second == 0) first++;
                else second = lps[second - 1];
            }
        }

        if(second == needle.size())
            return first-second;

        return -1;
    
// make a string pallindrome (gfg)
    // method 1 => bruteforce O(n^2) |
    
    // method 2 => longest prefix pallindrom | O(N)
        // given string and reverse string | find lps 
        // s += '$' | s += reverse(s) | lps(s) | ans = s.length() - lps

        string rev = str;
        reverse(rev.begin(), rev.end());
        int size = str.size();
        str += '$';
        str += rev;

        int n = str.size();
        vector<int> lps(n, 0);

        int pre = 0, suf = 1;
        while(suf < str.size()){
            // matched
            if(str[pre] == str[suf]){
                lps[suf] = pre + 1;
                pre++, suf++;
            }
            // not matched
            else{
                if(pre == 0){
                    suf++;
                }else{
                    pre = lps[pre-1];
                }
            }
        }
        return size - lps[n-1];
    
// circular pattern matching
    
// Repeated string match (leetcode 686 )
        if(a == b) return 1;

        int repeat = 1;
        string temp = a;

        while(temp.size() < b.size()){
            temp += a;
            repeat++;
        }

        // KMP pattern search
        if(KMP_MATCH(temp, b) == 1)
            return repeat;

        // Temp + a | KMP search
        if(KMP_MATCH(temp+a, b) == 1)
            return repeat+1;

        return -1;
