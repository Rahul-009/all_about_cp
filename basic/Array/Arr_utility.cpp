#include<bits/stdc++.h>
using namesapce std;

// finding min and max from array
void getMinMax(int arr[],int n){
	// finding minimum value
	int min = 1e9;
	for(int i=0; i<=n ; i++){
		if(arr[i]<min){
			min = arr[i];
		}
	}
	cout <<"min = "<<min <<'\n';

	// finding maximum value
	int max = 0;
	for(int i=1; i<=n ; i++){
		if(arr[i]>max){
			max = arr[i];
		}
	}
	cout <<"max = "<<max <<'\n';
}

void getMinMax2(int arr[],int n){
	int mx=0;
	for(int i=1; i<=n; i++){
		mx = max(mx,arr[i]);
	}
	cout << mx << '\n';

	int mini = (int)1e9;
	for(int i=1; i<=n; i++){
		mini = min(mini,arr[i]);
	}
	cout << mini << '\n';
}

//Sum of array
int sumArray(int arr[],int n){
	int sum = 0;
	for(int i=1 ; i<=n ; i++){
		sum += arr[i];
	}

	return sum;
}

// Reverse Array
void reverseArray(int arr[],int n){
	int start = 0 , end = n-1;
	while(start<end){
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

// Reverse with recursion
void reverseArray(int arr[],int start,int end){
	if(start>=end) return;
	
	int temp = arr[start];
	arr[start] = arr[end];
	arr[end] = temp;

	reverseArray(arr,start+1,end-1);
}

//printting max frequency O(n^2)
void maxFrequency(int arr[],int n){
	int mx=0;
	for(int val=1 ; val<=n ; val++){
		int cnt = 0;
		for(int j=1 ; j<=n ; j++){
			if(arr[val] == arr[j]){
				cnt++;
			}
		}
		mx = max(mx,cnt);
	}
	cout << max << '\n';
}

//printting max frequency O(n)
void maxFrequency2(int arr[],int n){
	int mx=0 ;
	for(int i=1 ; i<=n ; i++){
		cnt[arr[i]]++ ;
	}
	for(int i=1; i<=100; i++){
		mx = max(mx,cnt[i]);
	}	
	cout << mx << '\n';
}

//print all frequency o(n^2)
void countFreq(int arr[],int n){
	vector<bool> visited(n,false);

	for(int i=1; i<=n; i++){
		if(visited[i]==true) continue;

		int cnt = 1;
		for(int j=0; j<=n; j++){
			if(arr[i]==arr[j]){
				cnt++;
				visited[j]=true;
			}
		}
		cout << arr[i] << " "<< cnt <<'\n'; 
	}
}

//print all frequency using map (space kom lage map e)
// O(n)
void countFreq2(int arr[], int n){
	unordered_map<int, int> mp;

	for(int i=1; i<=n; i++){
		mp[arr[i]]++;
	}


	for(auto x : mp){
		cout << x.first << " " << x.second << endl;
	}
}

//Pallindrome
void Pallindrome(string str){
	int l=0;
	int h= str.size() - 1;

	while(h > l){
		if(str[l] != str[h]){
			cout<< "False"<< endl;
			return;
		}
		l++;
		h--;
	}
	cout<< "True"<< endl;
}

void pallindrome2(string str){
	string r=""; //empty string assign na korle garbage assign hoye jabe
	int n=str.size();
	for(int i=n-1; i>=0; i--){
		r.push_back(str[i]);
	}
	if(str==r){
		cout << "Yes"<< '\n';
	}else{
		cout<< "No"<< '\n';
	}
}

void pallindrome3(string str){
	string r = str;
	int n = str.size();

	reverse(r.begin(), r.end());
	if(str==r){
		cout << "Yes"<< '\n';
	}else{
		cout<< "No"<< '\n';
	}
}

//pallindrome with recursion
string is_pal(string s, int start, int end){
	if(start == end){
		return "YES";
	}

	if(s[start] != s[end]){
		return "NO";
	}

	if(start < end) return is_pal(s, start+1, end-1);

	return "YES";
}

int main(){
	int n, x;
	int arr[];

	// taking input in array
	for(int i=1 ; i<=n ; i++){
		cin >> arr[i];
	}

	// output every element
	for(int i=0 ; i<=n ; i++){
		cout << arr[i];
	}

	// taking unlimited input
	int n=0;
	while(cin >> x){
		arr[n++] = x ;
	}

}