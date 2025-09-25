# AVL Tree 
## Definition
AVL tree is a self-balancing Binary Search Tree, which means it rebalances itself whenever the height-balance condition is violated(this happen at insertion and deletion) (balance factor ∉ {−1, 0, 1}).
    
    How the tree rebalace itself?

## Rotations
Rotations are algorithms designed to restore balance in $O(1)$ time.

    Types of rotations(Rotation types are named after the imbalance pattern, not the fixing action) 
    Left-Left (LL) Rotation
    Right-Right (RR) Rotation
    Left-Right (LR) Rotation
    Right-Left (RL) Rotation
-----
## Left Left (LL) Rotation 
Occurs when a node is inserted into the left subtree of the left child to fix it we perform a single **right** rotation.

## Right Right (RR) Rot 
Occurs when a node is inserted into the right subtree of the right child to fix it we Perform a single **left** rotation

---
## Left-Right (LR) Rot
Occurs when a node is inserted into the right subtree of the left child to fix it we Perform a left rotation on the left child, followed by a right rotation on the node

---
## Right-Left (RL) Rot
Occurs when a node is inserted into the left subtree of the right child to fix it we Perform a right rotation on the right child, followed by a left rotation on the node.

------
### Visualization
![alt text](<AVL Rotation.png>)
We will disucuss every rotate type in the code file.
