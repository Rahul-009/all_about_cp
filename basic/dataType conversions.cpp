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
	// integer theke character e convert korte '0' add kora lagbe

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

		// solution 2 - only works for small array
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

		stoi(finalNumber); 

// string to array

// binary to decimal

// decimal to binary
	int a[32], n, i;	
	cin >> n;

	for(i=0; n>0; i++){
		a[i] = n%2 ;
		n = n/2;
	}

	// a[n] etar reverse korle binary form pabo

	for(i=i-1; i>=0; i--){
		cout << a[i];
	}



