// Generalized BST
// Can store large number of keys in a single node 

// All leaves are at the same level.

// Every node except the root must contain at least t-1 keys. The root may contain a minimum of 1 key.
// All nodes (including root) may contain at most (2*t – 1) keys
// Number of children of a node is equal to the number of keys in it plus 1.
// All keys of a node are sorted in increasing order. The child between two keys k1 and k2 contains all keys in the range from k1 and k2.

// max children m | min children ceil(m/2)
// max keys (m-1) | min keys ceil(m/2)-1

// Insertion only happens in leaf node

