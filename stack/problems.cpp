// yt playlist - coder army

// Application
    // reverse array/string
    // history store korte chaile | stack remembers history

// Problems | using stack, memory complexity increases
    // insert at bottom of stack | 2 ta stack lagbe
    // same string in adjacent | remove both
    // valid parenthesis problem
        // method-1 : using stack O(n) space
        bool check(string str){
            stack<char> stk;
            for(int i=0; i<str.size(); i++){
                if(str[i] == '('){
                    stk.push(str[i]);
                }else{
                    if(stk.empty())
                        return false;
                    else{
                        s.pop();
                    }
                }
            }
            return stk.empty();
        }

        // method-2 : O(1) space
        bool check(string str){
            int left = 0;
            for(int i=0; i<str.size(); i++){
                if(str[i] == '(')
                    left++;
                else
                    if(left == 0) return 0;
                    else left--;
            }
            return 0;
        }
    
    // minimum add to make parenthesis valid
        // using stack
        stack<char> st;
        int count = 0;
        for(int i=0; i<str.size(); i++){
            if(str[i] == '()') st.push(str[i]);
            else{
                if(st.empty()) count++;
                else st.pop();
            }
        }
        return count + st.size()

        // without stack
    
    // background string compare
    // print bracket number
        vector<int> bracketNumber(string s){
            int count = 0;
            stack<int> st;
            vector<int> ans;

            for(int i=0; i<s.size(); i++){
                if(s[i] == '()'){
                    count++;
                    st.push(count);
                    ans.push_back(count);
                }else if(s[i] == ')'){
                    ans.push_back(s.top());
                    s.pop();
                }
            }
            return ans;
        }
    
    // get minimum at pop | stack
        stack<int> st;
        for(int i=0; i<n; i++){
            if(i==0) st.push(arr[i]);
            else st.push(min(arr[i], st.top()));
        }
        return st
    
    // next greater element
    // next greater element 2
    // next smaller element
    // smaller element in left
    // greatest element in left

    // Largest Reactangle in histogram
        // next smallest right, next smallest left
        // O(n) + O(n) + O(n) | 3 pass
        vector<int> right(N);
        vector<int> left(N);
        stack<int> st;

        for(int i=0; i<N; i++){
            while(!st.empty()){
                if(height[st.top()] > height[i]){
                    right[st.top()] = i;
                    st.pop();
                }
            }
            st.push(i);

            // for the elements whose next smallest right do not exist
            while(!st.empty()){
                right[st.top()] = n;
                st.pop();
            }
        }

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && height[st.top()] > height[i]){
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);

            while(!st.empty()){
                left[st.top()] = -1;
                st.pop();
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, height[i] * (right[i]-left[i]));
        }
        return ans;

        // method 2 -> O(n) | single pass 
        int ans = 0;
        int index;
        stack<int> st;
        int n = heights.size();

        for(int i=0; i<n; i++){
            while(!st.empty() && height[st.top()] > height[i]){
                index = st.top();
                st.pop();
                if(!st.empty()){
                    ans = max(ans, height[index]*(i - st.top() - 1));
                }
                else ans = max(ans, height[index]*i);
            }
            st.push(i);

            // for the elements whose next smallest right do not exist
            while(!st.empty()){
                index = st.top();
                st.pop();
                if(!st.empty()){
                    ans = max(ans, height[index]*(n-st.top()-1));
                }
                else{
                    ans = max(ans, height[index]*n);
                }
            }
            return ans;
        }
    
    // Maximal Rectangle 
        int largestRectangleInHistogram(){
            int ans = 0;
            int index;
            stack<int> st;
            int n = heights.size();

            for(int i=0; i<n; i++){
                while(!st.empty() && height[st.top()] > height[i]){
                    index = st.top();
                    st.pop();
                    if(!st.empty()){
                        ans = max(ans, height[index]*(i - st.top() - 1));
                    }
                    else ans = max(ans, height[index]*i);
                }
                st.push(i);

                // for the elements whose next smallest right do not exist
                while(!st.empty()){
                    index = st.top();
                    st.pop();
                    if(!st.empty()){
                        ans = max(ans, height[index]*(n-st.top()-1));
                    }
                    else{
                        ans = max(ans, height[index]*n);
                    }
                }
                return ans;
            }
        }

        int ans = 0;
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> height(col, 0);
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(matrix[i][j] == 0){
                    height[j] = 0;
                }else{
                    height[j] += 1;
                }
            }
            ans = max(ans, largestRectangleInHistogram(height))
        }
        return ans;
    
    // The celebrity problem
        stack<int> st;
        for(int i=n-1; i>=0; i++){
            st.push(i);
        }
        while(st.size() > 1){
            if(arr[first][second] && !arr[second][first])
                st.push(second);
            else if(!arr[first][second] && arr[second][first])
                st.push(first);
        }
        if(!st.empty()) return -1;

        int num = st.top();
        st.pop();

        int row = 0, col = 0;
        for(int i=0; i<n; i++){
            row += arr[num][i];
            col += arr[i][num];
        }
        if(row==0 && col==n-1)
            cout << "celebrity" << endl;
        else cout << "not celebrity" << endl;
    
        
    // maximum of minimum for every window size
        // bruteforce O(n^3)
        vector<int> ans(N, 0);
        // i window size | j number of sets
        for(int i=0; i<n; i++){
            for(int j=0; j<n-i; j++){
                int num = INT_MAX;
                for(k=j; k < j+i+1; k++){
                    num = min(num, arr[k]);
                }
                ans[i] = max(ans[i], num);
            }
        }
        // O(n^2) solution
        // O(n) solution
