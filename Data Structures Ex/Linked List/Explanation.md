# Linked list  (First type which is singly)

## Definition
L-list is an uncontiguous area of memory consisting of equal-sized elements indexed by random **addresses**.

**Note:**
--- 
The address tells the program where the data is stored in the memory, and this is what makes L-list an uncontiguous area.
--- 

## Imagination
![alt text](<Linked list-1.png>)
-----------------------------------------
+ This means we can traverse a linked list in only one direction, which is "forward." Specifically, any operation that requires traversing backward will take $O(n)$ time.

## Common Operations
| Operation        | Description                                     | Time Complexity |
|------------------|-------------------------------------------------|-----------------|
| Traversal        | Visit each node in the list                     | O(n)            |
| Search           | Find an element by value                        | O(n)            |
| Insertion (head) | Insert a new node at the beginning              | O(1)            |
| Insertion (tail) | Insert a new node at the end (with tail pointer)| O(1)            |
| Insertion (pos)  | Insert a new node at a specific position        | O(n)            |
| Deletion (head)  | Delete the first node                           | O(1)            |
| Deletion (tail)  | Delete the last node                            | O(n)            |
| Deletion (pos)   | Delete a node at a specific position            | O(n)            |
| Update           | Modify the value of a specific node             | O(n)            |

## Notes about the OPs taple
+ **What does make the delete first take O(1) and delete last take O(n)?** 
 + Because the first head point is at the second node (which will be the head after deletion), we do not need to search to find "what node will be the head after deletion".
 + But in the last node, we don't know "what node will be the tail after deletion" because there is no point at the node before the tail, so we will search( O(n) ) for it.
 + You can measure this across all processes. 

The one direction (forward) makes several OPs takes $O(n)$, so this makes us build the second type of L-list whis is :

## Doubly linked list
 It is like normal linked list but it has to directoin forward and backward by add new pointer for previous node.


## Imagination  
![alt text](<Double L-list-1.png>)
 + This mean we can go forward or backward traverse.

## Common Operations
| Operation          | Time Complexity |
|--------------------|-----------------|
| Search   | O(n)            |
| Insert at head     | O(1)            |
| Insert at tail     | O(1)            |
| Insert in middle   | O(n)            |
| Delete at head     | O(1)            |
| Delete at tail     | O(1)            |
| Delete in middle   | O(n)            |

 + Most operation become  $O(1)$ now.


