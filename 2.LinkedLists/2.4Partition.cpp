// Partition: Write code to partition a linked list around a value x, such that all nodes less than x come
// before all nodes greater than or equal to x. If x is contained within the list, the values of x only need
// to be after the elements less than x (see below). The partition element x can appear anywhere in the
// "right partition"; it does not need to appear between the left and right partitions.
// EXAMPLE
// Input:
// Output:
// 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition= 5]
// 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
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

//method 1 take two pointers less than x are assigned to head and greater to tail
Node *Partition(Node* curr,int x){
    Node* head=curr;
    Node* tail=curr;
    while (curr!=nullptr){
        Node* next=curr->next;
        if (curr->data<x){
            curr->next=head;
            head=curr;
        }else{
            tail->next=curr;
            tail=curr;
        }
        curr=next;    
    }
    tail->next=nullptr;
    return head; 
}

//method 2 declare 4 pointers and an if else ladder

int main(){
    vector<int>A={3,5,8,5,10,2,1};
    Node* B=vectorToLinkedList(A);
    print(B);
    cout<<endl;
    Node* C=Partition(B,5);
    print(C);
}

