// Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the
// beginning of the loop.
// DEFINITION
// Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so
// as to make a loop in the linked list.
// EXAMPLE
// Input: A -> B -> C - > D -> E -> C [the same C as earlier]
// Output: C

#include<iostream>
#include<vector>
using namespace std;

//basic Node template
struct Node
{
    char data;
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

Node *vectorToLinkedList(vector<char>v)
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

Node* LoopDetection(Node* head){
    Node* fast=head;
    Node* slow=head;

    while(fast!=nullptr&&fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            break;
        }
    }
    if(fast==nullptr||fast->next==nullptr){
        return nullptr;
    }

    slow=head;
    while(fast!=slow){     //loop start is equally distant from both head and meet point
        fast=fast->next;
        slow=slow->next;
    }
    return fast;

}

int main(){
    vector<char>A={'A','B','C','D','E','F'};
    Node* B=vectorToLinkedList(A);
    Node* temp=B;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=B->next->next->next;
    Node* result=LoopDetection(B);
    cout<<result->data;
}