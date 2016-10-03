#Infix Prefix PostFix

An arithmetic expression can be written in three different but equivalent notations without changing the essence or output of expression.

###Infix Notations
We write expression in infix notation, where operators are used in-between operands. It is easy for us humans to read, write and speak in infix notation 
but the same does not go well with computing devices since Infix notation needs extra information to make the order of evaluation of the operators clear. 

For example, the usual rules for associativity say that we perform operations from left to right, so the multiplication by A is assumed to come before the division by D. Similarly, the usual rules for precedence say that we perform multiplication and division before we perform addition and subtraction.

An algorithm to process infix notation could be difficult and costly in terms of time and space consumption.
Instead, these infix notations are first converted into either postfix or prefix notations and then computated.

###Prefix Notations
In this notation, operator is prefixed to operands, i.e. operator is written ahead of operands. Prefix notation is also known as Polish Notation.

###PostFix Notation
  In this notation style, operator is postfixed to the operands i.e., operator is written after the operands. 

####Examples
Infix | Prefix | PostFix |  
------------ | ------------- | -------------
A + B | + A B | A B +
A * (B + C) |	* A + B C |	A B C + *
(A + B) * (C + D) |	* + A B + C D | A B + C D + *


###Postfix Evaluation Algorithm
 
* Create an empty stack for keeping operators and an empty list for output.
* Scan the token list from left to right:
 
  Token | Action
    ------------ | -------------
    Operand (A, B): | Append it to the end of the output list.
    Left parenthesis(() | Push it on the stack.
    Right parenthesis()) | Pop the stack until the corresponding left parenthesis is removed. Append each operator to the end of the output list.
    Operator(*, /, +, or -) | First remove any operators already on the stack that have higher or equal precedence, append them to the output list and push the operator on the stack. 

* When the input expression has been completely processed, check the stack. Any operators still on the stack can be removed and appended to the end of the output list.
 
 
[Source](https://www.tutorialspoint.com/data_structures_algorithms/expression_parsing.htm)
