# Array

## Definition

An **array** contiguous area of memory consisting of equal size elements indexed by contiguous integres.

## Explanation
When you initialize:
```cpp
int arr[5];
```
and compile the program, the compiler determines the total amount of memory needed for this array as:
----
  number of elements × size of each element
---
It then reserves this block from memory, This fixed memory allocation makes arrays static.



## Common Operations

| Operation   | Description                        | Time Complexity |
|-------------|------------------------------------|-----------------|
| Access      | Retrieve element at index i        | O(1)            |
| Update      | Change value at index i            | O(1)            |
| Insert      | Add element (end: O(1), middle: O(n)) | O(n)         |
| Delete      | Remove element (end: O(1), middle: O(n)) | O(n)       |
| Search      | Find element by value              | O(n)            |

## Use Cases

- Storing and processing lists of items (numbers, strings, etc.)
- Lookup tables
- Multi-dimensional data (matrices)

## Pros and Cons

**Pros:**
- Simple to implement and use
- Fast access using index

**Cons:**
- Fixed size (cannot grow or shrink after creation)
- Insertion and deletion (except at the end) are slow (O(n))

## Visual

```
Index:   0   1   2   3   4
Array: [10][20][30][40][50]
```

## Example (Pseudocode)

```
// Accessing 3rd element
array[2] // returns 30
```

## Analogy

Think of an array like a row of mailboxes, each with a number. You can quickly go to any mailbox by its number, but if you want to add a new mailbox in the middle, you have to shift all the ones after it.