#include<bits/stdc++.h>
using namespace std;

string str_sum(string str1, string str2){
	int n1 = str1.length();
	int n2 = str2.length();

	if(n1 > n2){
		swap(str1, str2);
	}

	string str = " " ;

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;

	for(int i=0; i<n1; i++){
		int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
		str.push_back(sum%10 + '0');

		carry = sum/10;
	}

	for(int i=n1; i<n2; i++){
		int sum = ((str2[i]-'0') + carry);
		str.push_back(sum%10 + '0');
		carry = sum/10;
	}

	if(carry)
		str.push_back(carry +'0');

	reverse(str.begin(), str.end()); 
	
	return str;
}

string str_sub(string str1, string str2){
	if(str1.length() < str2.length()){
		swap(str1, str2);
	}else if (str1.length() == str2.length()){
		if(str1 < str2){
			swap(str1, str2);
		}
	}

	int n1 = str1.length();
	int n2 = str2.length();

	string str = " ";
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;

	for(int i=0; i<n2; i++){
		int sub = ((str1[i]-'0') - (str2[i]-'0') - carry);

		if(sub < 0){
			sub = sub + 10;
			carry = 1;
		}else carry = 0;

		str.push_back(sub + '0');
	}

	for(int i= n2; i<n1; i++){
		int sub = ((str1[i] - '0') - carry);

		if(sub < 0){
			sub = sub+10;
			carry = 1;
		}else carry = 0;

		str.push_back(sub + '0');
	}

	reverse(str.begin(), str.end());

	return str; 
}

string str_mul(string str1, string str2){
	int len1 = str1.length();
	int len2 = str2.length();
	
	if(len1 == 0 || len2 == 0){
		return "0";
	}

	vector<int> result(len1 + len2 , 0);

	int i_n1 = 0;
	int i_n2 = 0;

	for(int i=len1-1; i>=0; i--){
		int carry = 0;
		int n1 = str1[i] - '0';

		i_n2 = 0;

		for(int j= len2-1; j>=0; j--){
			int n2 = str2[j] - '0';
			int sum = n1*n2 + result[i_n1 + i_n2] + carry;
			carry = sum/10;

			//store result
			result[i_n1 + i_n2] = sum%10;
			i_n2++;
		}

		if(carry > 0)
			result[i_n1 + i_n2] += carry;

		i_n1++;
	}

	int i = result.size() - 1;
	while(i >= 0 && result[i] == 0){
		i--;
	}

	if(i == -1) return "0";
	string s = " ";

	while(i>=0){
		s+= to_string(result[i--]);
	}

	return s;
}


// String division
	
	// method 1
		// let A=9761 and B=2 .Now divide A by B .
		// At first,  remainder = 9%2 = 1 . 
		// Now concatenate next digit 7 | rem = 17 % 2 = 1 
	    // again concatenate 6 | rem = 16 % 2 = 0;
		// again concatenate 1 | rem = 0 + 1 = 1
		
		// ans = 0*10 + 9/2 = 4
		// ans = 4*10 + 17/2 = 48
		// ans = 48*10 + 16/2 = 488
		// ans = 488*10 + 1/2 = 4880 
	
		string a = "9765";
        int b = 2;

        int j = 0;
        if(a[0] == '-') j = 1;

        if(b < 0) b = abs(b);

        ll rem = 0;
        ll ans = 0;
        for( ; j<a.size(); j++){
            rem = rem*10 + (a[j] - '0');
            ans = ans*10 + (rem/b);

            rem %= b;
        } 

        cout << ans << " " << rem << endl;

    // method 2	
	string str_div(string number, int divisor){
		string ans;

		int ind = 0;
		int temp = number[ind] - '0';
		while(temp < divisor)
			temp = temp*10 + (number[++ind] - '0');

		while(number.size() > ind){
			ans += (temp/divisor) + '0';

			temp = (temp % divisor)*10 + number[++ind] - '0';
		}

		if(ans.length() == 0)
			return "0";

		return ans;
	}

	int main(){
		string str1;
		int n;
		cin >> str1 >> n;

		cout << str_div(str1, n);
	}