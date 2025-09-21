#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int k) : val(k), left(nullptr),right(nullptr){}
};

Node* insert(Node* root, int key){
    if(root == nullptr){
        root = new Node(key);
        return root;
    }
    if(key < root->val ){
        //curr = curr->left;
       root->left = insert(root->left,key);
    }else{
        root->right = insert(root->right, key);
    }
    return root;
} 

Node* search (Node* root, int key){
    if (root == nullptr||root->val == key){
       return root; 
    }
    else if(key < root->val ) {
        return search(root->left,key);
    }  

    return search(root->right,key);
}


void inorder(Node* root){
    if(root == nullptr)return;
    inorder(root->left);
    cout<< root->val<<" ";
    inorder(root->right);
}
int main (){
    Node* root = new Node(10);
    root = insert(root,4);
    root = insert(root,12);
    root = insert(root,5);
    root = insert(root,7);
    root = insert(root,11);
    root = insert(root,13);
    inorder(root);
    cout<<endl;
    (search(root, 13) != nullptr)? cout<<"Found\n" :  cout<<"Not found";
    
}