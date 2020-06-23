// Intersection: Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting
// node. Note that the intersection is defined based on reference, not value. That is, if the kth
// node of the first linked list is the exact same node (by reference) as the jth node of the second
// linked list, then they are intersecting.
#include<iostream>
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

//method 1 to check for intersection run a loop to find if the terminating nodes are the same and calculate
//lengths of the lists in the process then for the bigger size list run the loop (size of A-B times) and run both together and check for common node

Node* findTail(Node* head,int &size){
    while(head->next!=nullptr){
        size++;
        head=head->next;
    }
    return head;
}

Node* findIntersection(Node* A,Node* B){
    int sizeA=1;
    int sizeB=1;
    Node* tailA=findTail(A,sizeA);
    Node* tailB=findTail(B,sizeB);
    if(tailA!=tailB){
        return nullptr;
    }
    int maxx=max(sizeA,sizeB);
    if(maxx==sizeA){
        for (int i = 0; i < sizeA-sizeB; i++)
        {
            A=A->next;
        }
    }else
    {
        for (int i = 0; i < sizeB-sizeA; i++)
        {
            B=B->next;
        }
    }
    while(A!=B){
        A=A->next;
        B=B->next;
    }
    return A;  //or return B
}

int main(){
    vector<int>L1={4,5,6,7,8,9,10};
    vector<int>L2={1,2,3};
    Node* list1=vectorToLinkedList(L1);
    Node* list2=vectorToLinkedList(L2);
    Node* temp1=list1;
    Node* temp2=list2;
    for (int i = 0; i < 3; i++)
    {
        temp1=temp1->next;
    }
    while (temp2->next!=nullptr)
    {
        temp2=temp2->next;
    }
    temp2->next=temp1;
    
    print(list1);
    print(list2);
    Node* result=findIntersection(list1,list2);
    cout<<result->data;
}