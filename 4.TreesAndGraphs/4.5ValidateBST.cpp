// Validate BST: Implement a function to check if a binary tree is a binary search tree.

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
    TreeNode(int data,TreeNode* left,TreeNode* right){
        this->data=data;
        this->left=left;
        this->right=right;
    }
};

//method 1: get the inorder traversal into a vector and check if it is sorted
//but we can further optimize it 
//instead of storing into a vector we can just keep a track of elements inserted 
//and check if they are sorted
//(Note: this method doesnt work if you have duplicate elements in your tree)
bool checkBST(TreeNode* n,int &lastprinted){
    if(n==nullptr)
        return true;

    if(!checkBST(n->left,lastprinted))
        return false;

    if(lastprinted!=NULL && n->data<=lastprinted){ //check if curr element being inserted is greater than previous
        return false;
    }
    lastprinted=n->data; //update last printed

    if(!checkBST(n->right,lastprinted))
        return false;

    return true;
}

//method 2: best method
//is to assign a min and max limit that they elements should fall into

bool checkBST_2(TreeNode* n,int MIN,int MAX){
    if(n==nullptr)
        return true;
    if(MIN!=NULL&&(n->data<=MIN)||MAX!=NULL&&(n->data>MAX)) 
        return false;
    if(!checkBST_2(n->left,MIN,n->data)||!checkBST_2(n->right,n->data,MAX))
        return false;
    return true;
}
//function to create bst to test
TreeNode* createMinimalBST(vector<int>A,int start,int end){
    if(start>end)
        return nullptr;
    int mid=(start+end)/2;
    TreeNode* n= new TreeNode(A[mid]);
    n->left=createMinimalBST(A,start,mid-1);
    n->right=createMinimalBST(A,mid+1,end);
    return n;
}
int main(){
    vector<int>A={1,2,3,4,5,6,7,8,9,10};
    TreeNode* result=createMinimalBST(A,0,A.size()-1);
    int lastprinted=NULL; //just a value to initialize 
    cout<<checkBST(result,lastprinted)<<endl;//1
    cout<<checkBST_2(result,NULL,NULL);
}