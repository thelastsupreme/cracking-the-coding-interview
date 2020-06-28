// Three in One: Describe how you could use a single array to implement three stacks.
#include<iostream>
#include<vector>
using namespace std;


//method 1 

// We can divide the array in three equal parts and allow the individual stack to grow in that limited space.
// Note: We will use the notation "[" to mean inclusive of an end point and "(" to mean exclusive of an end
// point.
// For stack 1, we will use [0, X).
// For stack 2, we will use [ X , 2X ) .
// For stack 3, we will use [ 2X , n) .

class FixedMultiStack{
private:
    int numberOFStacks=3;
    int stackCapacity;
    vector<int>values;//vector to store all the values
    vector<int>sizes; //vector to store size of each stack

    //ost important function to solve this question
    int indexOfTop(int stackNum){
        int offset=stackNum*stackCapacity;
        int size=sizes[stackNum];
        return offset+size-1; //say stack 1 capacity 10 curr size 8 
        //implies location of top for stack 1 is at index 17
    }
public:
    FixedMultiStack(int stackSize){
        stackCapacity=stackSize;
        values.resize(stackSize*numberOFStacks);//on resize default elements are 0s
        sizes.resize(numberOFStacks);
    }
    void push(int stackNum,int value){
        if(isFull(stackNum)){
            cout<<"stack"<<stackNum<<" is full"<<"cant push"<<endl;
        }
        sizes[stackNum]++;//increment size
        values[indexOfTop(stackNum)]=value;
    }
    int pop(int stackNum){
        if(isEmpty(stackNum)){
            cout<<"stack "<<stackNum<<" is empty"<<"cant pop"<<endl;
            return INT32_MIN;
        }
        int topIndex=indexOfTop(stackNum);//get index of top
        int value=values[topIndex];//extract the value
        values[topIndex]=0;//clear the value
        sizes[stackNum]--;//decrement its size
        return value;
    }
    int peek(int stackNum){
        if(isEmpty(stackNum)){
            cout<<"stack "<<stackNum<<" is empty"<<endl;
            return INT32_MIN;
        }
        return values[indexOfTop(stackNum)];
    }
    bool isEmpty(int stackNum){
        return sizes[stackNum]==0;
    }
    bool isFull(int stackNum){
        return sizes[stackNum]==stackCapacity;
    }
    void print(){
        for(int i=0;i<values.size();i++){
            cout<<values[i]<<"\t";
        }
    }
};

int main(){
    FixedMultiStack fms(10);//capacity of each stack=10
    fms.push(0,2);
    fms.push(0,4);
    fms.push(0,8);
    fms.push(0,16);
    fms.push(0,32);
    fms.push(0,64);
    fms.push(0,128);
    fms.push(0,256);
    fms.push(0,512);
    fms.push(1,1);
    fms.push(1,2);
    fms.push(1,3);
    fms.push(1,4);
    fms.push(1,5);
    fms.push(1,6);
    fms.push(1,7);
    fms.push(1,8);
    fms.push(1,9);
    fms.push(1,10);
    fms.peek(3);//peek empty stack 3
    fms.print(); //prints stack 3 is empty
    /* output:
     *  2       4       8       16      32      64      128     256    512     0       1
     *  1       2       3       4       5       6      7       8       9       10       
     *  0       0       0       0      0       0       0       0       0       0   
    */
}

//method 2 dynamic allocation
