// Minimal Tree: Given a sorted (increasing order) array with unique integer elements, write an algorithm
// to create a binary search tree with minimal height.

#include<iostream>
#include<vector>
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

//simple logic: in a sorted array the mid elemenet will be the node and then split into two arrays
//and they will be the left and right subtrees respective arrays


TreeNode* createMinimalBST(vector<int>A,int start,int end){
    if(start>end)
        return nullptr;
    int mid=(start+end)/2;
    TreeNode* n= new TreeNode(A[mid]);
    n->left=createMinimalBST(A,start,mid-1);
    n->right=createMinimalBST(A,mid+1,end);
    return n;
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
    vector<int>A={1,2,3,4,5,6,7,8,9,10};
    TreeNode* result=createMinimalBST(A,0,A.size()-1);
    print_inorder(result);
}