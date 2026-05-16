// integer theke character e convert korte '0' add kora lagbe
#include<bits/stdc++.h>
using namespace std;

int main(){
	// conversions to master

	// string to integer
		// string num = "1000";
		// int number = stoi(num);

		// cout << number << endl;
		// cout << sizeof(number) << endl;

	// integer to string
		// double number1 = 1000000000000000;
		// string num1 = to_string(number1);
		
		// cout << num1 << endl;

	// integer to character
		// int n = 8;
		// char num3 = 8 + '0';

		// cout << num3 << endl;
		// cout << (int)num3 << endl;
		// cout << sizeof(num3) << endl;

	// character to integer
		// char ch = '8';
		// int n = ch - '0';

		// cout << n << endl;
		// cout << sizeof(n) << endl;

	// array to string
		int arr[] = {1, 6, 0, 2, 2, 0, 0, 0};
		char ch;
		int size = sizeof(arr)/sizeof(int);
		string word = "";

		for( int i=0; i<size; i++){
			ch = arr[i] + '0';
			word += ch;
		}

		cout << word << endl;

		// solution 2 
		int a[] = { 60, 321, 5};

		int finalNumber = 0;
		for(int i=0; i<a.length; i++){
			int num = a[i];
			if(num != 0){
				while(num > 0){
					finalNumber *= 10;
					num /= 10;
				}
				finalNumber += a[i];
			}else{
				finalNumber *= 10;
			}
		}

	// string to array

	// binary to decimal
	// decimal to binary

}


