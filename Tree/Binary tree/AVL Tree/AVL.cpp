 
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
     Node* rotation_R (Node* node);
     Node* rotation_L (Node* node);
     Node* findsuitPlace(Node* node, int key);
     void insert(Node* node, int key);
     void inorder(Node* node);


    public:
     AVL () : root(nullptr){}
     int getHi() {return getHi(root);}
     void  insert(int key) {return insert(root, key);}
     void inorder() {inorder(root);}
};

int AVL::getHi(Node* node){
    if(node == nullptr)return 0 ;
    return node->hi;
}
void AVL ::modifyHi(Node* node){
    node->hi = 1 + max(node->left ? node->left->hi : 0, node->right ? node->right->hi : 0);
}

int AVL::getBalance(Node *node)
{
    return node ? getHi(node->left) - getHi(node->right) : 0;  
}
// Rotation Right to fix LL problem
Node* AVL::rotation_R(Node* node){

   //1-put Left Ch in temp (which makes the imbalance)
     Node* temp = node->left;
    
   //2-Childern Modification
     node->left = temp->right;
     temp->right = node;

   //3-Parent Modification
     temp->parent = node->parent;
     node->parent = temp;
     if(node->left) node->left->parent = node;
   //4-Hights Modification
     modifyHi(node);
     modifyHi(temp);
return temp;
}

int AVL::getBalance(Node *node)
{
    return node ? getHi(node->left) - getHi(node->right) : 0;  
}

// Rotation Right to fix LL problem
Node* AVL::rotation_L(Node* node){

   //1-put Right Ch in temp (which makes the imbalance)
     Node* temp = node->right;
    
   //2-Childern Modification
     node->right = temp->left;
     temp->left = node;

   //3-Parent Modification
     temp->parent = node->parent;
     node->parent = temp;
     if(node->right) node->right->parent = node;
   //4-Hights Modification
     modifyHi(node);
     modifyHi(temp);
return temp;
}

Node* AVL ::findsuitPlace(Node* node, int key){
  if(node == nullptr){
    Node* newNode = new Node(key);
    return newNode;
  }
  if(key < node->val)
  {
    node->left = findsuitPlace(node->left, key);
    node->left->parent = node;
  }
  if(key > node->val){
    node->right = findsuitPlace(node->right, key);
    node->right->parent = node;
  }
  return node;
}

void AVL ::insert(Node* node, int key){
  Node* suitP = findsuitPlace(node, key);
  while(suitP->parent != nullptr){
    // with evey iteration update the hight
    modifyHi(suitP);
    int b = getBalance(suitP);
    // How the rotation algorithm work?
      // - we check first the balance region [-1,0,1]
      // - then check do we need double or single rotatoin
    if(b > 1){
      if(getBalance(suitP->left) >= 0){
        // LL Problem
        suitP = rotation_R(suitP);
      }else {
        // LR problem
        suitP->left = rotation_L(suitP->left);
        suitP = rotation_R(suitP);
      }
      if(suitP->parent == nullptr) root = suitP;
    } 
    if(b < -1)
    {
      if(getBalance(suitP->right) <= -1){
        //RR Problem
        suitP = rotation_L(suitP);
      }else{
        //RL problem
        suitP->right = rotation_R(suitP->right);
        suitP = rotation_L(suitP);
      }
      if(suitP->parent == nullptr) root = suitP;
    } 
    suitP = suitP->parent;
  }
   
}

void AVL:: inorder(Node* node){
    if(node == nullptr)return;
    inorder(node->left);
    cout<< node->val<<" ";
    inorder(node->right);
}

int main (){
   
}
