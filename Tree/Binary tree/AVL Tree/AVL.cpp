 
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
     void dele (Node* node, int key);
     void inorder(Node* node);


    public:
     AVL () : root(nullptr){}
     int getHi() {return getHi(root);}
     void  insert(int key) { insert(root, key);}
     void inorder() {inorder(root);}
     void deleteKey(int key) { dele(root, key);}
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
  if (root == nullptr) {
    root = suitP;// the condition of while will fail if the tree is empty
    return;
  }
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
   return node;
}
Node* find (Node* node, int key){
  if(node == nullptr){
    cout<< "the tree is empty";
    return nullptr;
  }else if (key < node->val )return find(node->left,key);
  else if(key > node->val) return find(node->right, key);
  else return node;
}

Node* succ (Node* node){
  Node* curr = node->right;
  while (curr != nullptr && curr->left != nullptr) curr=curr->left;
  return curr; 
}
void :: dele(Node* node , int key){
  Node* placeOfnode = find(node, key);
  if (placeOfnode == nullptr) {
      return; // Not found
  }

  if(placeOfnode->left && placeOfnode->right){
    Node* suitreplaceNode = succ(placeOfnode);
    placeOfnode->val = suitreplaceNode->val;
    placeOfnode = suitreplaceNode;
  }

  Node* rebalanceStart = placeOfnode->parent;
  Node* child = (placeOfnode->left) ? placeOfnode->left : placeOfnode->right;

  if(child != nullptr ) child->parent = rebalanceStart;

  if(rebalanceStart == nullptr) root = child;

  if ( rebalanceStart->left ==  placeOfnode){
    rebalanceStart->left = child;
  }
  if (rebalanceStart->right == placeOfnode){
    rebalanceStart->right = child;
  }
  delete placeOfnode;

  
  while (rebalanceStart != nullptr){
  modifyHi(rebalanceStart);
  int balance = getBalance(rebalanceStart);
  Node* currentParent = rebalanceStart->parent; 
  Node* newSubtreeRoot = rebalanceStart;
  if(balance > 1){
    if(getBalance(rebalanceStart->left)>=0){
      rebalanceStart = rotation_R(rebalanceStart);
    }else {
      rebalanceStart->left = rotation_L(rebalanceStart);
      rebalanceStart = rotation_R(rebalanceStart);
    }
  }
  else if(balance < -1){
    if(getBalance(rebalanceStart->left )<=0){
      rebalanceStart = rotation_L(rebalanceStart);
    }else {
      rebalanceStart->right = rotation_R(rebalanceStart);
      rebalanceStart = rotation_L(rebalanceStart);
    }
  }
  if (currentParent == nullptr) {
        root = newSubtreeRoot;
    } else if (currentParent->left == rebalanceStart) {
        currentParent->left = newSubtreeRoot;
    } else {
        currentParent->right = newSubtreeRoot;
    }
    rebalanceStart = currentParent;
 
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
