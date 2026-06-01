// Leetcode 
// Problem => Valid Anagram
// Link => https://leetcode.com/problems/valid-anagram/description/

// bruteforce O(n*m)
int main(){
	string s, t;
	cin >> s >> t;

    if (s.size() != t.size()) {
        cout << "false" << endl;
        return 0;
    }

	vector<bool> used(t.size(), false);
	for(char c: s){
		bool found = false;

		for(int i = 0; i<t.size(); i++){
			if(!used[i] && c == t[i]){
				found = true;
				used[i] = true;
				break;
			}
		}

		if(!found){
			cout << "false" << endl;
            return 0;
		}
	}

	cout << "true" << endl;
}

// sort O(n*logn)
int main(){
	string s, t;
	cin >> s >> t;

	sort(s.begin(), s.end());
	sort(t.begin(), t.end());

	cout << (s == t) << endl;
}

// freq array O(n)
int freq[26] = {0};

int main(){
	string s, t;
	cin >> s >> t;

	if (s.size() != t.size()) {
		cout << false << endl;
        return 0;
    }

    for(char c : s){
    	freq[c - 'a']++;
    }

    for(char c : t){
    	freq[c - 'a']--;
    }

    for(int count: freq){
    	if(count != 0){
    		cout << false << endl;
    		return 0;
    	}
    }

    cout << true << endl;
}

// Hashmap if unicode present O(n)
unordered_map<char, int> mp;
int main(){
	string s, t;
	cin >> s >> t;

	if(s.size() != t.size()){
		cout << false << endl;
		return 0;
	}

	for(char c: s){
		mp[c]++;
	}

	for(char c: t){
		mp[c]--;
	}

	for(auto it: mp){
		if(it.second != 0){
			cout << false << endl;
			return 0;
		}
	}

	cout << true << endl;
}