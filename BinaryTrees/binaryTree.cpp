#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * left;
    Node * right;
public:
Node(int val){
    data=val;
   left=NULL;
   right=NULL;
}

};
Node* buildTree(Node* root){
       int val;
cout<<"enter root node";
cin>>val;
if(val==-1){
    return NULL;
};
 root=new Node(val);
 cout<<"Enter left values";
root->left=buildTree(root->left);
cout<<"enter right values";
root->right=buildTree(root->right);
return root;
};
void inOrderTraversal(Node* root){
if(root==NULL){
    return;
}
inOrderTraversal(root->left);
cout<<root->data<<" ";
inOrderTraversal(root->right);
// cout<<root->data;
};
int main()
{

    Node* root=NULL;
    root=buildTree(root);
    cout<<"In Order traversal is as follows:"<<endl;
    inOrderTraversal(root);
    return 0;
}
