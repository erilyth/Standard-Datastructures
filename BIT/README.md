###Binary Indexed Trees (BIT)

BIT (or Fenwick trees) are generally used in cumulative frequency and cumulative sum problems.
The basic underlying principle behind BITs is that each integer can be represented as sum of powers of two.  
Let’s define the following problem:  
We have n boxes that contain marbles. Possible queries are

1. Update the number of marbles in a particular box i
2. Sum marbles from box 1 to box i

The simple solution of running a loop through the array structure has time complexity of `O(1)` for query 1 and `O(n)` for query 2.
Another strategy is to create a prefix sum array and store sum from start to i at the i’th index in this array.
Sum of a given range can now be calculated in `O(1)` time, but update operation takes `O(n)` time now.
Using Binary Indexed Trees, we can perform both operations with worst case time complexity of `O(log n)`

####Implementation
BIT can implemented as arrays. Let's assume we have n elements. A node at index y is parent of a node at index x, 
iff y can be obtained by removing last set bit from binary representation of x.   
For example, `2 -> 0010 -> 0000`,`6 -> 0110 -> 0100`  
Hence, the nodes which are powers of 2 (1,2,4,8...) have the root node as their parent.  
(For sake of simplifying visualization of the tree we can create an array of length n + 1 and use 1-indexed notation,the 0th index being a dummy root node.)  

Let's say we wish to calculate the range upto 13 elements in some array.
`13 -> 1101` Hence we will only have to add the elements at the indexes `1101`(13 itself) + `1010`(10) + `1000`(8) + `0000`(null) in our BIT array.

So we generally require two methods - the update and sum methods(in the program bit.c you can find them as the change and query methods)  
For the sum method -
* Initialize a variable sum(in the code, this is the ans variable) to 0
* Do following while index is greater than 0.  
  a) Add BITree[index] to sum  
  b) Go to parent of BITree[index].Parent can be obtained by removing
     the last set bit from index, i.e., index = index - (index & (-index))
* Return sum.

For the update method - 
* Do following while index is smaller than or equal to n.  
 a) Add value to BITree[index]  
 b) Go to parent of BITree[index].  Parent can be obtained by removing
     the last set bit from index, i.e., index = index + (index & (-index))
