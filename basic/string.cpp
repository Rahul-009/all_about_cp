// string functions
// resize function
	string s = 'hello world';

	s.resize(5); //hello
	s.resize(20); 
	s.resize(20, '!') // hello world!!!!!!!!!
	s.resize(s.size()+3, '!!!'); //last e 3ta !!! add hobe


//concatenation trick
	string input;
	string overallinput;

	do{
		getline(cin, input);
		overallinput += input;
	}while(input != '!');

	cout << overallinput;

//removing letters
	string s = "abc abc";
	string new_s ;

	//removing 'a'
	//remove all numbers from string
	//remove all character from string
	for(int i=0 ; i<s.size(); i++){
		if(s[i] != 'a'){
			new_s+=s[i];
		}
	}

	cout << new_s << '\n'; // bc bc

//substr(start, count)
	string s = "hello world";
	cout << s.substr(6); // index 6 theke shob nibe ; world
	cout << s.substr(6, 2); // 6 theke 2ta nibe ; wo

//find(string/char, start)
	string s = "abc abc abc";
	cout << s.find("abc"); // 0 ; 0 index ei abc ase
	cout << s.find('b', 3 );// 5 ; 3 theke khujbe

	//keep searching
	int found = -1;
	do{
		found = s.find("abc", found+1); // found+1 value 0 , 1, 5
		if(found != -1)
			cout << "Found "<<found <<endl; // 0 , 4 ,8
	}while(found !=-1);

//find_first_of(string/char, start)
	string s = "abc abc abc";
	cout << s.find_first_of("cba");	// cba er jekono ekta pailei index print kore dibe

//split string

	//strtok(string, delimeter)
	char str[100]= "Learn how to split a string in C++";

	char *ptr;
	ptr = strtok(str, " ");

	cout << ptr; //Learn

	while(ptr != NULL){
		cout << ptr << endl;
		ptr = strtok(NULL, " "); 
	}

	//getline and sstream
	string str = "This is a test";
	stringstream ss(str);
	string temp;

	str = "";

	while(getline(ss, temp, ' ')){
		str += temp;
	}

	cout << str;

	// only sstream
	string str = "This is a test";

	stringstream ss(str);
	string temp;

	ss << str; // another way of storing sstring in sstream
	str = "";

	while(!ss.eof()){
		ss >> temp;
		str = str + temp;
	}
	cout << str;


