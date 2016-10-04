# BINARY SEARCH TREE

Binary Search Tree is node based binary tree data structure with the following properties: 
 
* The Left subtree contains the nodes with keys less than the node's key. 
* The Right subtree contains the nodes with keys greater than the node's key. 
* Both the right and left subtree should also be binary search tree. 
* There should not be any duplicate nodes. 
 
## SEARCHING 
 
Searching can be a recursive or iterative process.  
 
We begin first by comparing the value with the root node and if the value is equal to root node value then the search is successful. Otherwise we check if it is greater or smaller than root node. If smaller we go to the left subtree and repeat the above process and if its greater we go to the right subtree and repeat the above process. 
 
This operation of searching requires O(log n) time. 
 
### Pseudo Code: 
Search for a matching node 
  1. Start at the root node as current node 
  2. If the search key’s value matches the current node’s key then found a match 
 3. If search key’s value is greater than current node’s 
    1. If the current node has a right child, search right 
    2. Else, no matching node in the tree 
4. If search key is less than the current node’s 
    1. If the current node has a left child, search left 
    2. Else, no matching node in the tree. 

 

## Insert Node 
 
Insert Node operation also behaves in the same manner as Searching operation. Firstly, it checks whether the key is the same as that of root, if not then we either choose the right subtree or the left subtree depending upon the value passed is greater or smaller than the root node value respectively. 
 
Eventually, we will reach an external node where we will add the new node as its left or right child depending upon the node's key. 
 
This is also a recursive operation, as we start from the root and go until we find the right place to insert to node. 
 
It takes O(log n) time i.e. proportional to the height of the tree. 
 
### Pseudo Code: 
Always insert new node as leaf node 
2. Start at root node as current node 
3. If new node’s key < current’s key 
    1. If current node has a left child, search left 
    2. Else add new node as current’s left child 
4. If new node’s key > current’s key 
   1. If current node has a right child, search right 
   2. Else add new node as current’s right child 
