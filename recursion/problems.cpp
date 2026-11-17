// integer array subsequence (leetcode)
    // method 1
    void subseq(int arr[], int index, int n, vector<vector<int>> &ans, vector<int> temp){
        // base case
        if(index == n){
            ans.push_back(temp);
            return;
        }
        // dont take element
        subseq(arr, index+1, n, ans, temp);
        // take element 
        temp.push_back(arr[index]);
        subseq(arr, index+1, n, ans, temp);

        // temp.pop_back();
    }

    // method 2
    void subseq(int arr[], int index, int n, vector<vector<int>> &ans, vector<int> &temp){
        // base case
        if(index == n){
            ans.push_back(temp);
            return;
        }
        // take element 
        temp.push_back(arr[index]);
        subseq(arr, index+1, n, ans, temp);

        // dont take element
        temp.pop_back(arr[index]);          // backtrack
        subseq(arr, index+1, n, ans, temp);
    }

    int main(){
        int arr[] = {1, 2, 3};
        vector<vector<int>> ans;
        vector<int> temp;

        subseq(arr, 0, n, ans, temp);
    }

// string subsequence
    void subset(string &s, int index, int n, vector<string> &ans, string temp){
        if(index == n){
            ans.push_back(temp);
            return;
        }
        // dont take char
        subset(s, index+1, n, ans, temp);

        // take char
        temp.push_back(s[index]);
        subset(s, index+1, n, ans, temp);
        temp.pop_back();
    }

// parenthesis (leetcode)
    // right can never be greater than left
    void parenthesis(int n, int left, int right, vector<string> &ans, string &temp){
        if(left + right == 2*n){
            ans.push_back(temp);
            return;
        }
        // take left
        if(left < n){
            temp.push_back('(');
            parenthesis(n, left+1, right, ans, temp);
            temp.pop_back();
        }
        // take right
        if(right < left){
            temp.push_back(')');
            parenthesis(n, left, right, ans, temp);
            temp.pop_back();
        }
    }

// subset sum
    void print(int arr[], int index, int n, int sum, vector<int> &ans){
        // base case
        if(index == n){
            ans.push_back(sum);
            cout << sum << endl;
            return;
        }
        // dont take element
        subseq(arr, index+1, n, sum);

        // take element 
        subseq(arr, index+1, n, sum + arr[index]);
    }

    int main(){
        int arr[] = {1, 2, 3, 4};
        vector<int> ans; // store korar dorkar na thakle skip
        print(arr, 0, 4, 0, ans);
    }

// target subset sum
    bool find(int arr[], int n, int index, int target){
        if(target == 0) return 1;
        if(index == n || target < 0) return 0;

        return find(arr, index+1, n, target) || find(arr, index+1, n, target);
    }

    int main(){
        int arr[] = {2, 4, 1, 8, 7};
        int target = 13;
        cout << find(arr, 0, 5, target) << " ";
    }

// perfect sum problem (gfg)
    int subset(int arr[], int n, int index, int sum){
        if(sum == 0) return 1;
        if(index == n || sum < 0) return 0;

        return subset(arr, index+1, n, sum)  + subset(arr, index+1, n, sum);
    }

    int subset(int arr[], int n, int index, int sum){
        if(index == n){
            if(sum == 0) return 1;
            else return 0;
        }

        return subset(arr, index+1, n, sum)  + subset(arr, index+1, n, sum);
    }

// target sum with repetition(one number can be used multiple times)
    int subSum(int arr[], int index, int n, int sum){
        if(sum == 0) return 1;
        if(index == n || sum < 0) return 0;

        // dont take and move to next element || keep taking the element again and again
        return subSum(arr, index+1, n, sum) + subSum(arr, index, n, sum-arr[index]);
    }

// permutations
    // method 1
    void permut(int arr[], int n, vector<vector<int>> &ans, vector<int> &temp, vector<bool> &vis){
        if(arr.size() == temp.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<arr.size(); i++){
            if(vis[i] == 0){
                vis[i] = 1;
                temp.push_back(arr[i]);
                permut(arr, ans, temp, vis);

                // backtrack
                vis[i] = 0;
                temp.pop_back();
            }
        }
    }

    // method 2 => without temp and vis