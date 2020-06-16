
// One Away: There are three types of edits that can be performed on strings: insert a character,
// remove a character, or replace a character. Given two strings, write a function to check if they are
// one edit (or zero edits) away.
// EXAMPLE
// pale, ple -> true
// pales, pale -> true
// pale, bale -> true
// pale, bake -> false

#include<iostream>
#include<string>
using namespace std;

bool OneEditAway(string first,string second){
    if(abs(first.length()-second.length()>=2)){  //if diff in length >1 return false
        return false;
    }
    string large=(first.length()>=second.length())?first:second; //get string with larger size intp large
    string small=(first.length()<second.length())?first:second;

    // cout<<large<<endl;
    // cout<<small<<endl;
    bool flag=false;      //flag to check if char at position didnt match
    int index1=0,index2=0;
    while (index1<large.length()&&index2<small.length())
    {
        if(large[index1]!=small[index2]){
           if (flag)
           {
               return false;         //if the flag is already set then return false 
           }
           flag=true;                //else set the flag
           if(large.length()==small.length()){
               index2++;             //if both strings are same length increment index2 to go to next char
           }
        }
        else
        {
            index2++;                //if chars match go to next char in small string
        }
         index1++;                   //no matter what explore next char of the large string
    }
    return true;
}
int main(){

    cout<<OneEditAway("pale","ple"); 
    cout<<OneEditAway("pales","pale"); 
    cout<<OneEditAway("pale","bale"); 
    cout<<OneEditAway("pale","bake"); 
}