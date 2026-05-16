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