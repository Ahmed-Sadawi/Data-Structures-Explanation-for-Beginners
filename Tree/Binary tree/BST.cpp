#include<iostream>
#include<algorithm>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int k) : val(k), left(nullptr),right(nullptr){}
};
class BST{
    private:
     Node* root;
     Node* insert(Node* node, int key);
     Node* search(Node* node, int key);
     Node* delet(Node* node, int key);
     void inorder(Node* node);

    public:
    BST() : root(nullptr){}

     void insert(int key) {root = insert( root, key);}
     bool search(int key) {return search(root, key) != nullptr;}
     void delet(int key)  {root = delet(root, key);}
     void inorder() {inorder(root);}
};
Node* BST :: insert(Node* node, int key){
    if(node == nullptr){
        node = new Node(key);
        return node;
    }
    if(key < node->val ){
       node->left = insert(node->left,key);
    }else{
        node->right = insert(node->right, key);
    }
    return node;
} 

Node* BST::search (Node* node, int key){
    if (node == nullptr||node->val == key){
       return node; 
    }
    else if(key < node->val ) {
        return search(node->left,key);
    }  

    return search(node->right,key);
}

//Don't read this until it's used.
Node* helperToDelet (Node* curr){
    curr = curr->right;
    while(curr != nullptr && curr->left != nullptr){
        curr = curr->left;
    }
    return curr;
}
Node* BST::delet(Node* node, int key){
    if(node == nullptr){
        return node ;
    }
    // Search for key 
    if(key < node->val){
       node->left = delet(node->left, key);
    }
    else if(key > node->val){
        node->right = delet(node->right,key);
    }
    // If key = current node value
    // The deletion algo is replace this key with one of its siutable children   
    //We want to ensure that the tree condition will not be broken when we delete this element by:
    else{
        // WE have three possibilities 
         //1- The node we need to delet just has left ch
             if(node->right == nullptr){
                Node* temp = node->left;
                delete node;
                return temp;
             } 
         //2-The node we need to delet just has right ch 
             if(node->left == nullptr){
                Node* temp = node->right;
                delete node;
                return temp;
             } 
         //3- When both children are present
              //now want ensure that the tree condition will not be broken when we delete this element.
              //this by do this
                // - go to right ch and then go left deeply as we can
                // - if right ch has no left ch swap with this right ch
             Node* suit_node = helperToDelet(node);
             node->val = suit_node->val;
             // now we want to delet this leaf
             node->right = delet(node->right,suit_node->val); 
    }
    return node;
}

void BST:: inorder(Node* node){
    if(node == nullptr)return;
    inorder(node->left);
    cout<< node->val<<" ";
    inorder(node->right);
}
int main (){
    BST tree;
    tree.insert(10);
    tree.insert(4);
    tree.insert(12);
    tree.insert(5);
    tree.insert(7);
    tree.insert(11);
    tree.insert(13);
    tree.inorder();
    cout << endl;
    cout << (tree.search(13) ? "Found\n" : "Not found\n");
    tree.delet(12);
    tree.inorder();
    cout << endl;
    
    BST tree2;
    tree2.insert(50);
    tree2.insert(30);
    tree2.insert(20);
    tree2.insert(40);
    tree2.insert(70);
    tree2.insert(60);
    tree2.insert(80);
    tree2.inorder();
    cout << endl;
    tree2.delet(20);
    tree2.inorder();
    cout << endl;
    cout << (tree2.search(12) ? "Found\n" : "Not found\n");
    cout << endl;
}


