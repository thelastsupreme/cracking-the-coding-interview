// Successor: Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a
// binary search tree. You may assume that each node has a link to its parent.

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* right;
    TreeNode* left;
    TreeNode* parent;
    TreeNode(int data){
        this->data=data;
        right=nullptr;
        left=nullptr;
        parent=nullptr;
    }
};

//pseudo code as given in the book for logic
// The pseudocode looks like this:

// Node inorderSucc(Node n) {
//  if (n has a right subtree) {
//      return leftmost child of right subtree
//  }else {
//  while (n is a right child of n.parent) {
//      n = n.parent; // Go up
//  }
//  return n.parent; // Parent has not been traversed
//  }
// }
//terminating condition
// when we hit the very end of the in-order traversal. That is, if we're already on the far right of the tree, then there is
// no in-order successor. We should return null

TreeNode* leftMostChild(TreeNode* n){
    if(n==nullptr){
        return nullptr;
    }
    while (n->left!=nullptr)
    {
        n=n->left;
    }
    return n;
}

TreeNode* inorderSuccessor(TreeNode * n){
    if(n==nullptr){
        return nullptr;
    }
    if(n->right!=nullptr){  //imp logic
        return leftMostChild(n->right);
    }else{ //go to parent above and check
        TreeNode* q=n;
        TreeNode* x=q->parent;
        while (x!=nullptr&&x->left!=q) //if x is a left node condition fails parent is returned
        {
            q=x;
            x=x->parent;              //else u keep going until u find a left node or u will be the right most node
        }
        return x;
    }
}


void print_inorder(TreeNode* node)
{
    if(node!=nullptr)
    {
        print_inorder(node->left);
        cout<<node->data<<endl;
        print_inorder(node->right);
    }
}

int main(){

    TreeNode* A=new TreeNode(1);
    TreeNode* B=new TreeNode(2);
    TreeNode* C=new TreeNode(3);
    A->right=C;
    A->left=B;
    B->parent=A;
    TreeNode* ans=inorderSuccessor(B);
    cout<<ans->data<<endl; //op 1
}