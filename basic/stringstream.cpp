/*
String stream associates astring object with a stream allowing us to read
from the string as if it were a stream.
The string stream class is extremely useful in parsing input

//Basic methods
	-clear() 	to clear the stream
	-str()		to get and set string object whose content is present in the stream
	-extraction (>>) add a string to the stringstream object
	-insertion	(<<) read something from the string stream

*/

#include<iostream>
#include<sstream>
#include<map>
using namespace std;

// counting words in a string
	
	//without string stream

	// using stringstream
	int countWords(string str){
		//breaking input into words using string stream

		//used for breaking words
		stringstream s(str); //constructor

		// to store individual words
		string word;
	
	int count =0;

		// string stream white space paile loop break kore dey
		// as a result shob word er jonno notun iteration start h	oy
		while(s >> word){
			count ++ ;
		}
		return count;

}

// print frequencies of individual words in a string

void printFrequency (string st){
	//Each word is mapped to it's frequency
	map<string, int> m;

	//used for breaking words
	stringstream ss(st);

	// to store individual words
	string word;

	while(ss >> word){
		m[word]++;
	}

	for(auto it=m.begin(); it!= m.end(); it++){
		cout << (*it).first << " " <<(*it).second <<"\n";
	}
}

int main(){
	string input; getline(cin, input);
	stringstream ss;  

	ss.str(input);					// sets the element of the string stream
	string str = ss.str();			// creates string

	cout << str << endl;

	string s = "geeks for geeks ";
	cout << "Number of words are: "<< countWords(s);
	
	cout << endl;
	printFrequency(s);

	return 0;
}
