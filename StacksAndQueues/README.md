##STACKS  
A stack is a **last-in first-out**(LIFO) linear data structure,ie. the items are accessed from the stack  
in the reversed order in which they are inserted. Elements can be added/removed from the stack only at the top.  
Generally, the following two operations are performed on stacks - 
* Push() -  Adds an item in the stack (if the stack is not full)
* Pop()  -  Removes an item from the top of the stack  
Additionally, a method can be used to check whether the stack is full/ is empty to avoid errors.

####Implementation:  
There are two ways to implement a stack:  
* Using an array
* Using a linked list  

For an array based stack, create an array depending on the type of variables to be stored.
Next, create a variable _top_ that refers to the top element in the stack and a variable _capacity_ that refers to the array size. 
The _top_ changes from _-1_ to _capacity - 1_. We say that a stack is empty when top = -1, and the stack is full when top = capacity-1.
  
####Use-cases - 
* Reversal of a word
* Balancing parantheses
* Hanoi Tower problem
* Maze/Backtracking

##QUEUES
The queue is a _first-in first-out_ (FIFO) data structure. It is easy to visualize a queue as a line at the supermarket. 
When you go to the supermarket, customers join to the rear (end) of the line and customers come off of the line (i.e., are serviced) from the front of the line.
Generally, the following two operations are performed on queues -
* Dequeue() - Removes and returns the object at the beginning of the Queue.
* Enqueue()	- Adds an object to the end of the Queue.  
Additional utility methods/variables for checking status can be used.

####Implementation:
Queues can easily be implemented using lists/arrays. For implementing a queue, we need to keep track of two indices, _front_ and _rear_. We enqueue an item at the rear and dequeue an item from front.
If we simply increment front and rear indices, then there may be problems, the front may reach end of the array. 
The solution to this problem is to increase front and rear in circular manner, by incrementing the counters modulo the size of the array.

####Use-cases - 
* Arithmetic Expression Evaluation
* Searching algorithms
