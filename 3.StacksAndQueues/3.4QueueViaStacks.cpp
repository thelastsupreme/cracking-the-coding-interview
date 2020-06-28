// Queue via Stacks: Implement a MyQueue class which implements a queue using two stacks.

#include<iostream>
#include<stack>
using namespace std;

// In this approach, newStack has the newest elements on top and oldStack has the oldest
// elements on top. When we dequeue an element, we want to remove the oldest element first, and so we
// dequeue from stackOldest. If stackOldest is empty, then we want to transfer all elements from
// stackNewest into this stack in reverse order. To insert an element, we push onto stackNewest, since it
// has the newest elements on top.

template<class T>
class MyQueue{
public:   
    stack<T>newStack,oldStack;
    MyQueue(){

    }
    int size(){
        return newStack.size()+oldStack.size();
    }
    void add(T value){
        newStack.push(value);
    }
    void shiftStacks(){
        if(oldStack.empty()){
            while(!newStack.empty()){
                oldStack.push(newStack.top());
                newStack.pop();
            }
        }
    }
    T peek(){
        shiftStacks();
        return oldStack.top();
    }
    T remove(){
        shiftStacks();
        return oldStack.top();
        oldStack.pop();
    }
    void print(){
        while (!oldStack.empty())
        {
            cout<<oldStack.top()<<" ";
            oldStack.pop();
        }
        
    }

};

int main(){
    MyQueue<char> q;
    q.add('a');
    q.add('b');
    q.add('e');
    q.add('c');
    q.add('h');
    q.add('u');
    q.add('t');
    q.add('i');
    q.add('y');
    q.add('e');
    q.peek();
    q.print();
}