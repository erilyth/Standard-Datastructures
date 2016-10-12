# Tries

## Introduction
The word trie is an infix of the word “retrieval” because the trie can find a single word in a dictionary with only a prefix of the word.
The main idea of the trie data structure consists of the following parts:  
The trie is a tree where each node represents a single char or a prefix.
A field in the trie node field, eg. value(isLeaf in the example below) will be used to distinguish the node as leaf node (there are other uses of the value field).
We mark the last node of every word as leaf node.
A simple trie node structure can be as follows - 
```
struct TrieNode {
    struct TrieNode *children[26]; //size particularly for words in the english alphabet
    bool isLeaf;    // isLeaf is true if the node represents end of a word
};
```
## Insertion -  
Follow links corresponding to each character in the word to be inserted. When you
* Encounter a null link: create new node.
* Encounter the last character of the word: set isLeaf to true in that node.

## Search - 
Follow links corresponding to each character in the key/word being searched. The key is not present in the structure if
* Nodes do not exist for all characters of the key.
* All nodes exist but the leaf node is not marked true.

## Deletion - 
* If key 'k' is not a prefix of any other key and nodes of key 'k' are not part of any other key then all the nodes 
starting from first one to the leaf node of key 'k' should be deleted. 
* If key 'k' is a prefix of some other key, then leaf node corresponding to key 'k' should be marked as 'not a leaf node'.
No node should be deleted in this case.

Example of a trie for the words _the,there,their,answer,any,by,bye_- 
```
                       root
                    /   \    \
                    t   a     b
                    |   |     |
                    h   n     y
                    |   |  \  |
                    e   s  y  e
                 /  |   |
                 i  r   w
                 |  |   |
                 r  e   e
                        |
                        r
```
Tries can insert and find strings in `O(L)` time, where L represents the length of the string.


## Use-cases -
* Dictionaries
* Auto-completion
* IP Routing
