// Binary Search Tree
	// left child smaller than root
	// right child greater than root

// search in O(height) | balanced tree er height = log(nodes)
// so in average O(logn)
// skewed tree te O(n)
// skewed tree = no left child/ no right child | linear almost

// No duplicates allowed
// special case duplicates**


// representation
	struct Node{
	   int data;
	   Node* left;
	   Node* right; 

	   Node(int val){
	      data = val;
	      left = NULL;
	      right = NULL;
	   }
	};

// inorder traversal gives sorted sequence
	void inOrder(Node* root){
	   if(root == NULL) return;

	   inOrder(root->left);
	   cout << root->data << endl;
	   inOrder(root->right);
	}

// Level order traversal (BFS er moto)
	// find k-th level sum (practise)

	void levelOrder(Node* root){
	    if(root == NULL) return;

	    queue<Node*> q;
	    q.push(root);
	    q.push(NULL);

	    while(!q.empty()){
	        Node* node = q.front();
	        q.pop();

	        if(node != NULL){
	            cout << node->data << " ";
	            if(node->left != NULL){
	                q.push(node->left);
	            }
	            if(node->right != NULL){
	                q.push(node->right);
	            }
	        }
	        else if(!q.empty()){
	            q.push(NULL);
	        }
	    }
	}

// Build BST (insert)
	Node* insert(Node* root, int val){
	   if(root == NULL){
	      return new Node(val);
	   }

	   if(val < root->data){
	      root->left = insert(root->left, val);
	   }else{
	      root->right = insert(root->right, val);
	   }

	   return root;
	}

// Search BST O(logn)
	// one comparison per level

	Node* search(Node* root, int key){
	   if(root == NULL) return NULL;

	   if(root->data == key){
	      return root;
	   }

	   if(root->data > key){
	      return search(root->left, key);
	   }

	   return search(root->right, key);
	}
	
	// handle NULL | otherwise error
	if(search(root, 10) == NULL) 
		cout << "Key's doesn't exist" << endl;
   	else cout << "key exists" << endl;

// Delete node
	// case1 - No child (leaf node)
	// case2 - One child
	// case3 - two child**
		// inorder successor diye replace korte hobe 
   		// inorder vabe lekhle jeta delete korbo oitar porer ta
   		// In other word | leftmost in right subtree

   	// returns the leftmost leaf node
   	Node* inorderSucc(Node* root){
	    Node* curr = root;
	    while(curr && curr->left != NULL){
	        curr = curr->left;
	    }
	    return curr;
	}

	Node* deleteBST(Node* root, int key){
	    if(key < root->data){
	        root->left = deleteBST(root->left, key);
	    }
	    else if(key > root->data){
	        root->right = deleteBST(root->right, key);
	    }
	    else{
	        // case 1, 2
	        if(root->left == NULL){
	            Node* temp = root->right;
	            free(root);
	            return temp;
	        }
	        else if(root->right == NULL){
	            Node* temp = root->left;
	            free(root);
	            return temp;
	        }

	        // case 3
	        Node* temp = inorderSucc(root->right);
	        root->data = temp->data;
	        root->right = deleteBST(root->right, temp->data);
	    }
	    return root;
	}

// if a tree is BST or not?
    // 1 2 7 1 0 3 8 | not valid | 7 er child 3, root 4 er cheye choto
    // root er left er kono element root er cheye boro hote parbe na
    // root er right er kono element root er cheye choto hote parbe na

    // approach 1
        // left subtree er max ber korbo
        // right subtree er min ber korbo
        // node > maxleft && node < minright

    // approach 2 O(N)
        // min allowed | max allowed variable rakhbo
        // node e iterate korar somoy check korbo
        // one visit per node
        
    bool isBST(Node* root, Node* min=NULL, Node* max=NULL){
        if(root == NULL) return true;

        if(min != NULL && root->data <= min->data){
            return false;
        }

        if(max != NULL && root->data >= max->data){
            return false;
        }

        bool leftValid = isBST(root->left, min, root);
        bool rightValid = isBST(root->right, root, max);

        return leftValid && rightValid;
    }


// build balanced BST from ordered array
    //1. make middle element root
    //2. recursively do the same for subtrees
        //a. start to mid-1 for left subtree
        //b. mid+1 to end for right subtree

	Node* buildBST(int arr[], int start, int end){
	    if(start > end) return NULL;

	    int mid = (start + end) / 2;
	    Node* root = new Node(arr[mid]);

	    root->left = buildBST(arr, start, mid-1);
	    root->right = buildBST(arr, mid+1, end);

	    return root;
	}

// print in range (x to y)
	// case1 - x<=root<=y
	// case2 - x>root
	// case3 - y<root

// root to leaf paths
	// like preorder
	// array nibo traverse korbo dhukabo
	// leaf e gele print kore dibo | return korbo array theke remove korbo


// print all BST's for n 
	// n=3, BST=5 | n=4, BST=14 | catalan number
	// N given, how many BST can be constructed |

	vector<Node*> constructTrees(int start, int end){
	    vector<Node*> trees;
	    if(start > end){
	        trees.push_back(NULL);
	        return trees;
	    }

	    // catalan stuff is here O(n^n)
	    for(int i=start; i<=end; i++){
	        vector<Node*> leftSubtrees = constructTrees(start, i-1);
	        vector<Node*> rightSubtrees = constructTrees(i+1, end);

	        for(int j=0; j< leftSubtrees.size(); j++){
	            Node* left = leftSubtrees[j];
	            for(int k=0; k<rightSubtrees.size(); k++){
	                Node* right = rightSubtrees[k];
	                Node* node = new Node(i);
	                node->left = left;
	                node->right = right;

	                trees.push_back(node);
	            }
	        }
	    }

	    return trees;
	}

// zigzag traversal
    // 1 2 3 0 4 0 5 6 7 0 0
    // 1 3 2 0 4 0 5 0 0 7 6

    // after each step direction change | 
    // 1st step - left to right | 2nd step right to left | ....

    // Approach O(n)
        // use 2 stacks - currentLevel & nextLevel
        // variable to store direction | leftToRight bool
        // if leftToRight, push left child then right
        // else push right then left
        // after each level stacks will swap

    void zigzag(Node* root){
        if(root == NULL) return;

        stack<Node*> currLevel;
        stack<Node*> nextLevel;

        bool leftToRight = true;

        currLevel.push(root);

        while(!currLevel.empty()){
            Node* temp = currLevel.top();
            currLevel.pop();

            if(temp){
                cout << temp->data << " ";

                if(leftToRight){
                    if(temp->left){
                        nextLevel.push(temp->left);
                    }
                    if(temp->right){
                        nextLevel.push(temp->right);
                    }
                }

                else{
                    if(temp->right){
                        nextLevel.push(temp->right);
                    }
                    if(temp->left){
                        nextLevel.push(temp->left);
                    }
                }
            }
            if(currLevel.empty()){
                leftToRight = !leftToRight;
                swap(currLevel, nextLevel);
            }
        }
    }

// Identical BST
    // check if 2 BST's are same or not
    // both structure and values must be same

    //1. If both empty return true
    //2. If both non-empty,
        // a. check that hte data at nodes is equal
        // b. check if left subtrees are same
        // c. check if right subtrees are same
    //3. If (a, b, c) are true, return true
        // else return false

    bool isIdentical(Node* root1, Node* root2){
        if(root1 == NULL && root2 == NULL){
            return true;
        }

        else if(root1 == NULL || root2 == NULL){
            return false;
        }

        else{
            bool cond1 = root1->data == root2->data;
            bool cond2 = isIdentical(root1->left, root2->left);
            bool cond3 = isIdentical(root1->right, root2->right);
        
            if(cond1 && cond2 && cond3) return true;
            else return false;
        }
    }

// largest BST in a Binary Tree
    
    // approach
        // store 5 info for each node
        // 1. min in subtree
        // 2. max in subtree
        // 3. subtree size
        // 4. size of largest BST
        // 5. isBST bool
    // traverse in a bottom-up manner & find out the size of largest BST
    // from leaf to root level by level


    struct info{
        int size;
        int max;
        int min;
        int ans;
        bool isBST;
    };

    info largestBST(Node* root){
        if(root == NULL) return {0, INT_MIN, INT_MAX, 0, true};

        if(root->left == NULL && root->right == NULL){
            return {1, root->data, root->data, 1, true};
        }

        info left = largestBST(root->left);
        info right = largestBST(root->right);

        info curr;
        curr.size = (1 + left.size + right.size);

        if(left.isBST && right.isBST && left.max < root->data && right.min > root->data){
            curr.min = min(left.min, right.min);
            curr.max = max(left.max, right.max);

            curr.ans = curr.size;
            curr.isBST = true;
            return curr;
        }

        curr.ans = max(left.ans, right.ans);
        curr.isBST = false;

        return curr;
    }

// restore BST
    // 1 2 3 4 5 6 7 8
    // 1 8 3 4 5 6 7 2

    // BST er 2ta value swap kora thakbe | Now that's not BST | we have to make it BST again
    
    // approach
        // maintain 3 pointers first, last, mid
            // first : previous node where 1st number < previous [8]
            // mid : number where 1st number < previous [3]
            
        // 1. swapped elements are not adjacent to each other
            // last : 2nd node where number < previous [2]
            // swap first with last
        // 2. swapped elements are adjacent to each other
            // last : NULL
            // swap first and mid