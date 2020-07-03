// Magic Index: A magic index in an array A [ 0 ••• n -1] is defined to be an index such that A[ i] =
// i. Given a sorted array of distinct integers, write a method to find a magic index, if one exists, in
// array A.
// FOLLOW UP
// What if the values are not distinct?

#include<iostream>
#include<vector>
using namespace std;

//method 1 brute force linear time straight forward

int magicSlow(vector<int>A){
    for(int i=0;i<A.size();i++){
        if(A[i]==i)
            return i;
    }
}

//method 2 using a binary search approach

int magicFast(vector<int>&A,int start,int end){
    if(end<start){
        return -1;
    }
    int mid=(start+end)/2;
    if(A[mid]==mid){
        return mid;
    }else if (A[mid]>mid){  //implies after mid u wont get a match
        return magicFast(A,start,mid-1);
    }else{
        return magicFast(A,mid+1,end);
    }
}

//follow up if duplicate are allowed 

int magicDups(vector<int>&A,int start,int end){
    if(end<start){
        return -1;
    }
    int mid=(start+end)/2;
    int midValue=A[mid];
    if(mid==midValue){
        return mid;
    }
    int leftIdx=min(midValue,mid-1);
    int leftVal=magicDups(A,start,leftIdx); //so u only search from start to either mid index-1 or the midvalue
    if(leftVal>0){
        return leftVal;
    }
    int rightIdx=max(midValue,mid+1);
    int rightVal=magicDups(A,rightIdx,end);
    return rightVal;
}
int main(){
    vector<int>A={-12,2,2,2,9,10,15};
    cout<<magicFast(A,0,A.size()-1)<<endl; //here op 1 since duplicate array used for test 
    cout<<magicDups(A,0,A.size()-1);
}
