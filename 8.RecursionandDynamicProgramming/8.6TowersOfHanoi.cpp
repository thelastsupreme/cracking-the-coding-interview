// Towers of Hanoi: In the classic problem of the Towers of Hanoi, you have 3 towers and N disks of
// different sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending order
// of size from top to bottom (i.e., each disk sits on top of an even larger one). You have the following
// constraints:
// (1) Only one disk can be moved at a time.
// (2) A disk is slid off the top of one tower onto another tower.
// (3) A disk cannot be placed on top of a smaller disk.
// Write a program to move the disks from the first tower to the last using stacks.

#include<iostream>
#include<stack>
using namespace std;


void towersOfHanoi(stack<int>&src,stack<int>&temp,stack<int>&dest,int N){
    if (N<=0|| src.size()==0){
        return;
    }
    towersOfHanoi(src,dest,temp,N-1); //src to temp for n-1 disks
    dest.push(src.top());
    src.pop();
    towersOfHanoi(temp,src,dest,N-1);  //temp to dest for n-1 disks
}

int main(){
    stack<int>src;
    stack<int>temp;
    stack<int>dest;
    for (int i = 10- 1; i >= 0; i--)
    {
        src.push(i);
    }
    towersOfHanoi(src,temp,dest,10);
    while(!dest.empty()){
        cout<<dest.top()<<endl;
        dest.pop();
    }
    
}