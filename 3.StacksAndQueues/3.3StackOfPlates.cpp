// Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
// Therefore, in real life, we would likely start a new stack when the previous stack exceeds some
// threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks should be
// composed of several stacks and should create a new stack once the previous one exceeds capacity.
// SetOfStacks. push() and SetOfStacks. pop() should behave identically to a single stack
// (that is, pop () should return the same values as it would if there were just a single stack).

// FOLLOW UP
// Implement a function popAt(int index) which performs a pop operation on a specific substack.
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class SetOfStacks{
public:
    vector<stack<int>>stacks;
    int capacity;
    int pushIdx=0;
    int popIdx=0;

    SetOfStacks(int capacity){
        this->capacity=capacity;
    }
    
    void pushh(int val){
        if(stacks.size()==pushIdx){
            stack<int>temp;
            stacks.push_back(temp);
        }
        if(stacks[pushIdx].size()==capacity){ //if full increment index and call again
            pushIdx++;
            pushh(val); //recursive call to push now that we have incremented push index
        }else{
            popIdx=max(popIdx,pushIdx); //pop index will always be the latest update of pushIdx or the inital one whichever is max
            stacks[popIdx].push(val);  //push at required location
        }
    }

    int popp(){
        if(stacks.size()==0) return -1; //if no stack exists return -1
        if(stacks[popIdx].size()==0){ //is size of the stack at index is 0 then decrement popIdx and call function again
            if(popIdx==0)   //incase ur popIdx is 0 return -1
                return -1;
            popIdx--;
            return popp();
        }
        int val=stacks[popIdx].top();
        stacks[popIdx].pop();
        pushIdx=min(pushIdx,popIdx); //update pushIdx
        return val;
    }

    int popAtStack(int index){  //just pops at index doesnt do the shifting part
        if(stacks.size()<=index||stacks[index].size()==0)return -1; //check if the required stack exists
        int val=stacks[index].top();
        stacks[index].pop();
        pushIdx=min(pushIdx,popIdx);
        return val;
    }
    void print(){
        for (int  i = 0; i <stacks.size(); i++)
        {
            cout<<"stack"<<i<<":"<<endl;
            while(!stacks[i].empty()){
                cout<<stacks[i].top()<<endl;
                stacks[i].pop();
            }
            cout<<endl;
        }
        
    }
    
};

int main(){
    SetOfStacks ss(5); //capacity of each stack is 5
    ss.pushh(1);
    ss.pushh(2);
    ss.pushh(3);
    ss.pushh(4);
    ss.pushh(5);
    ss.pushh(6);
    ss.pushh(7);
    ss.pushh(8);
    ss.popp();
    ss.print();

}

//approach using maps

    // class SetOfStacks{
    //     int c;
    //     map<int, vector<int>> m;
    //     set<int> available;

    //     SetOfStacks(int capacity) {
    //         c = capacity;
    //     }

    //     void push(int val) {
    //         if (available.empty())
    //             available.insert(m.size());
    //         m[*available.begin()].push_back(val);
    //         if (m[*available.begin()].size() == c)
    //             available.erase(available.begin());
    //     }

    //     int pop() {
    //         while (m.size() && m.rbegin()->second.empty()) {
    //             m.erase(m.rbegin()->first);
    //         }
    //         if (m.empty()) return -1;
    //         return popAtStack(m.rbegin()->first);
    //     }

    //     int popAtStack(int index) {
    //         if (m[index].empty())
    //             return -1;
    //         int val = m[index].back();
    //         m[index].pop_back();
    //         available.insert(index);
    //         if (m[index].empty())
    //             m.erase(index);
    //         return val;
    //     }
    // };

//*********************************************************************************************
//online approach using pointers

// vector<stack<int>*> vec;  //vector of pointers to stacks
// int index = 0;
// bool initialized = false;

// void init_stacks()
// {
//    stack<int> *s = new stack<int>; //creating a new stack an storing its pointer in s
//    vec.push_back(s);
// }

// void stack_push(int v)
// {
//     if(initialized == false){  //for creation of first stack
//         initialized = true;
// //        init_stacks();
//     }

//     stack<int> *s = vec.at(index);
//     if(s->size() == 5){ //capacity of 5 assumed
//         s = new stack<int>;
//         vec.push_back(s);
//         index ++ ; //increment index on creation of new stack
//     }

//     s->push(v);
// }

// void stack_pop()
// {
//     stack<int> *s = vec.at(index);
//     if(index > 0){
//         if(s->size() == 0){  //if current stack is empty delete it
//             delete s;
//             index --;  //decrement the index
//             s = vec.at(index);
//         }
        
//         s->pop(); //then pop ot
//     }
//     else{
//         if(s->size() == 0){
//             ;//cout << " no more elements in stack !" << endl;
//         }
//         else{
//             s->pop();
//         }
//     }
// }

