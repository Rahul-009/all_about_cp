// BINARY TREE
	//max 2 children (2 er kom thakte parbe)

	// full binary tree
	// complete binary tree

// Hierarchical data structure
// Leaf, Branch, Tree
// Level & subtree
// height of tree = root to deepest leaf distance
// height = longest path length from root
// depth


// linked list representation
	// struct node root = new node(1); | evabe node banate hobe
struct node{
   int data;
   Node* left;
   Node* right; 

   node(int val){
      data = val;
      left = NULL;
      right = NULL;
   }
};

// preorder root->left->right (+lr)
void preOrder(Node* node){
   if(node == NULL) return;

   cout << node->data << endl;

   preOrder(node->left);
   preOrder(node->right);
}

// inorder left->root->right (l+r)
void inOrder(Node* node){
   if(node == NULL) return;

   inOrder(node->left);
   cout << node->data << " ";
   inOrder(node->right);
   // cout << node->data << " ";
}

// postorder left->right->root (lr+)
void postOrder(Node* node){
   if(node == NULL) return;

   postOrder(node->left);
   postOrder(node->right);
   cout << node->data << " ";

}


// build tree from inorder and preorder
   // preorder e traverse korbo and inorder e chek kore dekhbo thik ase kina

int search(int in[], int instart, int inend, int curr){
   for(int i=instart; i<=inend; i++){
      if(in[i] == curr) return i;
   }
   return -1;
}

Node* buildTree(int pre[], int in[], int instart, int inend){
	// instart and inend both inclusive	
   static int idx = 0;
   if(instart > inend) return NULL;

   int curr = pre[idx];
   idx++;
   Node* node = new Node(curr);

   if(instart == inend ){
      return node;
   }

   int pos = search(in, instart, inend, curr);
   node->left = buildTree(pre, in, instart, pos-1);
   node->right = buildTree(pre, in, pos+1, inend);

   return node;
}

// search O(n)


// level order traversal
// count of nodes
// sum of nodes
// height of tree = depth of the deepest tree
	// O(n)
	int height(Node* root){
	    if(root == NULL) return 0;

	    int lheight = height(root->left);
	    int rheight = height(root->right);

	    return max(lheight, rheight) + 1;
	}

// diameter of tree
	// longest path  = left most node -> root -> rightmost node (normally)
	// diameter = longest path length

	// case 2 - root diye jay na 
	
	// max(diam1, diam2, diam3)
		// diam1 = LS diameter
		// diam2 = RS diameter
		// diam3 = leftheight + rightheight + 1 (with root case)

	// diameter O(n^n) | karon height, diameter 2ta function e n times call hoche
	int diameter(Node* root){
	    if(root == NULL) return 0;
	    
	    int lheight = height(root -> left);
	    int rheight = height(root->right);
	    int currDiameter = lheight + rheight +1;

	    int ldiameter = diameter(root->left);
	    int rdiameter = diameter(root->right);

	    return max({ldiameter, rdiameter, currDiameter});
	}


	// diameter O(n)
	int diameter(Node* root, int* height){
	    if(root == NULL){
	        *height = 0;
	        return 0;
	    }

	    int lh = 0, rh = 0;
	    int ldiameter = diameter(root->left, &lh);
	    int rdiameter = diameter(root->right, &rh);

	    int currdiameter = lh+rh+1;
	    *height = max(lh, rh) + 1;

	    return max({currdiameter, ldiameter, rdiameter});
	}

// Balanced height tree
    // for each node difference between the heights of the left subtree & right subtree <=1
    
 //     1
 //    / \
 //   2   3      balanced tree
 //  /
 // 4

 //     1
 //    / \
 //   2   3      unbalanced tree
 //  /
 // 4
 //  \
 //   6


	// O (n^n) | karon height bar bar call kora lagtese
	bool isBalanced(Node* root){
	    // base cases
	    if(root == NULL){
	        return true;
	    }
	    if(isBalanced(root->left) == false){
	        return false;
	    }
	    if(isBalanced(root->right) == false){
	        return false;
	    }

	    int lh = height(root->left);
	    int rh = height(root->right);

	    if(abs(lh-rh) <= 1) return true;
	    else return false;
	}


	// O(n)
	bool isBalanced(Node* root, int* h){
	    if(root == NULL) return true;

	    int lh = 0, rh = 0;
	    if(isBalanced(root->left, &lh) == false){
	        return false;
	    }
	    if(isBalanced(root->right, &rh) == false){
	        return false;
	    }

	    *h = max(lh, rh)+1;
	    if(abs(lh - rh) <= 1){
	        return true;
	    }
	    else return false;
	}

// Count nodes 
	int countNodes(Node* root){
	    if(root == NULL) return 0;

	    return countNodes(root->left) + countNodes(root->right) + 1;
	}

// sum of all nodes
	int sumNodes(Node* root){
	    if(root == NULL) return 0;

	    return sumNodes(root->left) + sumNodes(root->right) + root->data;
	}

// Sum replacement 
    // all nodes will replace with - (left sum + right sum + node val)
    // no change in leaf node
    // 1  2  3 4 5 0 0
    // 15 11 3 4 5 0 0

    void sumReplace(Node* root){
        if(root == NULL) return;

        sumReplace(root->left);
        sumReplace(root->right);

        if(root->left != NULL){
            root->data += root->left->data;
        }
        if(root->right != NULL){
            root->data += root->right->data;
        }
    }


// max path sum     
    // 1. calculate node val
    // 2. max path thorugh left child + node val
    // 3. max path through right child + node val
    // 4. max path through left + max path through right child + node val
    
	int maxPathSumUtil(Node* root, int &ans){
	    if(root == NULL) return 0;

	    int left = maxPathSumUtil(root->left, ans);
	    int right = maxPathSumUtil(root->right, ans);

	    int nodeMax = max(max(root->data, root->data+left+right), max(root->data + left, root->data + right));

	    ans = max(ans, nodeMax);
	    int singlePathSum = max(root->data, max(root->data+left, root->data+right));
	    return singlePathSum;
	}
	    
	int maxPathSum(Node* root){
	    int ans = INT_MIN;
	    maxPathSumUtil(root, ans);

	    return ans;
	}


// check if a tree is subtree of another

// sum of nodes at k-th level 

// find lowest common ancestor (lca)
	// there are many common ancestor | but only 1 lca
// 2 7 9 10 6 3 0 0 5 11 0 0
// 	lca(6, 3) = 2
// 	lca(10, 11) = 7


// lowest common ancestor - point of path change
    // ei strategy te same node e barbar jawa lage
    // O(n)
    bool getPath(Node* root, int key, vector<int> &path){
        if(root == NULL) return false;

        path.push_back(root->data);

        if(root->data == key){
            return true;
        }

        if(getPath(root->left, key, path) || getPath(root->right, key, path)){
            return true;
        }

        path.pop_back();
        return false;
    }

    int LCA(Node* root, int n1, int n2){
        vector<int> path1, path2;

        if(!getPath(root, n1, path1) || !getPath(root, n2, path2)){
            return -1;
        }

        int pc;
        for(pc = 0; pc < path1.size()&&path2.size(); pc++){
            if(path1[pc] != path2[pc]){
                break;
            }
        }
        return path1[pc-1];
    }


	// ekta node ekbar iterate korbe O(n)
   	// 	lca(10, 20) = 10 | ekta node exist na korleo o/p pabo
	Node* LCA(Node* root, int n1, int n2){
	    if(root == NULL) return NULL;

	    if(root->data == n1 || root->data == n2){
	        return root;
	    }

	    Node* left = LCA(root->left, n1, n2);
	    Node* right = LCA(root->right, n1, n2);

	    if(left != NULL && right != NULL){
	        return root;
	    }
	    if(left == NULL && right == NULL){
	        return NULL;
	    }

	    if(left != NULL){
	        return LCA(root->left, n1, n2);
	    }
	    return LCA(root->right, n1, n2);
	}

	// shorter version
	Node* LCA(Node* root, int n1, int n2){
        if(root == NULL) return NULL;

        if(root->data == n1 || root->data == n2){
            return root;
        }

        Node* left = LCA(root->left, n1, n2);
        Node* right = LCA(root->right, n1, n2);

        if(left && right){
            return root;
        }

        if(left != NULL){
            return left;
        }
        return right;
    }

// distance between two nodes
2 7 9 10 6 3 0 0 5 11 0 0
	dist(5, 10) = 3
	dist(10, 3) = 4
	dist (5, 11) = 2

	// step-1 find lowest common ancestor(lca)
	// dist(a, b) = dist(lca, a) + dist(lca , b)



	int findDist(Node* root, int k, int dist){
	    if(root == NULL) return -1;

	    if(root-> data == k){
	        return dist;
	    }

	    int left = findDist(root->left, k, dist+1);
	    if(left != -1){
	        return left;
	    }

	    return findDist(root->right, k, dist+1);
	}

	int distance(Node* root, int a, int b){
	    Node* lca = LCA(root, a, b);

	    int d1 = findDist(lca, a, 0);
	    int d2 = findDist(lca, b, 0);

	    return d1+d2;
	}

// flattening - tree to linked list
    // for each node left will be NULL and right contain next node in preorder
    // preorder sequence == flatten linked sequence

    // step - 1 : recursively flatten left & right subtree
    // step - 2 : store the left tail and right tail
    // step - 3 : store right subtree in temp & make left subtree as right subtree
    // step - 4 : join right subtree with left tail
    // step - 5 : return right tail

	void flatten(Node* root){
	    if(root == NULL || (root->left == NULL && root->right == NULL)){
	        return;
	    }

	    if(root->left != NULL) {
	        flatten(root->left);

	        Node* temp = root->right;
	        root->right = root->left;
	        root->left = NULL;

	        Node* t = root->right;
	        while(t->right != NULL){
	            t = t->right;
	        }

	        t->right = temp;
	    }

	    flatten(root->right);
	}


// nodes at k distance
    // case - 1: without crossing root
    // case - 2: crossing root | find(node, k)
        // d = dist(node, root) | find(root, k-d)
        // node left e takle right subtree te search korbo
        // node right e thakle left subtree te search


	// case - 1
	void printSubtreeNodes(Node* root, int k){
	    if(root == NULL || k<0) return;

	    if(k == 0){
	        cout << root->data << " ";
	        return;
	    }

	    printSubtreeNodes(root->left, k-1);
	    printSubtreeNodes(root->right, k-1);
	}


	// case - 2
	int printNodesAtk(Node* root, Node* target, int k){
	    if(root == NULL) return -1;

	    if(root == target){
	        printSubtreeNodes(root, k);
	        return 0;
	    }

	    int dl = printNodesAtk(root->left, target, k);
	    if(dl != -1){
	        if(dl + 1 == k){
	            cout << root->data << " ";
	        }
	        else{
	            printSubtreeNodes(root->right, k-dl-2);
	        }

	        return 1+dl;
	    }


	    int dr = printNodesAtk(root->right, target, k);
	    if(dr != -1){
	        if(dr + 1 == k){
	            cout << root->data << " ";
	        }
	        else{
	            printSubtreeNodes(root->left, k-dr-2);
	        }

	        return 1+dr;
	    }

	    return -1;
	}


