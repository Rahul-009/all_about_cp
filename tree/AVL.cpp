// Self balancing BST
// height(left) - height(right) < 2
// height difference 0 ar 1 allowed

// Left rotation
// right rotation

// 4 cases to handle
	// RR - left rotation
	// LL - right rotation
	// LR - left , right rotation
	// RL - right, left rotation

// Advantages
	// strictly height balanced
	// searching is faster in AVL tree
	// insertion and deletion is faster in Red Black

// Drawbacks
	// kono tree ke AVL banate koyta rotation lagbe eta fixed na
	// depends on node number and structure