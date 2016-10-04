# Sorting 

## Merge Sort

Merge sort is a sorting technique based on divide and conquer technique. Merge sort first divides the array into equal halves and then combines them in a sorted manner 

### Working of Merge Sort: 

To understand merge sort, we take an unsorted array as depicted below − 
14,33,27,10,35,19,42,44

We know that merge sort first divides the whole array iteratively into equal halves unless the atomic values are achieved. We see here that an array of 8 items is divided into two arrays of size 4. 
14,33,27,10  35,19,42,44
Merge Sort Division :
This does not change the sequence of appearance of items in the original. Now we divide these two arrays into halves. 
14,33  27,10 35,19  42,44
Merge Sort Division 
We further divide these arrays and we achieve atomic value which can no more be divided.
14 33 27 10 35 19 42 44

### Merge Sort Division 

We first compare the element for each list and then combine them into another list in sorted manner. We see that 14 and 33 are in sorted positions. We compare 27 and 10 and in the target list of 2 values we put 10 first, followed by 27. We change the order 19 and 35. 42 and 44 are placed sequentially. 
Merge Sort Combine 
14,33 10,27 19,35 42,44
In next iteration of combining phase, we compare lists of two data values, and merge them into a list of found data values placing all in sorted order. 
10,14,33,27 19,35,42,44

After final merging, the list should look like this − 
10,14,19,27,33,35,42,44
Merge Sort 

 Worst case Time Complexity-O(nlogn) 

### ALGORITHM: 

Step 1 − if it is only one element in the list it is already sorted, return.  

Step 2 − divide the list recursively into two halves until it can no more be divided. 

Step 3 − merge the smaller lists into new list in sorted order. 

 

## QUICK SORT 

Quicksort is a divide and conquer algorithm. Quicksort first divides a large array into two smaller sub-arrays: the low elements and the high elements. Quicksort can then recursively sort the sub-arrays. 

The steps are: 

1.Pick an element, called a pivot, from the array. 

2.Partitioning: reorder the array so that all elements with values less than the pivot come before the pivot, while all elements with values greater than the pivot come after it (equal values can go either way). After this partitioning, the pivot is in its final position. This is called the partition operation. 

3.Recursively apply the above steps to the sub-array of elements with smaller values and separately to the sub-array of elements with greater values. 

The base case of the recursion is arrays of size zero or one, which never need to be sorted. 

The pivot selection and partitioning steps can be done in several different ways; the choice of specific implementation schemes greatly affects the algorithm's performance. 

 

## RANDOMIZED QUICK SORT: 

Randomized Quick Sort is an extension of Quick Sort in which pivot element is chosen randomly.Worst case happens when randomly chosen pivot is got selected in sorted or reverse sorted order. 

In this random number generator is used and procedure is same as that for quick sort. 

 
