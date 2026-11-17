// yt resource => 
// coder army => https://youtu.be/-wqKvpYGg1I?si=fswFfWIBygvT9NYy

// problem solving approach | makes a sequence of choice 
// each of which looks best at that moment | aims to find global optimal solution

// min number of coin (gfg)
    int currency[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

    int notes = 0; i=0;
    vector<int> ans;

    while(N){
        notes = n/currency[i];
        while(notes--){
            ans.push_back(currency[i]);
        }
        n %= currency[i];
        i++;
    }
    return ans;

// shop in candy store (gfg)
    sort(candies, candies+N);
    int min_amount = 0; max_amount=0;
    int i=0; j = N-1;

    while(i<=j){
        min_amount += candies[i];
        i++; j-=k;
    }

    i = N-1, j=0;

    while(i>=j){
        max_amount+=candies[i]
        i--; j+=k;
    }

// assign mice to holes (gfg)
    sort(M, M+N);
    sort(H, H+N);

    int ans = INT_MIN;
    for(int i=0; i<N; i++){
        ans = max(ans, abs(M[i]-H[i]));
    }

    return ans;

// minimum rotation to unlock a circular lock (gfg)
    int ans = 0;
    int first, second;

    while(R){
        first = r%10;
        second = d%10;

        r/=10;
        d/=10;

        ans += min(abs(first-second), 10-abs(first-second))
    }

// N meeting in one room
    // sort on end time
    bool comp(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }

    vector<pair<int, int>> timer;
    for(int i=0; i<n; i++){
        timer.push_back({start[i], end[i]});
    }
    sort(timer.begin(), timer.end(), comp);

    int total = 0;
    for(int i=1; i<timer.size(); i++){
        if(timer[i-1].second < timer[i].first){
            total++;
        }
    }

// Job sequencing problem (gfg)
    // O(n^2)
    sort(arr, arr+n, comp);
    int deadline = 0;
    for(int i=0; i<n; i++){
        deadline = max(deadline, arr[i].dead);
    }
    vector<bool> task(deadline+1, 0);
    vector<int> ans(2, 0);

    // pick task one by one
    for(int i=0; i<n; i++){
        // can I complete the task before deadline
        for(int j=arr[i].dead; j>0; j--){
            if(!task[j]){
                task[j] = 1;
                ans[0]++;
                ans[1] += arr[i].profit;
                break;
            }
        }
    }
    return ans;

    // O(nlogn)
    int find(int num, vector<int> &parent){
        if(num == parent[num])
            return num;
        
        return parent[num] = find(parent[num], parent);
    }

    sort(arr, arr+n, comp);
    int deadline = 0;
    for(int i=0; i<n; i++){
        deadline = max(deadline, arr[i].dead);
    }

    vector<int>parent(deadline+1);
    for(int i=0; i<=deadline; i++){
        parent[i] = i;
    }
    vector<int> ans(2, 0);

    // pick each task one by one
    for(int i=0; i<n; i++){
        int slot = find(arr[i].dead, parent);
        if(slot>0){
            ans[0]++;
            ans[1]+=arr[i].profit;
            parent[slot] = slot-1;
        }
    }

// single threaded CPU (leetcode 1834)
    // sort the array on the basis of enqueue time

    // timer = first task enqueue time
        // push all the task into min heap whose (enqueue time <= timer)
        // if min_heap is empty | timer = enque time of next task
        // pop the element
        // print the order
        // increase the timer | timer += processing_time
    
    vector<int> ans;
    int n = tasks.size();
    for(int i=0; i<n; i++){
        tasks[i].push_back(i);
    }
    // sort the task on the basis of enqueue time
    sort(tasks.begin(), tasks.end());
    int timer = tasks[0][0];
    int i=0;

    // {processing time, index}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    
    while(!pq.empty() || i<n){
        // put all the task into min heap whose enqueue time is less than timer
        while(i<n && timer>=tasks[i][0]){
            pq.push({tasks[i][1], tasks[i][2]});
            i++;
        }
        // if min heap is empty
        if(pq.empty()){
            timer = task[i][0];
        }
        // not empty
        else{
            ans.push_back(pq.top().second);
            timer += pq.top().first;
            pq.pop();
        }
    }

// Fractional Knapsack (gfg)
    bool comp(Item a, Item b){
        return a.value*b.weight > b.value*a.weight;
    }

    sort(arr, arr+n, comp);
    double profit = 0;
    int i=0;
    while(w && i<n){
        if(w >= arr[i].weight){
            profit += arr[i].value;
            w -= arr[i].weight;
        }else{
            double temp = arr[i].value;
            temp /= arr[i].weight;
            profit += temp*w;

            w = 0;
        }
        i++;
    }
    return profit

// Non overlapping interval (leetcode 435)
    // sort by end time

// Insert overlapping (leetcode 57)

// Task Scheduler (leetcode 621)
    vector<int> freq(26, 0);
    int count = 0;
    for(int i=0; i<n; i++){
        freq[tasks[i]-'A']++;
        count = max(count, freq[tasks[i]-'A']);
    }

    int ans = (count-1)*(n+1);
    for(int i=0; i<26; i++){
        if(freq[i] == count) ans++;
    }

    return ans>tasks.size() ? ans: tasks.size();
// huffman coding (gfg)
     
