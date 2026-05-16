// stack can be implemented in two way

// using vector
	// all operations O(1) | sometime vector resize korar jonno time lage
	// faster 
	// more space efficient
	
	// stl 
	stack< int, vector<int> > stckk; 
		// now we can use all the functions of stack


	// without stl
	struct stack{
		vector<ll> s;

		void push(ll x){
			s.push_back(x);
		}		

		ll pop(){
			ll res = s.back();
			s.pop_back();
			return res;
		}

		bool empty(){
			return s.empty();
		}

		ll top(){
			return s.back();
		}
	}
	
// using singly linked list
	// front == top
	// O(1) in all cases

	// back == top
	// pop() will become O(n)
	typedef struct node Node;
	struct node{
		int data;
		Node* left;
		Node* right;
	};

	Node* head;
	void push(int x){

	}

	int pop(){

	}

	int top(){

	}

	bool empty(){

	}

// Sum of all subarrays O(N)
	int main(){

        fast_io;

        int n;cin >> n;

        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        int left[n], right[n];

        stack<pair<int, int>>s1, s2;

        for(int i=0; i<n; i++){
            int cnt = 1;

            // current element stack top er cheye choto hole remove korbo
            while(!s1.empty() && (s1.top().first) > arr[i]){
                cnt += s1.top().second;
                s1.pop();
            }

            s1.push({arr[i], cnt});
            left[i] = cnt;
        }

        for(int i=n-1; i>=0; i++){
            int cnt = 1;

            while(!s2.empty() && (s2.top().first) >= arr[i]){
                cnt += s2.top().second;
                s2.pop();
            }

            s2.push({arr[i], cnt});
            right[i] = cnt;
        }

        int result = 0;

        for(int i=0; i<n; i++)
            result = (result + (arr[i] * left[i] * right[i]));

        cout << result << endl;
    }