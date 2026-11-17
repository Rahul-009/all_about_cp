// one line of string T | one sequence string P given
// find if P is in T or not


// O(window size * string size) | window size choto hole kora jabe
	bool match(int l, int r){
		for(int i=0; i<len_p; i++){
			if(t[l+i] != p[i]) 
				return false;
		}
		return true;
	}

	for(int l=0, r=len_p-1; r<len_t ; l++, r++){
		if(match(l, r))
			cout << l << " ";

		cout << endl;
	}

// longest substring without repeating char (leetcode 3)
	// method 1 => check all substring
	// method 2 => sliding window
	string s;
	vector<bool> count(256, 0);
	int first = 0, second = 0, len = 0;
	while(second < s.size()){
		while(count[s[second]]){
			count[s[first]] = 0;
			first--;
		}
		count[s[second]] = 1;
		len = max(len, second-first+1);
		second++;
	}
	return len;

// smallest distinct window
	vector<int> count(256, 0);
	int first = 0, second = 0, len = str.size();

	// find number of unique characters
	while(first < str.size()){
		if(count[str[first]] == 0) diff++;
		count[str[first]]++;
		first++;
	}

	// reset everything
	for(int i=0; i<256; i++) count[i] = 0;
	first = 0;

	// slide window and track diff
	while(second < str.size()){
		while(diff && second<str.size()){
			if(count[str[second]] == 0) diff--;
			count[str[second]]++;
			second++;
		}
		len = min(len, second-first);

		while(diff != 1){
			len = min(len, second-first);
			count[str[first]]--;

			if(count[str[first]]==0) diff++;
			first++;
		}
	}
	return len;
