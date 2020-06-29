// Check Balanced: Implement a function to check if a binary tree is balanced. For the purposes of
// this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any
// node never differ by more than one.

#include<iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int data){
        this->data=data;
        right=nullptr;
        left=nullptr;
    }
};

//method 1 use two functions one to get height recursively and one to recursively check balance
//O(NLog n) gets job done but not very efficient
int getHeight(TreeNode* root){
    if(root==nullptr){
        return -1;
    }
    return(max(getHeight(root->left),getHeight(root->right))+1);
}

bool isBalanced(TreeNode* root){
    if (root==nullptr)
    {
        return true;
    }
    int diffHeight=abs(getHeight(root->left)-getHeight(root->right));
    if(diffHeight>1){
        return false;
    }else{
        return (isBalanced(root->left) && isBalanced(root->right));
    }
    
}


//method 2 combine both functions and using INT_MIN as a way to check for false
int checkHeight_2(TreeNode* root){
    if(root==nullptr){
        return -1;
    }
    int leftHeight=checkHeight_2(root->left);
    if(leftHeight==INT32_MIN) return INT32_MIN;

    int rightHeight=checkHeight_2(root->right);
    if(rightHeight==INT32_MIN) return INT32_MIN;
    int diffHeight=abs(rightHeight-leftHeight);
    if(diffHeight>1){
        return INT32_MIN;
    }else{
        return (max(leftHeight,rightHeight)+1);
    }

}
bool isBalanced_2(TreeNode *root){
    return checkHeight_2(root)!=INT32_MIN; //t or f based on checkHeight_2
}

int main(){
    TreeNode* root=new TreeNode(5);
    TreeNode* l=new TreeNode(3);
    root->left=l;
    TreeNode* ll=new TreeNode(4);
    l->left=ll;
    cout<<isBalanced_2(root); //not balanced
}