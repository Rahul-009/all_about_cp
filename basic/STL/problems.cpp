/* Given N strings, print unique strings in
lexicographical order with their frequency
N <= 10^5
|S| <= 100
*/

	map<string, int> m;
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		m[s]++;
	}	
	for(auto pr: m){
		cout << pr.first << " " << pr.second <<endl;
	}

/*Given N strings, print unique strings in lexicographical order
N <= 10^5
|S| <= 100
*/

	set<string> s;
	int n;
	cin >> n;
	for(int i=0; i<n; i++){		//O(logn)
		string str;
		cin >> str;
		s.insert(str);
	}
	for(auto value: s){
		cout << value << endl;
	}

/*Given N strings and Q queries.
In each query you are given a string
print frequency of that string
N <= 10^6
|S| <= 100
Q <= 10^6
*/
	unordered_map<string> m;
	int n; cin >> n;
	for(int i=0; i<n; i++){
		string str;
		cin >> str;
		m[s]++;
	}	
	int q; cin >> q;
	while(q--){
		string s; cin >> s;
		cout << m[s] << endl;
	}

/*Given N strings and Q queries.
In each query you are given a string
Print YES if string is present
else print NO

N <= 10^6
|S| <= 100
Q <= 10^6
*/

	unordered_set<string> s;
	int n; cin >> n;
	for(int i=0; i<n; i++){
		string str;
		cin >> str;
		s.insert(str);
	}
	int q; cin >> q;
	while(q--){
		string str;
		cin >> str;
		if(s.find(str) == s.end()){	// O(1)
			cout << "NO" <<"\n";
		}else{
			cout << "YES" <<"\n";
		}
	}