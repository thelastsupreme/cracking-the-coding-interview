// First Common Ancestor: Design an algorithm and write code to find the first common ancestor
// of two nodes in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not
// necessarily a binary search tree.

#include<iostream>
#include<vector>
using namespace std;

//tree node with parent node
struct TreeNodeWithP
{
    int data;
    TreeNodeWithP* right;
    TreeNodeWithP* left;
    TreeNodeWithP*parent;
    TreeNodeWithP(int data){
        this->data=data;
        right=nullptr;
        left=nullptr;
        parent=nullptr;
    }
    TreeNodeWithP(int data,TreeNodeWithP* left,TreeNodeWithP* right,TreeNodeWithP* parent){
        this->data=data;
        this->left=left;
        this->right=right;
        this->parent=parent;
    }
};

//tree node without parent node
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

//method 1 with parent link find depths of the nodes then from the nodes to tree is basically a singly linked list
//find intersection point

int depth(TreeNodeWithP* node){
    int depth=0;
    while(node!=nullptr){   //cause root nodes parent is nullptr
        node=node->parent;
        depth++;
    }
    return depth;
}

TreeNodeWithP* commonAncestorWithP(TreeNodeWithP* p,TreeNodeWithP* q){
    int depthDiff=depth(p)-depth(q);
    // cout<<depthDiff<<endl;
    //just to get which node has max depth
    TreeNodeWithP* first=depthDiff>0?p:q; //longer one iterate over it by DepthDiff
    TreeNodeWithP* second=depthDiff>0?q:p;
    
    // cout<<first->data<<endl;
    // cout<<second->data;
    for(int i=0;i<abs(depthDiff);i++){
        first=first->parent;
    }
    while (first!=second && first!=nullptr && second!=nullptr)
    {
        first=first->parent;
        second=second->parent;
    }
    return first==nullptr||second==nullptr ? nullptr:first; //either return null or any one if match

}

//method 2 with parent link, start from required node p and check if its siblings have the node q
//then move up a level and search again

//fucntion to check if the sibling node and its subtree have the node required
bool covers(TreeNodeWithP* root,TreeNodeWithP* p){
    if(root==nullptr){
        return false;
    }if(root==p){
        return true;
    }
    return covers(root->left,p)||covers(root->right,p);
}
//function to get a sibling using the parent node
TreeNodeWithP* getSibling(TreeNodeWithP* node){
    if(node==nullptr||node->parent==nullptr){
        return nullptr;
    }
    TreeNodeWithP* parent=node->parent;
    return parent->left==node ? parent->right:parent->left; //if our node is left return right vise versa
}

TreeNodeWithP* commonAncestorWithP_1(TreeNodeWithP* root,TreeNodeWithP* p,TreeNodeWithP* q){
    if(!covers(root,p)||!covers(root,q)){
        return nullptr;
    }else if (covers(p,q)){
        return p;
    }else if (covers(q,p)){
        return q;
    }
    
    TreeNodeWithP* sibling=getSibling(p);
    TreeNodeWithP* parent=p->parent;
    while (!covers(sibling,q))
    {
        sibling=getSibling(parent);
        parent=parent->parent;
    }
    
    return parent;
}

//method 3 without pointers to parent nodes

// follow a chain in which p and q are on the same side. That is, if p and q are both on
// the left of the node, branch left to look for the common ancestor. If they are both on the right, branch right
// to look for the common ancestor. When p and q are no longer on the same side, you must have found the
// first common ancestor.

//function to check if the sibling node and its subtree have the node required
bool covers(TreeNode* root,TreeNode* p){
    if(root==nullptr){
        return false;
    }if(root==p){
        return true;
    }
    return covers(root->left,p)||covers(root->right,p);
}

TreeNode* ancestorHelper(TreeNode* root,TreeNode* p,TreeNode* q){
    if(root==nullptr||root==p||root==q){
        return root;
    }
    bool pIsOnleft=covers(root->left,p);
    bool qIsOnleft=covers(root->left,q);

    if(pIsOnleft!=qIsOnleft){  //means p and q are on diff sides
        return root;
    }
    TreeNode* childSide=pIsOnleft? root->left: root->right;     //check which sides both p and q are
    return ancestorHelper(childSide,p,q);
}

TreeNode* commonAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
    if(!covers(root,p)||!covers(root,q)){
        return nullptr;
    }
    return ancestorHelper(root,p,q);
}
//method 4 
// We recurse through the entire tree with a function called commonAncestor(TreeNode root,TreeNode p, Tree Node q).
// This function returns values as follows:
// Returns p, if root's subtree includes p (and not q).
// Returns q, if root's subtree includes q (and not p).
// Returns null, if neither p nor q are in root's subtree.
// Else, returns the common ancestor of p and q.


//this code has a bug occurs in the case when a node is not in the tree.
// to fix this make an additional flag in this struct to help solve that case
TreeNode* commonAncestorOptimized(TreeNode* root,TreeNode* p,TreeNode* q){
    if(root=nullptr)
        return nullptr;
    if(root==p && root==q)
        return nullptr;
    
    TreeNode* x=commonAncestor(root->left,p,q);
    if(x!=nullptr && x!=p && x!=q){  //found ancestor
        return x;
    }
    TreeNode* y=commonAncestor(root->right,p,q);
    if(y!=nullptr&&y!=p &&y!=q){   //found ancestor
        return y;                   
    }
    if(x!=nullptr&&y!=nullptr){
        return root;  //this is common ancestor
    }else if(root==p||root==q){
        return root;
    }else{
        return x==nullptr? y:x;  //if you find anything that is not null just return it(could be x or y)
    }
}

int main(){
    TreeNodeWithP* p=new TreeNodeWithP(1);
    TreeNodeWithP* q=new TreeNodeWithP(2);
    TreeNodeWithP* A=new TreeNodeWithP(4);
    TreeNodeWithP* B=new TreeNodeWithP(3);
    TreeNodeWithP* C=new TreeNodeWithP(0);
    A->left=B;
    B->parent=A;
    B->left=C;
    C->parent=B;
    B->right=p;
    p->parent=B;
    p->right=q;
    q->parent=p;
   
    TreeNodeWithP* result=commonAncestorWithP(p,q);
    cout<<result->data<<endl; //1
    TreeNodeWithP* result1=commonAncestorWithP_1(A,p,q);
    cout<<result1->data<<endl;

    cout<<"outputs of fuctions without parent pointers :"<<endl;
    TreeNode* p1=new TreeNode(1);
    TreeNode* q1=new TreeNode(2);
    TreeNode* A1=new TreeNode(4);
    TreeNode* B1=new TreeNode(3);
    TreeNode* C1=new TreeNode(0);
    A1->left=B1;
    B1->left=C1;
    B1->right=p1;
    p1->right=q1;
    TreeNode* result2=commonAncestor(A1,p1,q1);
    TreeNode* result3=commonAncestor(A1,p1,q1);
    cout<<result2->data<<endl;
    cout<<result3->data<<endl; //1

}