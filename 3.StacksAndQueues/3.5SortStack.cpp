// Sort Stack: Write a program to sort a stack such that the smallest items are on the top. You can use
// an additional temporary stack, but you may not copy the elements into any other data structure
// (such as an array). The stack supports the following operations: push, pop, peek, and is Empty.
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//method 1 using a temp stack 

void sort(stack<int>&s){
    stack<int>r;        //temp stack
    
    while(!s.empty()){  //continue until given stack is not empty
        int temp=s.top();   
        s.pop();                //put top item in s in temp
        while(!r.empty()&& r.top()>temp){  //if r.top is greater push it to s 
            s.push(r.top());
            r.pop();
        }
        r.push(temp);   //then push your temp
    }

    while (!r.empty())
    {
        s.push(r.top());
        r.pop();
    }
    
}

int main(){
   stack<int>s;
   s.push(2);
   s.push(9);
   s.push(4);
   s.push(3);
   s.push(8);
   s.push(1);

   sort(s);

   while (!s.empty())
   {
       cout<<s.top()<<endl;
       s.pop();
   }
   
}