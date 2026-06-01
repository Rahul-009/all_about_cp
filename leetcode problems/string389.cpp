// Leetcode 
// Problem => Find the difference
// Link => https://leetcode.com/problems/find-the-difference/description/


#include <bits/stdc++.h>
using namespace std;

// solution 1
int main(){
	string s, t;
	cin >> s >> t;

	vector<int> freq(26, 0);

    for(char ch : s){
        freq[ch - 'a']++;
	}

    for(char ch : t){
		freq[ch - 'a']++;
    }
        
    for(int i = 0; i < 26; i++){
        if(freq[i] % 2 != 0){
            cout << char('a' + i) << endl;
            break;
        }
    }

    cout << " " << endl;
}

// solution 2
int main(){
	string s, t;
	cin >> s >> t;

    // stores ASCII value 0 / NULL internally
	char ans = 0; // important

	for(auto ch: s){
		ans ^= ch;
	}

	for(auto ch: t){
		ans ^= ch;
	}

	cout << ans << endl;
}