#include <bits/stdc++.h>
using namespace std;

//check syntax online
	// find_if
	// find_if_not

int main(){


// *** IMPORTANT ****
	// size() function returns unsigned int
	// this causes problem in several cases | check it out


//STRING
	string s0 ("Initial string");// value init constructor
	string s2 (s0);//copy constructor
	string s3 (s0.begin(),s0.begin()+7);
	string s4 (10,'x');
	string s5 (10,42);
	string s6 (s0, 8, 3);
	string s7 ("Another character sequence",12);

	s6.push_back('i'); // only char append
	s6 += "ng";

	transform(); // tolower, toupper er jonno use hoy, check syntax online
//PAIR
	pair<string, double> product1;
	pair<string, double> product2 ("tomatoes",2.30); // value init constructor
	pair<string, double> product3 (product2); //copy constructor
	pair<string, double> product4 = make_pair("light",0.91);
	auto product5 = make_pair("lightbulbs",0.99);// Use of auto

	product1.first = "shoes";
	product1.second = 39.90;

	product2 = {"rahul", 20};

//TUPLE
	//Contiguous memory(can be more than 2)
	//data type can be different


	tuple<string, int, int> t1;
	tuple<string, int, int> t2("test2", 1, 2);
	tuple<string, int, int> t3(t1); // t1 , t3 er shob position er datatype same hote hobe
	tuple<int, int, int> t4 = {1, 2, 3};
	tuple<int, int, string> t5 = make_tuple(1, 2, "test5");
	auto t6 = make_tuple(2, 10, "test5"); // ager line er shortcut
	
	t2 = {"test", 4, 10};
	get<1>(t2) = 3;

	int a, b;
	string c;
	tie(a, b, c) = t5;

	tie(a, ignore, c)=t6;

	cout << get<0>(t2) << " " << get<1>(t2) << " " << get<2>(t2)<<endl;  	

	//Some tuple tricks
		int x, y, z;
		tie(x, y, z)= make_tuple(1, 2, 3); // quickly assign multiple variables
		tie(x, y)= make_tuple(y, x); // swapping 2 variables

	//lexicographically compares the values in the tuple
	//size of tuple and type should be same

	tuple<int, int, int> tup1 = {1, 2, 3};
	tuple<int, int, int> tup2 = {1, 4, 2}; 	
		
	cout << (tup1 == tup2); 	//0
	cout << (tup1 != tup2);		//1
	cout << (tup1 < tup2);		//1
	cout << (tup1 > tup2);		//0

	// swap tuples
	t1.swap(t3); //size and types must be same

//Structures (user defined data types)
	struct Book {
		string name;
		int page;
		string writer;
	};	

	struct Student {
		string name;
		int roll;
		string cls;
		Book book;
		vector<Book> books;  //vector of structures
	};

	void printBookInfo(Book book){
		cout << book.name << endl;
		cout << book.writer << endl;
		cout << book.page << endl;
	}

	void printStudentInfo(Student student){
		cout << student.name << endl;
		cout << student.roll << endl;
		cout << student.cls << endl;
		printBookInfo(student.book);
		cout << endl;
	}

	Book book1 = {"EFT", 200, "NCTB"};
	Book book2 = {"Math", 300, "S U Ahmed"};
	
	Student student1 = {"rahul", 10, "XII"};
	Student student2 = {"samir", 11, "XII"};
	student1.book = book1;
	student2.book = book2;

	student1.books.push_back(Book());   // default constructor diye initialize kora jay
	books[0].name =	"english"; 
	books[0].page = 900;
	books[0].writer = "NCTB";

	printStudentInfo(student1);
	printStudentInfo(student2);


//VECTOR

	//Declaration
	vector<int> v;
	vector<int> v2(10,5);				//vector of size 10 with values 5 //O(n)
	vector<int> v3(10);					//vector of size 10 with default values //O(n)
	vector<int> v4(v2);					// copy constructor // O(n)
	vector<int> v5 = v2;				// copies v2 vector in v5 // O(n)
	vector<int> v6 = {1, 2, 3, 4, 5};	//Declare and initialize O(n)


	// vector resize

		//method 1;
		vector<vector<int>> adj;
		vector<bool> vis;
		vector<int> col;

		int main(){
		   fast_io;
		   
		   int n; cin>> n;
		   adj = vector<vector<int>>(n);
		   vis = vector<bool>(n, false);
		   col = vector<int>(n, -1);
		}

		// method 2
		vector<int> vec;
		vec.assign(n, 0);

	//Traverse vector : 3 ways
	for(int i=0; i<v.size(); i++){		//loop
		cout << v[i] << " ";
	}

	for(auto x: v){						//range loop
		cout << x << " ";
	}

	vector<int>::iterator itr = v.begin();
	auto itr = v.begin();				// this is easiear; will use this

	cout << *itr;						//access the value using dereference operator
	cout << *(itr + index);				//O(1) operation bcz iterator is random access
	//vector uses simple array inside ; that's why O(1)

	for(auto itr = v.begin(); itr != v.end(); itr++){
		cout << *itr << " ";			// iterate from beginning to end
		*itr = 10;						// can update the values
	}

	for(auto itr = v.rbegin(); itr != v.rend(); itr++){
		cout << *itr << " ";			// iterate from end to beginning
		*itr = 10;						//can update the values
	}

	for(auto itr = v.begin()){
		cout << *itr << " ";			// constant iterator are faster
		*itr = 10;						// cannot update the values; produce error
	}

	// function basics
	void passByValue(vector<int> vec){
		cout << "Vector is passed by value: O(n)";
	}
	
	void passByReference(vector<int> &vec){
		cout << "Vector is passed by reference: O(1)";
		vec[0] = 10;
	}
	
	void passByReference(const vector<int> &vec){
		vec[0] = 10;  // produce error , const variable change kora jabe na
	}
	
	vector<int> returnVector(){
		int arr[] = {1, 2, 3, 4, 5};				//inside a function array takes memory from stack . stack is cleared when function is returned . Array is lost				
		return arr;									//Not possible to return array
	
		vector<int> v = {1, 2, 3, 4, 5};  			//dynamically allocated array takes memory from heap
		return v;									//possible to return
	}

	// Insertion
	v.insert(v.begin(), value);					//Insert at head O(n)
	v.insert(v.begin() + index, value);			//insert at index O(n)
	v.push_back(value);							//insert at tail O(1) 

	// Remove
	v.erase(v.begin());							//remove head O(n)
	v.erase(v.begin() + index);			//remove index O(n)
	v.pop_back();								//remove tail O(1)

	// Access
	cout << v.front();							//access head O(1)
	cout << v.at(index) << " " << v[index];		//access index O(1)
	cout << v.back();
	cout << *prev(vec.end()) << endl; 			// end() iterator er ager ta							//access tail O(1)

	int sz = v.size();							//returns the size of vector
	bool isEmpty = v.empty()					//check if the vector is empty or not
	v.clear();		//clear the vector completely
	v1.swap(v2);			//swap two vector
	v1.resize(10);		 	//resize the vector to 10
	v1.capacity();		//capacity of vector

	//emplace() == insert()						//inplace insert, efficient when we use object
	//emplace_back() == push_back()				//inplace insert at end


	// O(n)
	distance(itr1, itr2); // calculate the distance between two iterator

	//Use range for loop to take vector as input and update values

	int n; cin >> n;

	vector<int> vec(n);

	for(auto &x: vec) cin >> x;

	for(auto &x: vec) x=10;

	//Vector of pairs
		vector<pair<int, int> > v = {{1,2}, {2,3}, {4,5}};
	

		bool cmp(pair<int, int> a, pair<int, int>b){
		    if(a.first > b.first){
		        return false; 
		        // a boro hole false | mane a pore rakhbe
		        // choto theke boro sort
		    }else if(a.first == b.first){
		    	// 2ta shoman hole second element wise sort korbe
		        if(a.second > b.second){
		            return true;
		            // a boro hole true | means a age rakhbe
		            // boro theke choto
		        }
		        return false;
		    }else{
		        return true;
		    }

		}

		// taking input 
		int n; cin >> n;
		for(int i=0; i<n; i++){
			int x, y;
			cin >> x >> y;

		// 2 ways to insert pair
		v.push_back({x,y});			// better way
		v.push_back(make_pair(x,y));
		}

		// printing values
		for(int i=0; i<v.size(); i++){
			cout << v[i].first << " " << v[i].second<<endl;
		}
		
		for(auto val: v){
			cout << val.first << " " << val.second << endl;
		}

	// 2D array: rows and columns both are fixed

	//Array of vectors: rows are dynamic, but columns are fixed
		vector<int> v[10]; 				// this will make an array of 10 vectors
		
		// taking input
		int N;	
		cin >> N;						// size of array
		vector<int> v[N];
		for(int i=0; i<N; i++){
			int n; cin >> n;			// size of each vector
			for(int j=0; j<n; j++){
				int x; cin >> x;		// elements of vector
				v[i].push_back(x);
			}
		}
	
		// printing elements
		for(int i=0; i<N; i++){
			cout << "size: " << v[i].size() << endl;
			for(int j=0; j<v[i].size(); j++){
				cout << v[i][j] << " ";
			}
			cout << endl;
		}

	//Vector of vectors: rows and columns both are dynamic 
		int N;
		cin >> N;
		vector<vector<int> > v;
		
		// 2D array size fix kora
		vector<vector<int>> vec(n, vector<int>(m)); 

		//using temp vector
		for(int i=0; i<N; i++){
			int n; cin >> n;
			vector<int> temp;
			for(int j=0; j<n; j++){
				int x; cin >> x;
				temp.push_back(x);
			}
			v.push_back(temp);
		}


		for(int i=0; i<N; i++){
			int n; cin >> n;
			v.push_back(vector<int> ());
			for(int j=0; j<n; j++){
				int x; cin >> x;
				v[i].push_back(x);
			}
		}

		for(int i=0; i<N; i++){
			for(int j=0; j<v[i].size(); j++){
				cout << v[i][j] << " ";
			}
			cout << endl;
		}


// LIST (doubly linked list)
	// not contiguous memory like vector
	// that's why pointer operation doesn't work like vector
	// iteration is slower than vector
	// accessing in middle is also slower O(n)

	list<int> list1;		// list of 0 length
	list<int> list2(7);		// list of 7 length

	list.push_back(element);		// insert at end
	list.push_front(element)		// insert at front
	list.pop_back();				// delete from tail
	list.pop_front();				// delete from head
	list.remove(9);					// deletes all 9
	list1.sort();					// merge sorted list
	list1.merge(list2);				// combines 2 list
	list1.reverse();   				// reverse the list

	list<int> :: iterator iter;
	iter = list1.begin();
	cout << *iter << " ";
	iter++; // but iter+2 will not work

	cout << *iter << " ";
	iter ++;
	cout << *iter << " ";


//MAP (red black tree)
	// order wise sort kora lagle map use korbo
	// sorting important na hole unordered map use korbo //O(1)

	map<int, string> m;

	// insertion, access both are O(logn)
	m[1] = "abc";	//O(logn)
	m[5] = "cdc";	
	m[3] = "acd";
	m[6];			//O(logn) key=6, value="" inserted
	m[5] = "cde"; 	// 5 abar insert hobe na!! map er key unique .. 5 er value change hobe

	m.insert({4, "afg"});   // pair insert korte hobe O(logn)

	map<string, string> mp;
	mp["abcd"] = "abcd";  	// O(key.size() * logn)
	//ekhane new key ager shob key er sathe compare kora hoy
	// ejonno log n er sathe string comparison er complexity add hobe
	// string comparison er complexity depends on length

	map<int, string> :: iterator it;
	for(it = m.begin(); it != m.end(); it++){	//O(nlogn)
		cout << (*it).first << " " << (*it).second << endl;

		// it = it + 1;  // it will not work; bcz contiguous memory na 
		// eta sudhu contiguous memory(vector, tuple) e kaaj kore
		// it ++ ;		  // it will work
	}

	for(auto &pr: m){							// O(nlogn)
		cout << pr.first << " " << pr.second << endl;
	}

	auto itr = m.find(7); 		// returns an iterator O(logn) // na paile m.end() return kore
	if(itr == m.end()){			// m.end() segmentation error dey; eta handle korar jonno if lage
		cout << "NO value" << endl;
	}else{
		cout << (*itr).first << " " << (*itr).second << endl;
	}

	// removing element
	m.erase(3);					//erase with key O(logn)
	auto itr5 = m.find(5);
	m.erase(itr5);				//erase with iterator
								// itr5 end() iterator hole error hobe, handle with if

	m.clear();		// deletes all element	

//UNORDERED MAP 
	// When to use?
		//order important na hole unordered list use korbo

	//Difference with map
		//1. valid keys data types	(int , longlong ,string)
		//2. Time complexity	O(1)
		//3. inbuilt implementation (Hash Table)

	unordered_map<pair<int, int>, string> m; //compilation error
	//basic data type er hash function declare kora thake
	//complex data type(vector, set, pair) er hash function declare kora thake na
	// ejonno unordered map e complex data type use kora jay na
	// nije hash function declare kore use kora jabe

//MULTIMAP
	// ekta key er jonno multiple value store korar jonno use hoy
	// implentation - Red Black Tree
	multimap<int, string> m;

	// map use koreo multimap er kaaj kora jay
	// ejonno multimap khub kom use hoy
	map<int, vector<string>> m;  // evabe ekta key te onek value store kora jay

//SET (red black tree)
	// The set stores the elements in sorted order.
	// All the elements in a set have unique values.
	// The value of the element cannot be modified once it is added to the set, though it is possible to remove and then add the modified value of that element. Thus, the values are immutable.
	// Sets follow the Binary search tree implementation.
	// The values in a set are unindexed.
	//set, unordered_set, multiset map familyr motoi same vabe implement kora
	//Just ekhane sudhu value part ta thake na | only key niye chinta korle bakita same
	set<string> s;
	s.insert("abc");		// O(logn)
	s.insert("zsdf");		// O(logn)
	s.insert("bcd");		// O(logn)

	// finding element
	auto it = s.find("abc"); //O(logn)
	if(it != s.end()){
		cout << (*it);
		s.erase(it)
	}else{
		cout << "No value";
	}

	//accessing first and last element
	set<int> s;
	s.insert({1, 2, 3});

	auto it = s.end();
	--->auto it = s.begin()+1; // doesnot work. but works for vector
	auto it2 = s.begin();
	cout << *(--it) << endl;
	cout << *(it2) << endl;


	// printing set
	for(auto it = s.begin(); it != s.end(); it++){
		cout << (*it) << endl;
	}

	for(string value: s){
		cout << value << endl;
	}

//UNORDERED SET (Hash table)
	//similar to unordered_map
	// order doesn't matter; just precedence matter
	unordered_set<string> s;

//MULTISET 
	//similar to multimap
	// priority queue er jaygay use kora jay; easier than priority_queue
	multiset<string> s;
	s.insert("abc"); 	//O(logn)
	s.insert("zsdf");	
	s.insert("bcd");
	s.insert("abc");	// duplicate allowed

	auto it = s.find("abc");  // prothom "abc" er iterator return korbe 
	s.erase(it);			  // sudhu iterator jake point kore oita delete hobe
	s.erase("abc");			  // shob "abc" delete hoye jabe


//STACK (LIFO)
	// recursion internally uses stack
	// balanced paranthesis checking problem
	// NGE problem - Next greater Element
	// operations - push, pop, top
	stack<int> s;
	stack< int, vector<int> > stckk; // stack using vector
	s.push(2);		// inserts in the end
	s.push(3);	
	s.push(4);
	s.push(5);
	while(!s.empty()){	// empty returns boolean
		cout << s.top() << endl; // prints top element
		s.pop(); // removes element from top
	}

//QUEUE (FIFO)
	//breadth first search (graphs)
	//operations - push, pop, front
	queue<string> q;
	q.push("abc");		// inserts at end
	q.push("bcd");
	q.push("efg");
	q.push("cde");
	while(!q.empty()){	// returns boolean
		cout <, q.front()<<endl;	// prints elemet from front
		q.pop();		// removes from front
	}

// PRIORITY QUEUE

	// pq of pairs min heap
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int, int>>> pq;

	//pq of pairs max heap
	priority_queue<pair<int, int>> pq;

	//pq of int min heap
	priority_queue<int , vector<int>, greater<int>> pq;

	//pq of int max heap
	priority_queue<int> pq;

// bitset
	bitset<8> b; // size must be declared before compilation
	bitset<8> a(7) // 7 er binary store hobe
	bitset<8> a(string("1101")) // 00001101

	int x; cin >> x;
	bitset<x> a; // error

	cout << b << endl; // 8 ta zero 

	b.set(); // shob 1 kore dey
	b.set(2); // sudhu 2 index ke 1 korbe
	b.reset();	// shob 0 kore dey
	b.reset(3);
	b.count(); // koyta bit set ase
	b.any(); // kono bit 1 ache kina check kore(return true false)
	b.none(); // shob 0 hole true dey
	b.flip(); // 0 ar 1 swap hobe

	//index array er ulta dik theke count kore
	cout << b[0] << " " << b[1] ;

//ALGORITHMS
	//upper_bound - jei element dibo oitar immediate boro element er location dibe
	//lower bound - jei element dibo oita or oitar che boro element er location dibe
	// vector ar array er jonno upper,lower bound binary search diye implement hoy
		// Array er jonno
			int n; cin >> n;
			int a[n];
			for(int i=0; i<n; i++){
				cin >> a[i];
			}
			sort(a, a+n);				// sort kora thakle O(logn); naile O(n)
			for(int i=0; i<n; i++){
				cout << a[i] << " ";
			}
			cout << endl;
		
			int *ptr = upper_bound(a, a+n, 7); 		
			if(ptr == (a+n)){
				cout << "Not found";
				return 0;
			}
			cout << (*ptr) << endl;
	
		// Vector er jonno
			int n; cin >> n;
			vector<int> a(n);
			for(int i=0; i<n; i++){
				cin >> a[i];
			}
			sort(a.begin(), a.end());
			for(int i=0; i<n; i++){
				cout << a[i] << " ";
			}
			cout << endl;
	
			auto it = upper_bound(a.begin(), a.end(), 26); 	// 26 array te nai ; a.end() return korbe	
			if(it == a.end()){
				cout << "Not found";
				return 0;
			}
			cout << (*it) << endl;

		// map and set er jonno
			// Tree traversal diye implement hoy
		
			set<int> s;
			map<int, int> m;
			for(int i=0; i<(int)(1e6); i++){
				s.insert(rand());
			}
			for(int i=0; i<(int)(1e5); i++){
				auto it = s.lower_bound(rand()); 	//O(logn)
				// auto it = lower_bound(s.begin(), s.end(), 5);  // evabe lekhle O(n) hobe
			}
			cout << (*it) << endl;
		
			//ekhane integer er jonno upper/lower bound ber kora hoise
			// pair, string etc er jonnou kaaj kore

	// min_element
	// max_element
	// accumulate
	// count
	// find
	// reverse
	// prev** | vector er back, front func ase but onnoder(set, map) nai

						// pura duniya ekdike ar array onnodik
						// array		pura duniya
						// a+0			 a.begin()	
						// a+n 			 a.end()
						// pointer 		 iterator

		//vector, string etc
			vector<int> v = {2, 3, 1, 6, 7, 6};	
		
			int min = *min_element(v.begin(), v.end());
			cout << min << endl;
			auto max = max_element(v.begin(), v.end());
			cout << (*max) << endl;
			int sum = accumulate(v.begin(), v.end(), 0); //intial sum 0 
			cout << sum << endl;
			int ct = count(v.begin()+1, v.end(), 2);	//2 koyta ase? count kore
			cout << ct << endl;
			auto it = find(v.begin(), v.end(), 10);		//khuje na paile garbage print kore; if diye handle kora lagbe
			if(it != v.end())
				cout << (*it) << endl;
			else
				cout << "Element not found" << endl;

			sort(v.begin()+2, v.end());		//introsort: heap,insertion,quick 3ta sort eksathe implement kora O(nlogn)
											// jokhon jeta easy oita use kore
			reverse(v.begin()+2, v.end());
		
			for(auto val: v){
				cout << val << " ";
			}
			cout << endl;

		// Array er jonno
			int a[]= {2, 3, 1, 6, 7, 6};	
		
			int min = *min_element(a, a+n;
			cout << min << endl;
			auto max = max_element(a, a+n;
			cout << (*max) << endl;
			int sum = accumulate(a, a+n, 0); //intial sum 0 
			cout << sum << endl;
			int ct = count(a+1, a+n, 2);	//2 koyta ase? count kore
			cout << ct << endl;
			auto it = find(a, a+n, 10);		//khuje na paile garbage print kore; if diye handle kora lagbe
			if(it != v.end())
				cout << (*it) << endl;
			else
				cout << "Element not found" << endl;

			sort(a+2, a+n);  			//O(nlogn)
			reverse(a+2, a+n;
			for(auto val: v){
				cout << val << " ";
			}
			cout << endl;

		//sorting vector of pairs

			bool cmp(const pair<int, int> &a, const pair<int,int> &b){
				return (a.second < b.second);
			}

			bool cmp2(const pair<int, int> &a, const pair<int,int> &b){
				return (a.second > b.second);
			}			

			vector<pair<int, int>> vec;

			// sort by first element
			sort(vec.begin(), vec.end()); 

			//sort in descending order
  			sort(vec.begin(), vec.end(), greater<pair<int,int>>());

			// sort by second element(ascending)
			sort(vec.begin(), vec.end() , cmp); 

			// sort by second element(descending)
			sort(vec.begin(), vec.end() , cmp2);

			// 0 1 2 3 4 5 ... evabe assign korte thake
			// index replicate kora jay shohoje
			iota(vec.begin(), vec.end(), 0);

			//comparator function evabeo lekha jay
			sort(ordp.begin(), ordp.end(), [&](auto x, auto y){return p[x]<p[y];});