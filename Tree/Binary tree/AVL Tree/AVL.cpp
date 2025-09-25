 
#include<iostream>
#include<algorithm>
using namespace std;

struct Node {
    int val; 
    int hi =0; // The hight 
    Node* left;
    Node* right;
    Node* parent;
    Node(int k) : val(k), left(nullptr), right(nullptr), parent(nullptr) {}
};
class AVL {

    private:
     Node* root;
     int getHi(Node* node);
     void modifyHi(Node* node);
     int getBalance(Node* node);
     void inorder(Node* node);


    public:
     AVL () : root(nullptr){}
     int getHi() {return getHi(root);}
     void inorder() {inorder(root);}
};

int AVL::getHi(Node* node){
    if(node == nullptr)return ;
    return node->hi;
    return 0;
}
void AVL ::modifyHi(Node* node){
    node->hi = 1 + max(node->left ? node->left->hi : 0, node->right ? node->right->hi : 0);
}

int AVL::getBalance(Node *node)
{
    return node ? getHi(node->left) - getHi(node->right) : 0;  
}

void AVL:: inorder(Node* node){
    if(node == nullptr)return;
    inorder(node->left);
    cout<< node->val<<" ";
    inorder(node->right);
}

int main (){
   
}
