#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int vlaue;
    Node* left;
    Node* right;
    Node(int k) : vlaue(k),left(nullptr), right(nullptr) {}
};
Node* insert(Node* root, int data)
{
    if(root == nullptr){
        root = new Node(data);
        return root;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr->left == nullptr)
        {
            curr->left = new Node(data);
            return root;
        }else q.push(curr->left);
        if(curr->right == nullptr)
        {
            curr->right = new Node(data);
            return root;
        }else q.push(curr->right);
    }
    
}
// left, Root, right
// Note the root roll with in,pre,post words
void inorder(Node* curr)
{
    if(curr == nullptr)return;
    inorder(curr->left);
    cout<<curr->vlaue<<" ";
    inorder(curr->right);
}

//Root, left, right
void preorder(Node* curr)
{
    if(curr == nullptr)return;
    cout<<curr->vlaue<<" ";
    preorder(curr->left);
    preorder(curr->right);
}

// Left, Right, Root
void postorder(Node* curr)
{
    if(curr == nullptr)return;
    postorder(curr->left);
    postorder(curr->right);
    cout<<curr->vlaue<<" ";
}


int main() {
  
  	// Constructing the binary tree
  	//          10
    //        /    \ 
    //       11     9
    //      / \    / \
    //     7  12   15 8
  
    Node* root = new Node(10);
    root->left = new Node(11);
  	root->right = new Node(9);
    root->left->left = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(8);
    
  
    int key = 12;
    root = insert(root, key);
  
  	// After insertion 12 in binary tree
  	//          10
    //        /    \ 
    //       11     9
    //      /  \   / \
    //     7   12 15  8

    inorder(root);

    return 0;
}

