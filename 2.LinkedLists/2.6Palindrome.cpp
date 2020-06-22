// Palindrome: Implement a function to check if a linked list is a palindrome.
#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
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

//method 1 reverse and compare
Node* reverseAndClone(Node* head){
    Node* newhead=nullptr;
    while(head!=nullptr){
        Node* temp=new Node{head->data,nullptr};
        temp->next=newhead;
        newhead=temp;
        head=head->next;
    }
    return newhead;
}
bool isEqual(Node* one,Node* two){
    while (one!=nullptr&&two!=nullptr){
        if(one->data!=two->data)
            return false;
        one=one->next;
        two=two->next;
    }
    return(one==nullptr&&two==nullptr);
}
bool isPalindrome(Node *head){
    Node* reverse=reverseAndClone(head);
    return isEqual(head,reverse);
}

//method 2 iterative approach using a stack
bool isPalindrome_2(Node* head){
    //using a slow pointer fast pointer approach to get to mid
    Node* slow=head;
    Node* fast=head;
    stack<int>s;
    while(fast!=nullptr&&fast->next!=nullptr){      //by the time fast pointer reaches the end slow pointer reaches mid
        s.push(slow->data);
        slow=slow->next;
        fast=fast->next->next;     
    }

    //if odd elements in the list skip the middle element
    if(fast!=nullptr){
        slow=slow->next;
    }
    while(slow!=nullptr){
        int top=s.top();
        s.pop();
        if(top!=slow->data){
            return false;
        }
        slow=slow->next;
    }
    return true;
}

int main(){
    vector<int>A={1,2,3,4,3,2,1};
    Node* B=vectorToLinkedList(A);
    cout<<isPalindrome_2(B);
}