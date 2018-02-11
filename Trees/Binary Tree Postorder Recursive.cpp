#include<iostream>

using namespace std;

class Node{
    
    public :
            Node* left;
            Node* right;
            
            int data;
            
            Node(int data){
                this->left = NULL;
                this->right = NULL;
                this->data = data;
            }
       
};

void preorder(Node* root){
    
    if(root == NULL){ return;}
    
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
    
    return;
}
int main(){
    //level 1
   Node *root = new Node(1); 
   
   //level 2
   root->left = new Node(2);
   root->right = new Node(3);
   
   //level 3
   root->left->left = new Node(4);
   root->left->right = new Node(5);
   root->right->left = new Node(6);
   root->right->right = new Node(7);
   
   //level 4
   root->left->right->left = new Node(8);
   root->left->right->right = new Node(9);
   
   preorder(root);
   
    return 1;
}
