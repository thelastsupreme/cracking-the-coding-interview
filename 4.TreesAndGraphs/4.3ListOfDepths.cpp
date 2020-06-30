// List of Depths: Given a binary tree, design an algorithm which creates a linked list of all the nodes
// at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).
#include<iostream>
#include<vector>
#include<list>
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
void print(vector<TreeNode*>A){
    for (int i = 0; i <A.size(); i++)
    {
        cout<<A[i]->data<<" ";
    }
    cout<<endl;
}
//method 1:
// implement a simple modification of the pre-order traversal algorithm, where we pass in level +
// 1 to the next recursive call. The code below provides an implementation using depth-first search.

void createLevelLinkedListDFS(TreeNode* root,vector<vector<TreeNode*>>&lists,int level){
    if(root==nullptr) return;

    if(lists.size()==level){ 
       //implies that level hasnt been added yet cause level starts from 0
        vector<TreeNode*>l;
        l.push_back(root);
        lists.push_back(l);
        
    }else{
        //if already exits access it
        lists[level].push_back(root);
    }
    createLevelLinkedListDFS(root->left,lists,level+1);
    createLevelLinkedListDFS(root->right,lists,level+1);
}

vector<vector<TreeNode*>>createLevel(TreeNode* root){
    vector<vector<TreeNode*>>lists;
    createLevelLinkedListDFS(root,lists,0); //first level is considered 0
    return lists;
}

//method 2
// iterate through the root first, then level 2, then level 3, and so on.
// With each level i, we will have already fully visited all nodes on level i. - 1. This means that to get which
// nodes are on level i, we can simply look at all children of the nodes of level i - 1.
vector<vector<TreeNode*>>createLevelLinkedListBFS(TreeNode* root){
    vector<vector<TreeNode*>>result;
    vector<TreeNode*>temp;
    if(root!=nullptr){
        temp.push_back(root);
    }
    while(temp.size()>0){
        result.push_back(temp); //push a parent level
        vector<TreeNode*>parents(temp); //copy parents level to iterate over it
        temp.clear(); //use temp for new level now
        for(TreeNode* parent:parents){
            if(parent->left!=nullptr){
                temp.push_back(parent->left);
            }
            if(parent->right!=nullptr){
                temp.push_back(parent->right);
            }
        }
    }
    return result;
}

//just to create a tree used an external function
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
    cout<<"using dfs: "<<endl;
    vector<vector<TreeNode*>>ans=createLevel(result);
    for(int i=0;i<ans.size();i++){
        print(ans[i]);
    }
    cout<<"using bfs: "<<endl;
    vector<vector<TreeNode*>>ans1=createLevelLinkedListBFS(result);
    for(int i=0;i<ans1.size();i++){
        print(ans1[i]);
    }      

}