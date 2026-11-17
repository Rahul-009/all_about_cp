// print all element in queue without removing any
    // O(n) solution

    // O(1) solution

// queue reversal
    // using array

    // using stack

// reverse first K element
    // using 1 stack
        // push first K element in stack
        // find the size of queue
        // push the stack in queue
        // pop the remaining from front and push to end

// Time needed to buy tickets | provide 1 ticket at a time

// First negative integer in every window of size K
    // using queue O(n*k)
    int display(queue<int> q){
        while(!q.empty()){
            if(q.front() < 0){
                return q.front();
            }
            q.pop()
        }
        return 0;
    }
    queue<int> q;
    for(int i=0; i<k-1; i++){
        q.push(arr[i]);
    }
    vector<int> ans;
    for(i=k-1; i<n; i++){
        q.push(arr[i]);
        ans.push_back(display(q));
        q.pop();
    }
    return ans;

    // O(n) solution using queue
    queue<int>q;
    for(int i=0; i<k-1; i++){
        if(arr[i] < 0) q.push(i)
    }
    vector<int> ans;
    for(int i = k-1; i<n; i++){
        // push negative only
        if(arr[i] < 0) q.push(i);
        
        if(q.empty()) 
            ans.push_back(0);
        else{
            if(q.front() < i-k) q.pop();
            if(q.empty()) ans.push_back(0);
            else ans.push_back(arr[q.front()]); // q.front e as hobe
        }
    }

// First not repeating char in stream of characters
    string ans = "";
    vector<int> repeated(26, 0);
    queue<char> q;

    for(int i=0; i<str.size(); i++){
        // repeated
        if(repeated[str[i]-'a'] >= 1){
            repeated[str[i]-'a']++;

            while(!q.empty() && repeated[q.front()-'a']>1) 
                q.pop()
            if(q.empty()){
                ans+='#';
            }else ans+=q.front();
        }
        // non repeated
        else{
            repeated[str[i]-'a']++;
            q.push(str[i]);
            while(repeated[q.front()-'a']>1)
                q.pop();
            ans+=q.front();
        }
        
    }

// sliding window maximum (leetcode 239)
    deque<int> d;
    vector<int> ans;

    for(int i=0; i<k-1; i++){
        if(d.empty()) d.push_back(i);
        else{
            while(!d.empty() && nums[i] > nums[d.back()])
                d.pop_back();
            d.push_back(i)
        }
    }
    for(int i=k-1; i<n; i++){
        // remove smaller element from back and push current one
        while(!d.empty() && nums[i] > nums[d.back()])
            d.pop_back();
        d.push_back(i);

        // front outside window | pop
        if(d.front() <= i-k) d.pop_front();

        // find ans
        ans.push_back(nums[d.front()]);
    } 

// Minimum Number of K Consecutive Flip bits
    queue<int> q;
    int flip=0;

    for(int i=0; i<nl i++){
        if(q.front()<i) q.pop();
        if(q.size()%2 == nums[i]){
            if(i+k-1 >= n) return -1;
            q.push(i+k-1);
            flip++;
        }
    }
