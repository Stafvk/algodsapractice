/*Problem:: is counting the number of leaf nodes in the tree
Solution:: Use any of the traversals and add a condition where you
check if the particular node's left and right is null and then increment the count. 
Complexity:: O(n) because we need to traverse all the nodes */

//Height of the tree- If you're calculating the highest number of edges from root to leaf then below is the solution

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int height(Node* node) {
     if(node==NULL)
     return -1;
     
     int left=height(node->left);
     int right=height(node->right);
     int maxheight=max(left,right)+1;
     return maxheight;
    }
};

//If you're calculating the height by saying the number of nodes from root to leaf then it is
/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int height(Node* node) {
     if(node==NULL)
     return 0;
     
     int left=height(node->left);
     int right=height(node->right);
     int maxheight=max(left,right)+1;
     return maxheight;
    }
};

/*Diameter of Binary tree*/
//O(n^2) complexity is as follows
int height(TreeNode* root){
    if(root==NULL)
    return -1;
    int left=height(root->left);
    int right=height(root->right);
    int maxHeight=max(left,right)+1;
    return maxHeight;
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        return 0;
        int op1=diameterOfBinaryTree(root->left);
        int op2=diameterOfBinaryTree(root->right);
        int op3=height(root->left)+height(root->right)+2;
         int maxheight=max(max(op1,op2),op3);
         return maxheight;
    }
};
// the above is N^2 complexity to make it O(n)


