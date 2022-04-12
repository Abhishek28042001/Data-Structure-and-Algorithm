// MIRROR TREE USING NEW TREE

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

node* mirrorTree(node* root1, node* root2){
    //base case
    if(root1 == NULL){
        root2 = NULL;
        return root2;
    }
    root2 = new node(root1->data);
    root2->right = mirrorTree(root1->left , root2->right);
    root2->left = mirrorTree(root1->right , root2->left);
    // root2->data = root1->data;

    return root2;
}

int main(){
    node* root1 = new node(5);
    root1->left = new node(3);
    root1->right = new node(6);
    root1->left->left = new node(2);
    root1->left->right = new node(4);

    inorderTraversal(root1);

    node* root2 = NULL;
    root2 = mirrorTree(root1, root2);
    cout<<endl;
    inorderTraversal(root2);


    return 0;
}