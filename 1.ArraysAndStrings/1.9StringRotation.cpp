// String Rotation: Assume you have a method i 5Su b 5 tr ing which checks if one word is a substring
// of another. Given two strings, 51 and 52, write code to check if 52 is a rotation of 51 using only one
// call to i5Sub5tring (e.g., "waterbottle" is a rotation of" erbottlewat").
#include<iostream>
#include<string>
using namespace std;

//method algo: take the string s1 and attack s1 to itself if s2 is a substring of s1 now then definitely its a roated substring

bool isRotation(string s1,string s2){
    if(s2.size()!=s1.size()) return false;
    s1.append(s1);
    return (s1.find(s2)!=string::npos);  //find returns index on found and string::npos on not found
}

int main(){
    cout<<isRotation("waterbottle","erbottlewat");
}