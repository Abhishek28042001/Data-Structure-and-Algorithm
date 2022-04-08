#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        this->data = d;
        this->left = this->right = NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter data ";
    int data;
    cin>>data;
    root = new node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"\nFor left element of "<<data;
    root->left = buildTree(root->left);
    
    cout<<"\nFor right element of "<<data;
    root->right = buildTree(root->right);

    return root;
}

void zigzakTraversal(node* root){
    if(root == NULL){
        return;
    }
    stack<node*> currentStack, nextStack;
    bool ltr = true;
    currentStack.push(root);
    while(!currentStack.empty()){
        node* temp = currentStack.top();
        currentStack.pop();
        if(temp!=NULL){
            cout<<temp->data<<" ";
            if(ltr){
                if(temp->left){
                    nextStack.push(temp->left);
                }
                if(temp->right){
                    nextStack.push(temp->right);
                }
            }
            else{
                if(temp->right){
                    nextStack.push(temp->right);
                }
                if(temp->left){
                    nextStack.push(temp->left);
                }
            }
        }
        if(currentStack.empty()){
            ltr = ! ltr;
            swap(currentStack,nextStack);
        }
    } 
}

int main(){
    node* root = NULL;
    //tree creation
    root = buildTree(root);
    //zigzak Traversal
    zigzakTraversal(root);


    return 0;
}