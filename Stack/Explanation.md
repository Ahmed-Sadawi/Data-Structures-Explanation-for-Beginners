## Stack 
## Definition
A stack is a data structure that allows you to add or remove items only from the top. The last item you put in is the first one you take out. This is called "Last In, First Out" **(LIFO)**.

## Imagination
![alt text](<Stack using array.png>)
  + Remember **LIFO**
  + All operations takes $O(1)$

## Real-life Examples and Applications

- Undo operations in text editors (each action is pushed onto a stack, and undo pops the last action).
- Browser history (the last visited page is the first to go back to).

## Common Issues: Stack Overflow and Underflow

- **Stack Overflow:** Happens when you try to push an item onto a stack that is already full.
- **Stack Underflow:** Happens when you try to pop an item from an empty stack.
--------------------------------------------------------
 **Now a question for you, can we impelement a stack uisng liked list?**