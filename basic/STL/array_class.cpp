#include<bits/stdc++.h>
using namespace std;

void passCArray(int arr[], int n){ 			// arr passed by reference here

	// cout << sizeof(arr)/sizeof(int);	 	//1 bcz arr here is a pointer

	// for(auto &x: arr) cout << x << endl;	//will not work, bcz pointer

	for(int i=0; i<5; i++) cout << arr[i] << " ";
	

}

void passArray1 (array<int, 5> arr){		//size is hard coded
	for(auto &x: arr) cout << x << " "; 	//value of array passed by value: O(n);

	cout << arr.size() << endl;
}	

template<size_t s>							//generic funciton using template
void passArray2(array<int, 5> &arr){		//always try to pass by reference: O(1)
	for(int i=0; i<arr.size(); i++){
		cout << arr[i] << endl
	}
}

int main(){
//Array
	//Contiguous memory, homogenous data, fixed size
	
//Main focus is to understand the difference between cArray and array class
	
	int cArr[5];							//garbage values
	array<int, 5> arr1;						//garbage values

	int cArr2[5] = {};						//values : 0 0 0 0 0
	array<int, 5> arr2 = {};				//values : 0 0 0 0 0

	int cArr3[5] = {1, 2, 3};				//values : 1 2 3 0 0
	array<int, 5> arr3 = {1, 2, 3};			//values : 1 2 3 0 0

	int cArr4[] = {1, 2, 3, 4, 5};			//auto size deduction
	array<int, 5> arr4 = {1, 2, 3, 4, 5};	//can't skip the size

	cArr3 = {1, 2, 3, 4, 5};//not working	//later we have to assign complete list
	arr3 = {1, 2, 3, 4, 5};					// otherwise error


	//size must be known at compile time for array class

	array<int , n> arr; // eta error dibe 
	//stl array er biggest drawback.. ejonno eta use hoy na

	//take memory on stack always

	int n; cin >> n;
	int *cRunTimeArr = new int[n];			//not possible for array class
	delete[] cRunTimeArr;					//heap memory not possible 

	//size of array

	cout << sizeof(cArr)/sizeof(int) <<endl;
	cout << arr.size() << endl;

	//for range loop

	for(int &x: cArr4) cin >> x;			//for input &x must
	for(int x : cArr4) cout << x << " ";	// 1 2 3 4 5
	for(int x : arr4) cout << x << " ";  	

	//Important
	// c style array decayed as pointer
	int *cArr5 = cArr4;						//an array is just an pointer to the first element
											//now cArr5 also points the same location
	cArr5[0] = 10;							//it will update the value for cArr4 also

	for(int i=0; i<5; i++){
		cout << cArr4[i] << " ";			//10 2 3 4 5
	}

	cout << endl;
	cout << sizeof(cArr5)/sizeof(int);   	//1 (cArr5 is a int pointer - 4byte) 4/4=1

	for(int x : cArr5) cout << x << " ";   	//will produce error bcz cArr5 is a pointer
	
	//But array class not decayed as pointer

	array<int, 5> arr5 = arr4;				// a new copy created for arr5 //O(n)
	
	for(int i=0; i<5; i++){
		cout << arr4[i] << " ";				//10 2 3 4 5
	}

	for(int x: arr5) cout << x << " ";

	//passing to function (same as assignment concept)

	passCArray(cArr1, 5);

	passArray1(arr1);

	passArray2(arr1);	


	// array in built functions
	 cout << arr5[1] << endl;				//when index out of range, garbage value or seg fault
	 cout << arr5.at(1) << endl;			//when index out of range, throws exception out_of_range

	 cout << arr5.front() << endl;			// first element
	 cout << arr5.back() << endl;			// last element
	 cout << arr5.empty() << endl;			// check array is empty or not

	 //swap two arrays
	 arr1.swap(arr2);						// O(n)

	 //fill the entire array with any value
	 arr1.fill(1);							// O(n)

	 
	 // Iterator: Random Access iterator for array class
	 // Pointed to an element of a container and has the ability to iterate over the container
	 // 1. begin(), cbegin()		returns an iterator to the beginning
	 // 2. end(), cend()   			returns an iterator to the end
	 // 3. rbegin(), rcbegin()		returns a reverse iterator to the beginning
	 // 4. rend(), cend()			returns a reverse iterator to the end

	 array<int, 5>::iterator itr1 = arr4.begin();
	 auto itr2 = arr4.begin();				// very useful

	 cout << *itr2;							// access value using dereferencing operator

	 for(auto itr = arr4.begin(); itr != arr4.end(); itr++){
	 	cout << *itr2 << " ";				// 1 2 3 4 5
	 	*itr = 10;
	 }

	 for(auto itr = arr4.rbegin(); itr != arr4.rend(); itr++){
	 	cout << *itr << " ";				// 5 4 3 2 1
	 }

	 //constant iterator can not used to update values
	 for(auto itr = arr4.cbegin(); itr != arr4.cend(); itr++){
	 	*itr = 10;							//will produce error
	 }

	 for(auto itr = arr4.rcbegin(); itr != arr4.rcend(); itr++){
	 	*itr = 10;							//will produc error
	 }

// All comparison operators like tuple works on array class also
// lexicographically compares the values in the array
	 
}					
