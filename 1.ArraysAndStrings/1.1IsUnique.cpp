// Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
// cannot use additional data structures?
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

//method 1 : take a char array to store flags for each char

//method 2 : using bit manipulation assumption of only lowercase
bool isUniqueChars(string A){
    int checker=0;
    for (int i = 0; i < A.length(); i++){
        int val=A[i]-'a';
        // cout<<checker<<endl;
        // cout<<"cheker&val  "<<(checker&(1<<val))<<endl;
        if((checker&(1<<val))>0){   //if the position already exists then 1 is returned terminating the loop
            return false;
        }
        checker|=(1<<val);  //push one into checker for the rquired char position
    }
    return true;
}
//method 3 : without additonal data structure
bool isUniqueChars_2(string A){
    sort(A.begin(),A.end());
    for (int i = 0; i <A.size()-1; i++)
    {
        if(A[i]==A[i+1]){
            return false;
        }
        return true;
    }
    
}

int main(){
    cout<<isUniqueChars_2("acdb");
}