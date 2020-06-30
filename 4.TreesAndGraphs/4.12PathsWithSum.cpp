// Paths with Sum: You are given a binary tree in which each node contains an integer value (which
// might be positive or negative). Design an algorithm to count the number of paths that sum to a
// given value. The path does not need to start or end at the root or a leaf, but it must go downwards
// (traveling only from parent nodes to child nodes).

#include<iostream>
#include<unordered_map>
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
//method 1 : brute force and making calls to child nodes based on parent selection total of 4 calls 
int PathsWithSum(TreeNode *root,int reqSum,int &result,int OreqSum){ //OreqSum is the original required sum 
    if(root==nullptr){
        return 0;
    }else if (root->data==reqSum){
        // cout<<"node value is "<<root->data<<"  ";
        // cout<<"reqSum is : "<<reqSum<<endl;
        result++;
    }
    return (PathsWithSum(root->left,reqSum-(root->data),result,OreqSum)+
    PathsWithSum(root->right,reqSum-(root->data),result,OreqSum)+
    PathsWithSum(root->left,OreqSum,result,OreqSum)+
    PathsWithSum(root->right,OreqSum,result,OreqSum));  //if u choose to ignore the current node then reqSum is reset to OreqSum
     
}
//method 2: brute force mentioned in the book

//count paths from that node
int countPathsWithSumFromNode(TreeNode* node,int targetSum,int currSum){
    if(node==nullptr){
        return 0;
    }
    currSum+=node->data; //add to curr sum
    int totalPaths=0;
    if(currSum==targetSum){
        totalPaths++; //increment paths
    }
    //calculate for child nodes
    totalPaths+=countPathsWithSumFromNode(node->left,targetSum,currSum);
    totalPaths+=countPathsWithSumFromNode(node->right,targetSum,currSum);

    return totalPaths;
}

int countPathsWithSum(TreeNode* root,int targetSum){
    if(root==nullptr){
        return 0;
    }
    int pathsFromRoot=countPathsWithSumFromNode(root,targetSum,0); //make a call including the parent
    int pathsOnLeft=countPathsWithSum(root->left,targetSum);
    int pathsOnRight=countPathsWithSum(root->right,targetSum); //calls exculding the parent
    return pathsOnRight+pathsOnLeft+pathsFromRoot;
}

//method 3:
// using dynamic programming and a map for memoization

// 1. Track its runningSum. We'll take this in as a parameter and immediately increment it by node. value.
// 2. Look up runningSum - targetSum in the hash table. The value there indicates the total number. Set
// totalPaths to this value.
// 3. If runningSum == targetSum, then there's one additional path that starts at the root. Increment
// totalPaths.
// 4. Add runningSum to the hash table (incrementing the value if it's already there).
// 5. Recurse left and right, counting the number of paths with sum targetSum.
// 6. After we're done recursing left and right, decrement the value of runningSum in the hash table. This is
// essentially backing out of our work; it reverses the changes to the hash table so that other nodes don't
// use it (since we're now done with node).

void countPathsWithSumDP(TreeNode* node,int targetSum,int runningSum,unordered_map<int,int>&pathCount,int &ans){
    if(node==nullptr){ 
        return;
    }
    runningSum+=node->data; //add node value to running sum
    
    if(pathCount.find(runningSum-targetSum)!=pathCount.end()){
       ans+= pathCount[runningSum-targetSum]; //if u do find key value pair in the map then incrment your answer by it;
    }
    pathCount[runningSum]++; //increment the value for runningsum in map cause 
    // you are further going inside the path and recurse
    countPathsWithSumDP(node->left,targetSum,runningSum,pathCount,ans);
    countPathsWithSumDP(node->right,targetSum,runningSum,pathCount,ans);
    pathCount[runningSum]--; //decrement finally cause you are no taking that path
    
}
// explantation for above code:

// index: 0     1    2    3     4     5    6    7    8
// value: 10 -> 5 -> 1 -> 2 -> -1 -> -1 -> 7 -> 1 -> 2
// sum:   10   15   16   18    17    16   23   24   26
// The value of runningSum7 is 24. lf targetSum is 8, then we'd look up 16 in the hash table. This would have
// a value of 2 (originating from index 2 and index 5). As we can see above, indexes 3 through 7 and indexes
// 6 through 7 have sums of 8.
int main(){
    TreeNode* nlr=new TreeNode(4);
    TreeNode* nll=new TreeNode(3);
    TreeNode* nl=new TreeNode(2,nll,nlr);
    TreeNode* nr=new TreeNode(5); 
    TreeNode* n=new TreeNode(1,nl,nr);

    int result=0;
    PathsWithSum(n,5,result,5);
    cout<<result<<endl;
    cout<<countPathsWithSum(n,5)<<endl;;

    // main for Dp method
    unordered_map<int,int>pathCount;
    pathCount[0]++;
    int res=0;
    countPathsWithSumDP(n,5,0,pathCount,res);
    cout<<res;
}