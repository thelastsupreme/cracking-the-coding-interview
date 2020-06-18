// URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string
// has sufficient space at the end to hold the additional characters, and that you are given the "true"
// length of the string. (Note: if implementing in Java, please use a character array so that you can
// perform this operation in place.)
// EXAMPLE
// Input: "Mr John Smith  ", 13
// Output: "Mr%20John%20Smith"

#include<iostream>
#include<string>
using namespace std;

void replace(string A,int length){
   A.resize(length);            //remove ending spaces
    cout<<A<<"."<<endl;
   string rep="%20";
   for (int i = 0; i <length; i++)
   {
       if(A[i]==' '){
           A.insert(i,"  ");  //insert two whitespaces making it total of 3
           A.replace(i,rep.length(),rep); //then replace those whitespaces with %20
       }
   }
   cout<<A;
}

int main(){
    replace("Mr John Smith   ", 13);
}