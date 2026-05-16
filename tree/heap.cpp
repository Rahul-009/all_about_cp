// Reference -
    // https://www.youtube.com/watch?v=NKJnHewiGdc&ab_channel=CodeHelp-byBabbar
    // https://www.programiz.com/dsa/heap-data-structure

// max heap | root always greater than child (apply for all node)
// min heap | root always smaller than child (apply for all node)

// left = 2*i+1 | right = 2*i+2
// parent = i/2
// leaf = (n/2 theke n) | 1 indexed
// leaf = (n/2-1 theke n-1) | 0 indexed 

// same max heap can have multiple configuration
// CBT = complete binary tree

// insert O(logn)
    // CBT er last index e insert korbo
    // compare korbo parent er sathe
    // root e giye thambo

    const int N = 100;
    int arr[N];
    int n, sz;

    void insert(int val){
        int index = sz;
        sz++;
        arr[index] = val;

        while(index > 0){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

// delete O(logn)
    // swap root with last position
    // delete last node
    // propagate root to it's correct position 


    void deleteRoot(){
        if(sz == 0) return;

        // put last element in root index
        arr[0] = arr[sz-1];
        // delete last index
        sz--;

        // take root to correct position
        int i = 0;
        while(i < sz){
            int left = 2*i+1;
            int right = 2*i+2;

            if(arr[i] < arr[left] && left < sz){
                swap(arr[i], arr[left]);
                i = left;
            }
            else if(arr[i] < arr[right] && right < sz){
                swap(arr[i], arr[right]);
                i = right;
            }
            else{
                return;
            }
        }
    }

    void deleteRoot(){
        if(sz == 0) return;

        // put last element in root index
        arr[0] = arr[sz-1];
        // delete last index
        sz--;

        // take root to correct position
        heapify(0);
    }

//1. heapify 
    // converts array to heap
    // we cannot determine if a single node is heap or not
    // that's why we will skip all the leaf nodes

    // Let the input array be 3 9 2 1 4 5
    // Create a complete binary tree (CBT)
    // Start from the first index of non-leaf node(n/2-1)
    // set current element i as largest
    // left child = 2*i+1 | right child = 2*i+2
    // if leftChild > curr | set leftChildIndex = largest
    // if rightChild > curr | set rightChildIndex = largest
    // swap largest with current element
    // repeat 3-7 until heapified

void heapify(int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(arr[left] > arr[largest] && left<n){
        largest = left;
    }
    if(arr[right] > arr[largest] && right<n){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(largest);
    }
}

void buildHeap(int a[], int n){
    for(int i=n/2; i>0; i--){
        heapify(a, n, i);
    }
}

// heapsort O(nlogn)
    // swap first and last element
    // delete last element
    // heapify

    void heapSort(){
        int temp = sz;
        while(temp > 0){
            // swap 1st and last
            swap(arr[0], arr[temp-1]);
            // delete last element
            temp--;

            // heapify
            heapify(0);
        }
    }


// median of running stream
    // continuous input of numbers

    // approach
        // keep 1 maxheap, 1 minheap
        // divide the array in 2 heap
        // new element amon vabe insert korbo jeno heap size difference 1 thake
        // if size not equal top of larger heap is the answer
        // if size equal avg of 2 top is the answer

priority_queue<int , vector<int>, greater<int>> pqmin;
priority_queue<int> pqmax;
    
void insert(int x){
    if(pqmin.size() == pqmax.size()){
        if(pqmax.size() == 0){
            pqmax.push(x);
            return;
        }

        if(x < pqmax.top())
            pqmax.push(x);
        else{
            pqmin.push(x);
        }
    }
    else{

        // 2 cases possible
        // case 1: size of maxHeap > size of minHeap
        // case 2: size of minHeap > size of maxHeap
        
        if(pqmax.size() > pqmin.size()){
            if(x >= pqmax.top()){
                pqmin.push(x);
            }
            else{
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        }
        else{
            if(x <= pqmin.top()){
                pqmax.push(x);
            }
            else{
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }
    }
}

double findMedian(){
    if(pqmin.size() == pqmax.size()){
        return (pqmin.top() + pqmax.top()) / 2.0 ;
    }
    else if(pqmax.size() > pqmin.size())
        return pqmax.top();
    else return pqmin.top();
}