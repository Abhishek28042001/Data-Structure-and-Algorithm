// MIRROR TREE USING SWAPPING

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorderTraversal(node* root){
    //base case
    if(root== NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

node* mirrorTree(node* root){
    //base case
    if(root == NULL){
        return root;
    }
    node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    if(root->left){
        root->left = mirrorTree(root->left);
    }
    if(root->right){
        root->right = mirrorTree(root->right);
    }

    return root;
}

int main(){
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(2);
    root->left->right = new node(4);

    inorderTraversal(root);

    
    root = mirrorTree(root);
    cout<<endl;
    inorderTraversal(root);


    return 0;
}