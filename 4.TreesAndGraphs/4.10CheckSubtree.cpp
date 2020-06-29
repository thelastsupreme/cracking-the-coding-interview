// Check Subtree: Tl and T2 are two very large binary trees, with Tl much bigger than T2. Create an
// algorithm to determine if T2 is a subtree of Tl.
// A tree T2 is a subtree of Tl if there exists a node n in Tl such that the subtree of n is identical to T2.
// That is, if you cut off the tree at node n, the two trees would be identical.
#include<iostream>
#include<string>
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

//method 1 we make use of preorder traversal and generate unique strings of traversal orders
//and check if smaller string contains the bigger one (remember to add a symbol for null pointers to make them unique)

void generateString(TreeNode* node,string &A){
    if(node==nullptr){
        A.append("X"); //symbol to dentote null values
        return;
    }
    A.append(node->data+"");
    generateString(node->left,A);
    generateString(node->right,A);
}
bool containsTree(TreeNode* T1,TreeNode* T2){
    string t1="";
    string t2="";
    generateString(T1,t1);
    generateString(T2,t2);
    return (t1.find(t2)!=string::npos); //check if and index is being returned or npos which is returned when not found
}

//method2 traverse through the trees and no root match chek if subtrees match
bool matchTree(TreeNode* r1,TreeNode* r2){
    if(r1==nullptr&&r2==nullptr){
        return true;
    }else if (r1==nullptr||r2==nullptr)
    {
        return false;
    }else if (r1->data!=r2->data)
    {
        return false;
    }else{
        return (matchTree(r1->left,r2->left)&&matchTree(r1->right,r2->right)); //check if subtrees match on data match
    }
    
}
bool subTree(TreeNode* r1,TreeNode* r2){
    if(r1==nullptr){
        return false;
    }else if (r1->data==r2->data && matchTree(r1,r2));
    {
        return true;
    }
    return (subTree(r1->left,r2)||subTree(r1->right,r2)); //check if subtrees are macthing with T2
}

bool containsTree_2(TreeNode* t1,TreeNode* t2){
    if(t2==nullptr) return true;
    return subTree(t1,t2);
}
int main(){
    TreeNode* A=new TreeNode(1);
    TreeNode* temp=new TreeNode(2);
    TreeNode* temp1=new TreeNode(3);
    TreeNode* temp2=new TreeNode(4);
    A->left=temp;
    temp->left=temp1;
    temp->right=temp2;

    TreeNode* B=new TreeNode(2);
    TreeNode* temp4=new TreeNode(3);
    TreeNode* temp5=new TreeNode(4);
    B->left=temp4;
    B->right=temp5;

    cout<<containsTree(A,B); //true
    cout<<containsTree_2(A,B); //true
}