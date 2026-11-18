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

// permutations (leetcode )
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
    void permut(vector<int> &arr, vector<vector<int>> &ans, int index){
        if(index == arr.size()){
            ans.push_back(arr);
            return;
        }

        for(int i=index; i<arr.size(); i++){
            swap(arr[i], arr[index]);
            permut(arr, ans, index+1);
            swap(arr[i], arr[index]);
        }
    }

// permutations II | with duplicate (leetcode )
    // negative num from 0 to 9 | pos 10 for 0
    // positive num from 11 to 19
    void permut(vector<int> &arr, vector<vector<int>> &ans, int index){
        if(index == arr.size()){
            ans.push_back(arr);
            return;
        }
        vector<bool> use(21, 0);
        for(int i=index; i<arr.size(); i++){
            if(use[arr[i] + 10] == 0){
                swap(arr[index], arr[i]);
                permut(arr, ans, index+1);
                swap(arr[index], arr[i]);
                use[arr[i]+10] = 1;
            }
        }
    }

// ways to sum n
    int way(int arr[], int m, int sum){
        if(sum == 0) return 1;
        if(sum < 0) return 0;
        
        int ans = 0;
        for(int i=0; i<m; i++){
            ans += way(arr, m, sum-arr[i]);
        }
        return ans;
    }

// Tower of hanoi

// josephus problem

// combination sum
    // method 1
    void solve(vector<int>& candidates, int target, int n, int index, vector<vector<int>> &ans, vector<int> &temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0) return;

        for(int i=index; i<n; i++){
            temp.push_back(candidates[i]);
            solve(candidates, target-candidates[i], n, i, ans, temp);
            temp.pop_back();
        }
    }

    // method 2 =>
    void solve(vector<int>& candidates, int target, int n, int index, vector<vector<int>> &ans, vector<int> &temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0 || index == n) return;

        // include
        temp.push_back(candidates[index]);
        solve(candidates, target-candidates[index], n, index+1, ans, temp);
        temp.pop_back();
        // exclude
        solve(candidates, target, n, index+1, ans, temp);
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();

        solve(candidates, target, n, 0, ans, temp);

        return ans;
    }
// combination sum II
    void solve(vector<int>& candidates, int target, int n, int index, vector<vector<int>> &ans, vector<int> &temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0 || index == n) return;

        // include
        temp.push_back(candidates[index]);
        solve(candidates, target-candidates[index], n, index+1, ans, temp);
        temp.pop_back();

        // exclude all index of a single number
        while(index+1 < candidates.size() && candidates[index] == candidates[index + 1]) index++;

        // exclude
        solve(candidates, target, n, index+1, ans, temp);
        
    }

// combination sum III
    void solve(vector<int>& candidates, int target, int size, int index, vector<vector<int>> &ans, vector<int> &temp, int count, int k){
        if(count > k) return;
        if(count == k && target == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0 || index == size) return;

        // include
        temp.push_back(candidates[index]);
        solve(candidates, target-candidates[index], size, index+1, ans, temp, count+1, k);
        temp.pop_back();
        

        // exclude all index of a single number
        while(index+1 < candidates.size() && candidates[index] == candidates[index + 1]) index++;
        
        // exclude
        solve(candidates, target, size, index+1, ans, temp, count, k);
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int size = candidates.size();
        int count = 0;
        solve(candidates, n, size, 0, ans, temp, count, k);

        return ans;
    }

// Elimination Game
    // method 1
    int lastRemaining(int n) {
        bool left = true;
        int head=1, step=1, remain=n;
        while(remain>1){
            if(left || remain&1){
                head += step;
            }
            step *= 2;
            remain /= 2;
            left = !left;
        }
        return head;
    }

    // method 2 => recursive
    int lastRemaining(int n) {
        if (n == 1) return 1;
        return 2 * (n / 2 + 1 - lastRemaining(n / 2));
    }