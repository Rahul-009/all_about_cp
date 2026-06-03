// Leetcode 
// Problem => Subsets
// Link => https://leetcode.com/problems/subsets/description/

// recursion O(n* 2^n)
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets;

void solve(vector<int> &subset, int i, vector<int> &nums){
	if( i == nums.size() ){
		subsets.push_back(subset);
		return;
	}

    //include
    subset.push_back(nums[i]);
    solve(subset, i+1, nums);

    // backtracking
    subset.pop_back();

	//exclude | exclude must come first
	solve(subset, i+1, nums);
}

int main(){
	vector<int> arr = {0};
	vector<int> subset;
	solve(subset, 0, arr);

	for(auto sub: subsets){
		for(auto val: sub){
			cout << val << " ";
		}
		cout << endl;
	}
}

// recursion O(n* 2^n) | space O(1)
