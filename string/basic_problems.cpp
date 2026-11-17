// pallindrome
	while(start < end){
		if(s[start] != s[end]){
			cout << "Not a pallindrome";
			return;
		}
		start++, end--;
	}
	cout << "It is a pallindrome" << endl;

// pangram (leetcode 1832)
    // all english letter present

// anagram

// rotate string clockwise
	void clockwise(string s){
		char c = s[s.size()-1];
		int index = s.size()-2;
		while(index >= 0){
			s[index+1] = s[index];
			index--;
		}
		s[0] = c;
	}

// rotate anticlockwise 
	void anticlockwise(string s){
		char c = s[0];
		int index = 1;
		while(index < s.size()){
			s[index - 1] = s[index];
			index++;
		}
		s[s.size()-1]= c;
	}

// sort a string
	// method 1 -> count char and make a new string

// longest pallindrome possible (leetcode)

// sorting the sentence (leetcode 1859)
    // method 1
    class Solution {
    public:
        string sortSentence(string s) {
            vector<string> ans(10);
            string temp;
            int count = 0, index = 0;

            while(index < s.size()){
                if(s[index] == ' '){
                    int pos = temp[temp.size()-1] - '0';
                    temp.pop_back();
                    ans[pos] = temp;
                    temp.clear();
                    count++;
                }else{
                    temp += s[index];
                }
                index++;
            }

            // Handle the LAST word (no trailing space)
            int pos = temp[temp.size()-1] - '0';
            temp.pop_back();
            ans[pos] = temp;
            temp.clear();
            count++;

            // Build result for positions 1..count
            for(int i = 1; i <= count; i++){
                temp += ans[i];
                temp += ' ';
            }
            temp.pop_back();  // remove trailing space
            return temp;
        }
    };

    // method 2
    string sortSentence(string s) {
        vector<string> ans(10);
        stringstream ss(s);
        string word;
        int count = 0;
        while (ss >> word) {
            int pos = word.back() - '0';
            word.pop_back();
            ans[pos] = word;
            count++;
        }
        string res;
        for (int i = 1; i <= count; i++) {
            res += ans[i];
            if (i < count) res += ' ';
        }
        return res;
    }

// roman to integer (leetcode)
    int num(char c){
        if(c == 'I') return 1;
        else if(c == 'V') return 5;
        else if(c == 'X') return 10;
        else if(c == 'L') return 50;
        else if(c == 'C') return 100;
        else if(c == 'D') return 500;
        else return 1000;
    }
    int romanToInt(string s) {
        int sum = 0, index = 0;
        while(index < s.size() - 1){
            if(num(s[index]) < num(s[index+1]))
                sum -= num(s[index]);
            else sum += num(s[index]);
            index++;
        }   
        sum += num(s[index]);
        return sum;
    }

// integer to roman (leetcode 12)

// factorial of large number (gfg)
    vector<int> ans(1, 1);
    while(n > 1){
        int carry = 0, res, size = ans.size();
        for(int i=0; i<size; i++){
            res = ans[i]*n + carry;
            carry = res/10;
            ans[i] = res%10;
        }
        while(carry){
            ans.push_back(carry%10);
            carry /= 10;
        }
        n--;
    }
    reverse(ans.begin(), ans.end())
    return ans;

