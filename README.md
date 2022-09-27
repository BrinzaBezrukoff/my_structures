# My structures (and algorithms)
This repository contains my implementations of some data structures and algorithms related with them.

## Repository content
### Binary Search Tree (my_bst)
BST class implements binary search tree data structure.

Map class based on BST implements key-value map (dictionary).

Performance and features:
- Lookup: O(log n)
- Insertion: O(log n)
- Deletion: O(log n)
- Stored pairs are sorted by key

Set class based on BST implements container of unique elements.

Performance and features:
- Lookup: O(log n)
- Insertion: O(log n)
- Deletion: O(log n)
- Stored elements are sorted by their values


### Priority Queue (my_priority_queue)
priority_queue class implements priority queue, based on binary heap data structure.

Template parameter Container may be any container satisfy:
- Random access with operator[]
- Insertion in the end with push_back() method
- Deletion from the end with pop_back() method
- size() method returns size of container

By default Container = std::vector

Performance and features:
- Insertion (.push): O(log n)
- Deletion (.pop): O(log n)
- Top element access (.top): O(1)
- Top element is always the greatest


### Queue and List (my_queue_list)
List implementation in list subdirectory.
Queue implementations in queue subdirectory.

Queue support different base containers:
- std::vector (VectorQueue)
- list (ListQueue)


### Stack (my_stack)
Stack implementation in stack subdirectory.

Stack support different base containers:
- std::vector (VectorStack)
- std::list (ListStack)


### Vector (my_vector)
Vector implementation in vector subdirectory.

NOT TEMPLATED in some reason...

Performance and features:
- operator[]: O(1)
- .pushBack: O(1)
- .popBack: O(1)
- .find: O(n)
- .insert: O(n)
- .erase and .eraseBetween: O(n)
- .pushFront: O(n)
- .popFront: O(n)
