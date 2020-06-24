// Sum Lists: You have two numbers represented by a linked list, where each node contains a single
// digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a
// function that adds the two numbers and returns the sum as a linked list.
// EXAMPLE
// Input: (7-> 1 -> 6) + (5 -> 9 -> 2).That is,617 + 295.
// Output: 2 -> 1 -> 9. That is, 912.
// FOLLOW UP
// Suppose the digits are stored in forward order. Repeat the above problem.
// EXAMPLE
// lnput:(6 -> 1 -> 7) + (2 -> 9 -> 5).That is,617 + 295.
// Output: 9 - > 1 -> 2. That is, 912.
#include<iostream>
#include<vector>
using namespace std;

//basic Node template
struct Node
{
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
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
    Node *head=new Node(v[0]);
    Node *currptr=head;
    for(int i=1;i<v.size();i++)
    {
        Node *node=new Node(v[i]);
        currptr->next=node;
        currptr=node;
    }
    return head;
}
Node* SumLists(Node* A, Node* B) {
    Node* res= new Node(0);
    Node* temp1=res;
    int sum=0,carry=0;
    Node* tempa=A;
    Node* tempb=B;
    while(tempa!=NULL&&tempb!=NULL)
    {
        int sum=tempa->data+tempb->data+carry;
        if(sum>9)
        {
            carry=1;
            sum=sum-10;
        }
        else
            carry=0;
        Node* temp=new Node(sum);
        temp1->next=temp;
        temp1=temp1->next;
        tempa=tempa->next;
        tempb=tempb->next;

    }
    while(tempa!=NULL)
    {
        sum=tempa->data+carry;
        if(sum>9)
        {
            carry=1;
            sum-=10;
        }
        else
            carry=0;
        Node* temp=new Node(sum);
        temp1->next=temp;
        temp1=temp1->next;
        tempa=tempa->next;
    }
    while(tempb!=NULL)
    {
        sum=tempb->data+carry;
        if(sum>9)
        {
            carry=1;
            sum-=10;
        }
        else
            carry=0;
        Node* temp=new Node(sum);
        temp1->next=temp;
        temp1=temp1->next;
        tempb=tempb->next;
    }
    if(carry==1)
    {
        Node *temp =new Node(1);
        temp1->next=temp;
    }
    return res->next;
}

//for follow up just pad the list with less elements with 0s to make both lists the same
int main(){
    vector<int>A={7,1,6}; //617
    vector<int>B={5,9,2}; //295
    Node* num1=vectorToLinkedList(A);
    Node* num2=vectorToLinkedList(B);
    Node* result=SumLists(num1,num2);
    print(result);
}
