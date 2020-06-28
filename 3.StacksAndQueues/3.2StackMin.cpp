// Stack Min: How would you design a stack which, in addition to push and pop, has a function min
// which returns the minimum element? Push, pop and min should all operate in 0(1) time.
#include<iostream>
#include<stack>
using namespace std;

//method 1 use a stack of objects which store the element value and min value till then 
//the book uses an object oriented approach i would go for a stack of pairs

// class StackMin
// {
// public:
//     stack<pair<int,int>>Stackmin; //first element is value second element is min till then

//     void StackMinpush(int value){
//         int newMin=min(value,minn());
//         Stackmin.push(make_pair(value,newMin));
//     }

//     int minn(){
//         if(Stackmin.empty()){
//             return INT32_MAX;  //return the max value so that current element is min at beginning of stack
//         }else{
//             return Stackmin.top().second;
//         }
//     }
    
// };

// int main(){
//     StackMin a;
//     a.StackMinpush(10);
//     a.StackMinpush(3);
//     a.StackMinpush(4);
//     a.StackMinpush(1);
//     a.StackMinpush(9);
//     a.StackMinpush(2);
//     while (!a.Stackmin.empty())
//     {
//         cout<<a.Stackmin.top().first<<" "<<a.Stackmin.top().second<<endl;
//         a.Stackmin.pop();
//     }
    
// }


//method 2 instead of storing min for each and every element use another stack just to store one min(kinda like a global min)
class StackMin
{
public:
    stack<int>s;//to store values
    stack<int>minStack; //to just store min values

    void pushh(int value){
        if(value<=min()){
            minStack.push(value);
        }
        s.push(value);
    }

    int min(){
        if(minStack.empty()){
            return INT32_MAX;
        }else{
            return minStack.top();
        }
    }

    void popp(){
        int x=s.top();
        s.pop();
        if(x==minStack.top()){
            minStack.pop();
        }
    }
    
    int topp(){
        return s.top();
    }
    
};

int main(){
    StackMin a;
    a.pushh(10);
    a.pushh(3);
    a.pushh(4);
    a.pushh(1);
    a.pushh(9);
    a.pushh(2);
    a.pushh(0);

    while (!a.s.empty())
    {
        cout<<a.topp()<<endl;
        a.s.pop();
    }
    cout<<"Min stack is :"<<endl;
    while (!a.minStack.empty())
    {
        cout<<a.minStack.top()<<endl;
        a.minStack.pop();
    }
    cout<<endl;
    cout<<"popp() check"<<endl;
    //checking if popp() is working
    a.pushh(10);
    a.pushh(3);
    a.pushh(4);
    a.pushh(1);
    a.pushh(9);
    a.pushh(2);
    a.pushh(0);
    a.popp();

    while (!a.s.empty())
    {
        cout<<a.topp()<<endl;
        a.s.pop();
    }
    cout<<"Min stack is :"<<endl;
    while (!a.minStack.empty())
    {
        cout<<a.minStack.top()<<endl;
        a.minStack.pop();
    }

}
