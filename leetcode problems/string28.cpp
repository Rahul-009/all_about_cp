// Leetcode 
// Problem => Find the index of first occurance in a string
// Link => https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/


// brute force 0(n*m)
int main(){
	string haystack, needle;
 	cin >> haystack >> needle;

 	int n = haystack.size();
 	int m = needle.size();

	for(int i = 0; i <= n-m; i++){

		int j = 0;

		while(j < m && haystack[i+j] == needle[j]){
			j++;
		}

		if(j == m){
			cout << j << endl;
			return 0;
		}
	}

	cout << -1 << endl;
}

// sliding window style 0(n*m)
int main(){
	string haystack, needle;
	cin >> haystack >> needle;

	int n = haystack.size();
	int m = needle.size();
	for(int left = 0; left+m <= n; left++){

		string window = haystack.substr(left, m);

		if(window == needle){
			cout << left << endl;
		}
	}	

	cout << -1 << endl;
}

// KMP (Knuth-Morris-Pratt)