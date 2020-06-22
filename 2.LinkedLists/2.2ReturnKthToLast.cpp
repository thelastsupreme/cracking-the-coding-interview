// Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

//basic Node template
struct Node
{
    int data;
    Node* next;
};
void print(Node* front)
{
    if(front==nullptr)
        cout<<"empty"<<endl;
    else
    {
        Node* curr=front;
        while(curr!=nullptr)
        {
            cout<<curr->data<<" -> ";
            curr=curr->next;
        }
    }
    cout<<"null"<<endl;
}

Node *vectorToLinkedList(vector<int>v)
{
    if(v.size()==0)
        return nullptr;
    Node *head=new Node{v[0] ,nullptr};
    Node *currptr=head;
    for(int i=1;i<v.size();i++)
    {
        Node *node=new Node{v[i],nullptr};
        currptr->next=node;
        currptr=node;
    }
    return head;
}
//method 1 best method declare two pointers start the second pointer after first point iterates k elements
// then as first pointer reaches end second pointer is at required location
int KthToLast(Node* head,int k){
    Node* first=head;
    Node* second=head;
    for(int i=0;i<k;i++){
        first=first->next;
    }
    while(first!=nullptr){
        first=first->next;
        second=second->next;
    }
    return second->data;
    
}
//method 2 find size then our element is size-k element from front

//method 3 recursive approach
int printKthToLast(Node* head,int k){
    if(head==nullptr){
        return 0;
    }
    int index=printKthToLast(head->next,k)+1;
    if(index==k)
        cout<<head->data;
    return index;
}
//method 4 same as 3 but passing index as reference
void print_2KthToLast(Node* head,int k,int &i){
    if(head==nullptr){
        return;
    }
    print_2KthToLast(head->next,k,i);
    i++;
    if(i==k){
        cout<<head->data;
    }
}

int main(){
    vector<int>A={1,2,3,4,5,6,7,8,9};
    Node* B=vectorToLinkedList(A);
    // printKthToLast(B,4);//prints 6
    int i=0;
    print_2KthToLast(B,3,i);//prints 7
}