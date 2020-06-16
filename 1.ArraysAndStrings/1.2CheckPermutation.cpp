// Check Permutation: Given two strings, write a method to decide if one is a permutation of the
// other.
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

//method 1 :sort and check if strings are equal and case sensitive

// bool checkpermutation(string A,string B){
//     sort(A.begin(),A.end());    //sort in algorithm header
//     sort(B.begin(),B.end());

//     if(A==B){
//         return true;
//     }else
//     {
//         return false;
//     }
    
// }
//method 2 check if both strings have same character counts

bool checkpermutation(string A,string B){
    if(A.size()!=B.size())
        return false;
        
    int countsStore[128]={0};        //initialize array to all zeros
    for (int i = 0; i < A.length(); i++)
    {
        countsStore[A[i]]++;    //increment the count at the index which is the ascii value of the char
    }
   
    for (int  i = 0; i<B.length(); i++)
    {
        countsStore[B[i]]--;
        if (countsStore[B[i]]<0)
        {
            return false;
        }
    }
    
}
int main(){
    cout<<checkpermutation("bdeaccc","bcceaca");
}