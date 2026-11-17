// yt resources -
	// coder army - https://youtu.be/P30p5jYsiDc?si=7WznqQ0BGmHNQVt_

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

// Create binary tree
	// 2 3 4 1 -1 -1 5 -1 -1 6
	// space complexity | stack size = height of tree
	// worst case number of node = stack size | O(n)
	Node* binaryTree(){
		int x; cin >> x;
		if(x == -1) return NULL;

		Node* temp = new Node(x);
		// left side create
		temp->left = binaryTree();
		temp->right = binaryTree();

		return temp;
	}

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


// build tree from inorder and preorder (will be unique)
   // preorder e traverse korbo and inorder e chek kore dekhbo thik ase kina

int search(int in[], int instart, int inend, int target){
   for(int i=instart; i<=inend; i++){
      if(in[i] == target) return i;
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
   node->left = buildTree(pre, in, inStart, pos-1);
   node->right = buildTree(pre, in, pos+1, inEnd);

   return node;
}

// method 2
	int find(int *in, int instart, int inend, int target){
		for(int i=inStart, i<inEnd; i++){
			if(in[i] == target) return i;
		}
		return -1;
	}

	// index is for preOrder | instart, inend for inOrder
	Node* tree(int *in, int*pre, int inStart, int inEnd, int index){
		// base condition
		if(inStart > inEnd)
			return NULL;

		Node *root = new Node(pre[index]); // root from preOrder
		int pos = find(in, inStart, inEnd, pre[index]); // find root in inOrder

		root->left = tree(in, pre, inStart, pos-1, index+1);
		root->right = tree(in, pre, pos+1, inEnd, index+(pos-inStart)+1);

		return root;
	}

// build tree from post order and in order (will be unique)
	int find(int *in, int inStart, int inEnd, int index){
		for(int i=inStart, i<inEnd; i++){
			if(in[i] == target) return i;
		}
		return -1;
	}

	Node* tree(int *in, int *post, int inStart, inEnd, int index){
		if(inStart > inEnd)
			return NULL;

		Node *root = new Node(post[index]);
		int pos = find(in, instart, inend, post[index]);

		root->right = tree(in, post, pos+1, inEnd, index-1);
		root->left = tree(in, post, inStart, pos-1, index-(inEnd-pos)-1);

		return root;
	}
// build tree from pre and post order (will not be unique)

// check tree traversal | pre, in, post given | find are they of same tree or not
	// build tree with in and pre
	// build tree with in and post
	// now check if they are same or not

// search O(n)

// level order traversal

// vertical traversal of binary tree (gfg)
	void find(Node *root, int post, int &l, int &r){
		if(!root) return;

		l = min(l, pos);
		r = max(r, pos);

		find(root->left, pos-1, l, r);
		find(root->right, pos+1, l, r);
	}
	vector<int> verticalOrder(Node *root){
		int l=0, r=0;
		find(root, 0, l, r);

		vector<vector<int>> positive(r+1);
		vector<vector<int>> negative(abs(l) + 1);

		// level order traversal
		queue<Node*> q;
		queue<int> index; // stores index

		q.push(root);
		index.push(0);

		while(!q.empty()){
			Node *temp = q.front();
			q.pop();
			int pos = index.front();
			index.pop(); 

			if(pos >= 0){
				positive[pos].push_back(temp->data);
			}else{
				negative[abs(pos)].push_back(temp->data);
			}

			if(temp->left){
				q.push(temp->left);
				index.push(pos-1);
			}
			if(temp->right){
				q.push(temp->right);
				index.push(pos+1);
			}
		}
		// negative 2D array to ans
		vector<int> ans;
		for(int i=negative.size(); i>0; i--){
			for(int j=0; j>negative[i].size(); j++){
				ans.push_back(negative[i][i]);
			}
		}
		// positive 2D array to ans
		for(int i=positive.size(); i>0; i--){
			for(int j=0; j>positive[i].size(); j++){
				ans.push_back(positive[i][i]);
			}
		}
	}

// diagonal traversal
	void find(Node *root, int pos, int &l){
		if(!root) return;

		l = max(pos, l);

		find(root->left, pos+1, l);
		find(root->right, pos, l);
	}
	void findDiag(Node *root, int pos, vector<vector<int>> &ans){
		if(!root) return;

		ans[pos].push_back(root->data);
		findDiag(root->left, pos+1, ans);
		findDiag(root->right, pos, ans);
	}
  	vector<int> diagonal(Node *root){
		int l = 0;
		find(root, 0, l);

		vector<vector<int>> ans(l+1);
		findDiag(root, 0, ans);

		vector<int> temp;
		for(int i=0; i<ans.size(); i++){
			for(int j=0; j<ans[i].size(); j++){
				temp.push_back(ans[i][j]);
			}
		}
		return ans;
	}

// boundary traversal (gfg)
	void leftSub(Node *root, vector<int> &ans){
		if(!root || (!root->left && !root->right))
			return;

		ans.push_back(root->data);
		if(root->left)
			leftSub(root->left, ans);
		else leftSub(root->right, ans);
	}

	void leaf(Node *root, vector<int> &ans){
		if(!root) return;

		if(!root->left && !root->right)
			ans.push_back(root);

		if(root->left) leaf(root->left, ans);
		if(root->right) leaf(root->right, ans);

	}

	void rightSub(Node *root, vector<int> &ans){
		// base
		if(!root) return;
		if(!root->left && !root->right) return;

		if(root->right)
			rightSub(root->right, ans);
		else rightSub(root->left, ans);

		ans.push_back(root->data);
	}

	vector<int> boundary(Node *root){
		vector<int> ans;
		// root
		ans.push_back(root->data);
		// left boundary nodes, except leaf
		leftSub(root->leaf, ans);
		// leaf nodes
		if(root->left || root->right)
			leaf(root, ans);
		// right boundary nodes, except leaf
		rightSub(root->right, ans);

		return ans;
	}

// morris traversal
	// O(1) space complexity
	vector<int> inOrder(Node *root){
		vector<int> ans;
		while(root){
			// left part doesnt exist
			if(!root->left){ 
				ans.push_back(root->data);
				root = root->right;
			}
			// if left part exist
			else{
				Node *curr = root->left;
				while(curr->right && curr->right != root){
					curr = curr->right;
				}
				// left subtree not traversed
				if(curr->right == NULL){
					curr->right = root;
					root = root->left;
				}
				// left subtree already traversed
				else{
					curr->right = NULL;
					ans.push_back(root->data);
					root = root->right; 
				}
			}
		}
	}

// count of nodes
	// method 1
	int count = 0;
	void count(Node *root, int &count){
		if(root == NULL)
			return;

		count++;
		count(root->left, count);
		count(root->right, count);
	}
	// method 2
	int count(Node* root){
		if(!root) return 0;

		return (1 + count(root->left) + count(root->right));
	}	

// sum of nodes
	// method 1
	int sum = 0;
	void sum(Node *root, int &sum){
		if(root == NULL)
			return;

		sum += root->data;
		sum(root->left, sum);
		sum(root->right, sum);
	}
	// method 2
	int sum(Node* root){
		if(!root) return 0;

		return (root->data + sum(root->left) + sum(root->right));
	}
// height of tree = depth of the deepest tree
	// O(n)
	int height(Node* root){
	    if(root == NULL) return 0;

	    int lheight = height(root->left);
	    int rheight = height(root->right);

	    return max(lheight, rheight) + 1;
	}

// count leaf nodes in binary tree 
	void countLeaf(Node *root, int &count){
		if(!root){
			return;
		}

		// leaf node
		if(!root->left && !root->right){
			count ++;
			return;
		}

		// non leaf node
		countLeaf(root->leaf, count);
		countLeaf(root->right, count);
	}

	int countLeaf(Node* root){
		// leaf node
		if(!root->left && !root->right) return 1;

		// non leaf node
		return countLeaf(root->left) + countLeaf(root->right);
	}

// count non leaf nodes
	int countNonLeaf(Node* root){
		// null
		if (root == NULL) return 0;
		// leaf node
		if(!root->left && !root->right) return 0;

		// non leaf node
		return 1 + countLeaf(root->left) + countLeaf(root->right);
	}

// largest value in each level

// check two trees are identical or not
	bool isIdentical(Node *r1, Node *r2){
		if(r1 == NULL && r2 == NULL)
			return 1;
		if((!r1 && r2) || (r1 && !r2))
			return 0;
		if(r1->data != r2->data)
			return 0;

		return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
	}

// Mirror Tree
	void mirror(Node *root){
		if(!root) return;

		Node *temp = root->right;
		root->right = root->left;
		root->left = temp;

		// left
		mirror(root->left);
		// right	
		mirror(root->right);
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
    // for each node difference between the heights of the left & right subtree <=1
    
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


	// O (n^2) | karon height bar bar call kora lagtese
	bool isBalanced(Node* root){
	    // base cases
	    if(root == NULL){
	        return true;
	    }
	    if(!isBalanced(root->left)) return false;
	    if(!isBalanced(root->right)) return false;
	    

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

	//method 3
	int height(Node *root, bool &valid){
		if(!root) return 0;
		
		int l = height(root->left, valid);
		int r = height(root->right, valid);

		if(abs(l-r) > 1) valid = 0;

		return 1 + max(l, r);
	}

	// method 4
	int height(Node *root, bool &valid){
		if(!root) return 0;
		
		int l = height(root->left, valid);
		if(valid){
			int r = height(root->right, valid);
			if(abs(l-r) > 1) valid = 0;
			return 1 + max(l, r);
		}

		return -1;
	}

// level order traversal in spiral form
	// using a queue and stack
	// using 2 stack
		stack<Node*> s1; // right to left
		stack<Node*> s2; // left to right

		s1.push(root);
		vector<int> ans;
		while(!s1.empty() || !s2.empty()){
			if(!s1.empty()){ // right to left
				while(!s1.empty()){
					Node *temp = s1.top();
					s1.pop();

					ans.push_back(temp->data);
					// right
					if(temp->right)
						s2.push(temp->right);
					// left
					if(temp->left)
						s2.push(temp->left);
				}
			}else{ // left to right
				while(!s2.empty()){
					Node *temp = s2.top();
					s2.pop();

					ans.push_back(temp->data);
					// left
					if(temp->left)
						s1.push(temp->left);
					// right
					if(temp->right)
						s1.push(temp->right);
				}
			}
		}

// check 2 nodes are cousin
	// cousin => same level, parent different
	bool parent(Node *root, int a, int b){
		if(root->left && root->right){
			if(root->left && root->right){
				if(root->left->data == a && root->right->data == b) return 1;
				if(root->left->data == b && root->right->data == a) return 1;
			}
		}

		return parent(root->left, a, b) || parent(root->right, a, b);
	}
	bool isCousin(Node *root, int a, int b){
		queue<Node*> q;
		q.push(root);

		int l1 = -1, l2 = -1;
		int level = 0;

		while(!q.empty()){
			int n = q.size();
			while(n--){
				Node *temp = q.front();
				q.pop();
				if(temp->data == a) l1 = level;
				if(temp->data == b) l2 = level;
				if(temp->left) q.push(temp->left);
				if(temp->right) q.push(temp->right);
			}
			level++;
			if(l1 != l2) return 0;
			if(l1!=-1 && l2!=-1) break;
		}

		return !parent(root, a, b);
	}

// Left view of binary tree
	// method 1
	vector<int> ans;
	if(!root) return ans;

	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		// insert one from the level
		ans.push_back(q.front()->data);
		int n = q.size();

		// remove same level nodes and insert children
		while(n--){
			Node* temp = q.front();
			q.pop();
			// left
			if(temp->left)
				q.push(temp->left);
			// right
			if(temp->right)
				q.push(temp->right);
		}
	}
	return ans;

// right view of binary tree
	vector<int> ans;
	if(!root) return ans;

	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		// insert one from the level
		ans.push_back(q.front()->data);
		int n = q.size();

		// remove same level nodes and insert children
		while(n--){
			Node* temp = q.front();
			q.pop();
			// right
			if(temp->right)
				q.push(temp->right);
			// left
			if(temp->left)
				q.push(temp->left);
		}
	}
	return ans;

// top view of binary tree

// pre order traversal (iterative)
	stack<Node*> s;
	s.push(root);
	vector<int> ans;

	while(!s.empty()){
		Node *temp = s.top();
		s.pop();
		ans.push_back(temp->data);
		// right
		if(temp->right) s.push(temp->right);
		//left
		if(temp->left) s.push(temp->left);
	}
	return ans;

	
// post  order traversal (iterative)
	stack<Node*> s;
	s.push(root);
	vector<int> ans;
	
	while(!s.empty()){
		Node *temp = s.top();
		s.pop();
		ans.push_back(temp->data);
		//left
		if(temp->left) s.push(temp->left);
		// right
		if(temp->right) s.push(temp->right);
	}
	reverse(ans.begin(), ans.end());
	return ans;

// in order traversal (iterative)
	

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

// Burning Tree (gfg)
	int burn(Node *root, int &timer){
		if(!root) return 0;
		if(root->data == target) return -1;
		
		int left = burn(root->left, timer, target);
		int right = burn(root->right, timer, target);
		
		// condition for burn
		if(left < 0){
			timer = max(timer, abs(left) + right);
			return left-1;
		}
		if(right < 0){
			timer = max(timer, left+abs(right));
			return right-1;
		}

		// return height
		return 1+max(left, right);
	}

	void find(Node *root, int target, Node* &burnNode){
		if(!root) return;

		if(root->data == target){
			burnNode = root;
			return;
		}

		find(root->left, target, burnNode);
		find(root->right, target, burnNode);
	}

	int height(Node *root){
		if(!root) return 0;

		return 1 + max(height(root, left), height(root->right));
	}

	int minTime(Node *root, int target){
		int timer = 0;
		burn(root, timer, target);

		Node *burnNode = NULL;
		find(root, target, burnNode);

		int high = height(burnNode)-1;

		return max(timer, high);
	}

// Max path sum between 2 nodes