// Random Node: You are implementing a binary tree class from scratch which, in addition to
// insert, find, and delete, has a method getRandomNode() which returns a random node
// from the tree. All nodes should be equally likely to be chosen. Design and implement an algorithm
// for getRandomNode, and explain how you would implement the rest of the methods.

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
    int data;
    int size;// total size of the tree from that node
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
    TreeNode* getRandomNode();
};

//method 1: put all elements in an array and then just return a random number from it

//method 2: instead of making an array if ur class already has one to begin with two always store its elements
// somewhere it is better than method1 but while deleting nodes u would need O(N) time.

//method 3: give a label to all Nodes between 1 to N then just call a random number between it and then find the element 
// in the tree using the label

//method 4: when u reach a node the probability of choosing an element from left should be left_side_elements_count/Total
//similarly for right side

TreeNode* TreeNode::getRandomNode(){
    int leftSize=(left==nullptr? 0: left->size);
    // cout<<"left size : "<<leftSize<<endl;
    int index=rand()%size;
    // cout<<"index : "<<index<<endl;
    if(index<leftSize){ 
        return left->getRandomNode();
    }else if (index==leftSize){
        return this;
    }else{
        return right->getRandomNode();
    }
}

//method 5: last optimization 
//just pick one number dont try and pivk a number always
// pick it and send it to the function
// we can subtract size of the left so that the number that previously was generated now lies in the range of size of right side
// TreeNode* getlthNode(int i) {
//     int leftSize = left == nullptr ? 0 : left.size();
//     if (i < leftSize)
//     {
//         return left.getithNode(i);
//     }
//     else if (i == leftSize)
//     {
//         return this;
//     }
//     else
//     {
//         /* Skipping over leftSize + 1 nodes, so subtract them. */
//         return right.getlthNode(i - (leftSize + 1));
//     }
// }

int main(){
    //for our op sake  hardcodes sizes 
    TreeNode* one=new TreeNode(1);
    one->size=1;
    TreeNode* two=new TreeNode(2);
    two->size=1;
    TreeNode* three=new TreeNode(3);
    three->size=3;
    three->left=one;
    three->right=two;
    TreeNode* four=new TreeNode(4);
    four->size=1;
    TreeNode* five=new TreeNode(5);
    five->size=5;
    five->left=three;
    five->right=four;

    TreeNode* result=five->getRandomNode();
    cout<<result->data;
}