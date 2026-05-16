#include<bits/stdc++.h>
using namespace std;

// bits basic
	// AND - both bit 1 (1) ; otherwise (0);
	// OR - both bit 0 (0) ; otherwise 1; 
	// XOR - same bit(0) ; opposite bit(1)
	// right shift - 2 diye vaag
	// left shift - 2 diye gun  1<<n = 2^n
	// complement (~) vs NOT (!)
	// parity | odd no of 1 thakle odd parity


// Reference - https://www.geeksforgeeks.org/builtin-functions-gcc-compiler/
// Builtin functions
	// __builtin_popcount | __builtin_popcountll
	// __builtin_clz() | count leading zeros
	// __builtin_parity() | returns boolean
	// __builtin_ctz() | count trailing zeros
	
	

// 1<<2 0000100    (1<<2)-1 00000011  
// 1<<3 0001000	(1<<3)-1 00000111
// 1<<3 0010000	(1<<4)-1 00001111
void printBinary(int num){
	for(int i=10; i>=0; i--){
		cout << ((num>>i) & 1);
	}
	cout << endl;
}

int main(){
	cout << INT_MAX << endl;

//(1<<32) = 2^32 ; 33 bits ; integer e store hobe na

	// int a = (1<<32)-1 ; // error 33 bit store korte parbe na; so calculation korte parbe na
	// int x = (1LL<<32)-1 ; //ekhane long long e calculation hobe ; store korar somoy overflow ; No error but output ulta palta
	
	int x = (1LL<<31)-1; //ekhane 31 bit store hoitese ; cause signed int
	unsigned int y = (1LL<<32)-1; // ekhane overflow hobe na 
	cout << x << " " << y << endl; // correct output

	int a = 9;
	printBinary(a);
	printBinary(~a);
	printBinary(!a);
	int i =3;

//checking bits

	// for int check first 31 bits | sign bit ase ekta
	// unsigned bit er jonno 32 bit e check korbo
	// 0 indexed | careful

	for(int i=0; i<=30; i++){
		if(a & (1<<i) != 0){
			cout << "set bit\n";
		}else{
			cout << "not set bits\n";
		}
	}


//bit set
	printBinary(a | (1<<2));

//bit unset
	printBinary(a & ~(1<<3));

//toggle
	printBinary(a ^ (1<<3));
	printBinary(a ^ (1<<3));

// counting bits
	unsigned countBits(unsigned int number)
{      
      // log function in base 2 
      // take only integer part
      return (int)log2(number)+1;
}

//counting set bits
	int cnt = 0;
	for(int i=0; i<=31; i++){
		if((a & (1<<i)) != 0){
			cnt++;
		}
	}
	cout << cnt << endl;

	cout << __builtin_popcount(a)<< endl;  // only works for integer
	cout << __builtin_popcountll((1LL << 35)-1) << endl;  // for long long

//XOR tricks
	// a ^ a = 0
	// a ^ 0 = a

	//swapping two values
	int a=4, b=6;
	a = a ^ b;
	b = b ^ a; // here a= a^b
	a = a ^ b; // here a = a^b, b=a 

	//all values of array are even in number except one. find that
	//time O(N) ; space O(1)*

	int n; cin>>n;
	int x;
	int ans = 0;

	for(int i=0; i<n; i++){
		cin >> x;
		ans ^= x;
	}
	cout << ans << endl;
//odd / even
	printBinary(5);
	printBinary(6); // odd, even er difference last bit e

	int x = 5;
	if(x & 1){
		cout << "odd" << "\n";
	}else cout << "even" << endl;

//Upper case - lowercase
	printBinary('B');
	printBinary('b');  // 2tar difference 5th bit e

	char b = 'B' | ' ';
	printBinary(' ');
	char b2 = 'B' | (1<<5); //2^5 = 32 (' ' er ASCII)
	cout << b << "\n";

	printBinary('_');		// 00001011111
	printBinary(~(1<<5));  	// 11111011111
	char B2 = 'b' & (~(1<<5));	
	char B = 'b' & '_' ;  	// etai bhalo
	// karon amader sudhu sesh 7 ta bit lagbe

//Clear LSB
	int a = 59;
	int i = 4;	// 4th bit porjonto LSB clear
	printBinary(a); // 00000111011
	printBinary(~((1<<(i+1))-1)); // 11111100000 (4th bit porjonto 0)
	int l = a & (~((1<< (i+1))-1));
	printBinary(l);

//Clear MSB
	i = 3;	//3rd bit porjonto MSB clear
	printBinary((1<< (i+1))-1);//00000001111
	int m = a & ((1<< (i+1))-1);
	printBinary(m);

//power of 2 ***
	// 2 er power gular binary te 1 ta bit set thake | bakishob 0
	// n (2 er power) | n-1 (ager ta)
	// n = 16 (10000)| n-1 = 15 (1111) | ekta bit kome jaitese
	// int always 32 bit |  15(..001111)

	// n & (n-1)  will be zero for 2 er power

	int n = 16;
	if(n&(n-1)){
		cout << "not power of 2"<< endl;
	}else{
		cout << "power of 2" << endl;
	}


// BIT MASKING //
	Bitmask = bit + mask

//Find the maximum common days between two worker
//for each worker the days are given

// sample input
// 5
// 4
// 1 4 7 9
// 6 
// 2 9 1 7 25 29
// 7 
// 1 23 4 7 9 11 29
// 10
// 2 28 8 7 9 10 30 21 18 19	
// 4 
// 1 11 29 7

	int n; cin >> n;
	vector<int> masks(n,0);
	for(int i=0; i< n; i++){
		int num_workers;
		cin >> num_workers;
		int mask =0;
		for(int j=0; j<num_workers; j++){
			int day;
			cin >> day;
			mask = (mask | (1 << day));
		}
		masks[i] = mask;


			// cout << masks[i] << ' ';
			// printBinary(masks[i]) ;
			// cout << '\n';
	}

	int max_days = 0;
	int person1 = -1;
	int person2 = -1;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int intersection = masks[i] & masks[j];
			int common_days = __builtin_popcount(intersection);
			// cout << i << ' '<< j << ' ' << common_days << '\n';
			if(common_days>max_days){
				max_days = common_days;
				person1 = i;
				person2 = j;
			}
			max_days = max(max_days, common_days);
		}

	}

	cout << person1 << ' ' << person2 << ' ' << max_days << '\n';


//Generating Subsets O(n*2^n)
	//taking input
	int n; cin>>n;
	vector<int> nums(n);
	for(int i=0; i<n; i++){
		cin >> nums[i];
	}

	//generating subsets
	int subset_ct = (1<<n);
	vector<vector<int>> subsets;
	for(int mask=0; mask<subset_ct; mask++){
		vector<int> subset;
		for(int j=0; j<n; j++){
			if((mask & (1<<j)) != 0)
				subset.push_back(nums[j]); 
		}
		subsets.push_back(subset);
	}

	//printing subsets
	for(auto subset: subsets){
		for(auto x:subset){
			cout << x << " ";
		}
		cout << endl;
	}
}