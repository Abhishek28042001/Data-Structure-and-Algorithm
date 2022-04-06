void inorder(node* root){
    //base case
    if(root==NULL){
        return ;
    }
    inoder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}