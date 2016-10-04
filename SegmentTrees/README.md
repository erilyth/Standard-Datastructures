###**Segment Trees**

A segment tree is a flexible data-structure built upon an array that stores any kind of information of the subsegments(intervals) of the base array.
These information may be, for example, the sum of the elements in the interval or the biggest/smallest value in the interval.
This structure is basically maintained through three operations:

* **Build tree**;
  Given `N` the size of the array, recursively build the binary tree based on the array. Complexity `O(N log(N))`.
* **Query interval**;
  Given `N` the size of the array, `A` the left frontier of the interval, `B` the right frontier of the interval, recursively gets and returns the info stored on the tree for the asked(solicitado) interval. Complexity `O(log(N))`.
* **Update tree**;
  Given `N` the size of the array, `I` the index of an element to be updated and `X` the value to update the value at `I` to, recursively updates the nodes that store any information for a interval that contains `I`. Complexity `O(log(N))`.

It is possible to see that a sum segment tree has very similar practical behavior to a Binary Indexed Tree (BIT).
So the main difference is that a segment tree is easily adaptable to store any information other than the sum of the interval.

###Implementation

Segment trees, despite of being binary trees, are easiest and more efficiently maintained in an array of size `2N`.

The implementation of each method is, as said before, recursive and can be described as follows.

Build method - Called with `s=0, e=N-1, i=0`
* If `s == e`, this is a leaf node and must store the value of the array at i and return it.
    * Current node(i) stores info(i)
    * Return current node info

* Else, this is not a leaf node and must store the information about both it's left and right subsegments.
    * Call build for left  `{s=s, e=(s+e)/2, i=(i*2)+1}`.
    * Call build for right `{s=((s+e)/2)+1, e=e, i=(i*2)+2}`.
    * Current node(i) stores info(left, right)
    * Return current node info

Query method - Called with `s=0, e=N-1, from=a, till=b, i=0`
* If `from > e || till < a`, this node doesn't contains any relevant information for this query and must return overwritable value. (a value that will always be worst at info than another [that depends on the problem to be solved]. for example, if your segment tree is a sum segment tree, it can be 0, since 0 is the neutral element in sum)
    * Return neutral value.
* Else if `from <= s && till >= e`, the interval of this node is entirely inside our interval query, and we can return it.
    * Return current node(i) info
* Else, we must search a little more on this node children.
    * Call query for left  `{s=s, e=(s+e)/2, from, till, i=(i*2)+1}`.
    * Call query for right `{s=((s+e)/2)+1, e=e, from, till, i=(i*2)+2}`.
    * Return info(left, right)

Update method - Called with `s=0, e=N-1, pos=x, val=y, i=0`
* If `pos >= s && pos <= e`, this node contains info of the element in the array at pos.
  * If `s == e`, this is a leaf node and can be updated.
	* Update current node(i) with y
	* Return current node(i) info
  * Else, this is not a leaf node and may possibly be updated
    * Call update for left  `{s=s, e=(s+e)/2, pos, val, i=(i*2)+1}`.
    * Call update for right `{s=((s+e)/2)+1, e=e, pos, val, i=(i*2)+2}`.
    * Return current node(i) info
* Else if `pos < s || pos > e`, this node doesn't contains info of the element, must be returned for updating it's common parents.
    * Return current node(i) info

