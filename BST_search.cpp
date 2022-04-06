#include<iostream>
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


node* buildBST(node* root){
    cout<<"Enter data : \n";
    int d;
    cin>>d;
    root = new node(d);

    if(d == -1){
        return NULL;
    }
    cout<<"Enter data of left of "<<d<<" : \n";
    root->left = buildBST(root->left);
    cout<<"Enter data of right of "<<d<<" : \n";
    root->right = buildBST(root->right);

    return root;
}

bool searched(node* root, int x){
    //base case
    if(root == NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }
    if(searched(root->left,x)){
        return true;
    }
    if(searched(root->right,x)){
        return true;
    }
}


int main(){
    node* root = NULL;
    root = buildBST(root);
    int x;
    cout<<"\nEnter searched element :";
    cin>>x;
    cout<<searched(root, x);
    return 0;
}