// BST Sequences: A binary search tree was created by traversing through an array from left to right
// and inserting each element. Given a binary search tree with distinct elements, print all possible
// arrays that could have led to this tree.
// EXAMPLE
// Input: parent node 2 left node 1 right node 3
// Output: {2, 1, 3}, {2, 3, 1}

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

//method :using weaving
// arrayl: {l, 2}
// array2: {3, 4}
// weaved: {l, 2, 3, 4}, {l, 3, 2, 4}, {1, 3, 4, 2},
// {3, 1, 2, 4}, {3, 1, 4, 2}, {3, 4, 1, 2}

// core logic:
// Let's think recursively about how to weave {1,2, 3}and{4, 5, 6}. What are the subproblems?
// Prepend a l to all weaves of{2, 3}and{4, 5, 6}.
// Prepend a 4 to all weaves of{l, 2, 3}and{5, 6}.



/* Weave lists together in all possible ways. This algorithm works by removing the
 * head from one list, recursing, and then doing the same thing with the other
 * list. */
void weaveLists(vector<int>&first,vector<int>&second,vector<vector<int>>&results,vector<int>&prefix){
    if(first.size()==0||second.size()==0){
        vector<int>temp(prefix);
        temp.insert(temp.end(),first.begin(),first.end());
        temp.insert(temp.end(),second.begin(),second.end());
        results.push_back(temp);
        return;
    }
    /* Recurse with head of first added to the prefix. Removing the head will damage
    * first, so we'll need to put it back where we found it afterwards. */
    int headFirst=first[0];
    first.erase(first.begin());
    prefix.push_back(headFirst);
    weaveLists(first,second,results,prefix);
    prefix.pop_back();
    first.insert(first.begin(),headFirst);
    
    //repeat it for the second vector
    int headSecond=second[0];
    second.erase(second.begin());
    prefix.push_back(headSecond);
    weaveLists(first,second,results,prefix);
    prefix.pop_back();
    second.insert(second.begin(),headSecond);
}
// When we recurse, we'll push the prefixed elements down the recursion . When first or second are empty, we
// add the remainder to prefix and store the result.

vector<vector<int>> allSequences(TreeNode* root){
    vector<vector<int>>result;
    if(root==nullptr){
        result.push_back(vector<int>());
        return result;
    }
    vector<int>prefix;
    prefix.push_back(root->data);

    // Recurse on left and right subtrees.
    vector<vector<int>>leftseq=allSequences(root->left);
    vector<vector<int>>rightseq=allSequences(root->right);

    for(vector<int>left:leftseq){
        for(vector<int>right:rightseq){
            vector<vector<int>>temp;
            weaveLists(left,right,temp,prefix);
            result.insert(result.end(),temp.begin(),temp.end());
        }
    }
    return result;
}
//code to generate a BStree
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
    // vector<int>A={1,2,3,4,5,6,7,8,9,10};
    // TreeNode* result=createMinimalBST(A,0,A.size()-1);
    TreeNode* result=new TreeNode(2);
    TreeNode* left=new TreeNode(1);
    TreeNode* right=new TreeNode(3);
    result->left=left;
    result->right=right;
    vector<vector<int>>ans=allSequences(result);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();i++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}