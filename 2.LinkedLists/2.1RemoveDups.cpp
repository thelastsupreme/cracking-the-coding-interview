// Remove Dups! Write code to remove duplicates from an unsorted linked list.
// FOLLOW UP
// How would you solve this problem if a temporary buffer is not allowed?
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

//method 1 use a temporary buffer(in this case unordered_map)
void deleteDups(Node* head){
    unordered_map<int,bool>map;
    Node* temp=head;
    Node* prev=nullptr;
    while(temp!=nullptr){
        if(map.find(temp->data)!=map.end()){
            prev->next=temp->next;
        }else{
            map[temp->data]=true;
            prev=temp;
        }
        temp=temp->next;
    }
}

//method 2 delete all elements of the same value as that of current node as soon as it is encountered
void deleteDups_2(Node*head){
    Node*temp=head;
    while (temp!=nullptr){
        Node* runner=temp;
        while (runner->next!=nullptr){
            if(runner->next->data==temp->data){
                runner->next=runner->next->next;
            }else{
                runner=runner->next;
            }
        }
        temp=temp->next;
    }
    
}
int main(){
    vector<int>A={1,4,7,3,5,6,7,3,2,5,6,7,3,3,5,6,2,4,2,2,1};
    Node* B=vectorToLinkedList(A);
    deleteDups_2(B);
    print(B);
}