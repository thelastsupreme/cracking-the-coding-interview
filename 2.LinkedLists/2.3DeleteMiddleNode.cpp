// Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but
// the first and last node, not necessarily the exact middle) of a singly linked list, given only access to
// that node.
// EXAMPLE
// lnput:the node c from the linked list a->b->c->d->e->f
// Result: nothing is returned, but the new linked list looks like a->b->d->e- >f

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


//method 1 since u cant acces any nodes before given node just make the value of deleted node same as the one after 
//and delete that node

bool deleteNode(Node* curr){
    if(curr==nullptr||curr->next==nullptr){
        return false;
    }
    Node* next=curr->next;
    curr->data=next->data;
    curr->next=next->next;
    return true;
}

int main(){
    vector<char>A={'a','b','c','d','e','f','g','h','i','j'};
    Node* B=vectorToLinkedList(A);
    print(B);
    deleteNode(B->next->next->next);
    print(B);

}