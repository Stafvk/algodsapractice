#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

public:
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node *buildTree(Node *root)
{ // building tree using recursion
    int val;
    cout << "enter root node";
    cin >> val;
    if (val == -1)
    {
        return NULL;
    };
    root = new Node(val);
    cout << "Enter left values";
    root->left = buildTree(root->left);
    cout << "enter right values";
    root->right = buildTree(root->right);
    return root;
};

/*
Function for inOrderTraversal
*/
void inOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
    // cout<<root->data;
};
/*
Function to demonstrate level order Zig-Zag Traversal
*/
void zigZagLevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
int level=-1;
    while (!q.empty())
    {
        level++;
        Node *temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if(level%2==0){
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
    if(level%2!=0){
        if (temp->right)
        {
            q.push(temp->right);
        } 
         if (temp->left)
        {
            q.push(temp->left);
        }
    }
    }
}
int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node *root = NULL;
    root = buildTree(root);
    cout << "In Order traversal is as follows:" << endl;
    inOrderTraversal(root);
    cout << "Zig Zag level order traversal is as follows:" << endl;
    zigZagLevelOrderTraversal(root);
    return 0;
}
