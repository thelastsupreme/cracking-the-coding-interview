// Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome.
// A palindrome is a word or phrase that is the same forwards and backwards. A permutation
// is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

// EXAMPLE
// Input: Tact Coa
// Output: True (permutations: "taco cat", "atco eta", etc.)
#include<iostream>
#include<string>
#include<unordered_map>
#include<bitset>
using namespace std;

// method 1
// using a map to store the frequencies of char counts if char count is odd for more than 1 element then return false
// case sensitive considered
// spaces considered if spaces insensitive use if condition A[i]<='z'&&A[i]>='a'

// bool checkPalindromePerm(string A){
//     unordered_map<char,int>map;
//     for (int i = 0; i <A.length(); i++)
//     {
//         if(map.find(A[i])!=map.end()){
//             map[A[i]]++;
//         }else {
//             map[A[i]]=1;
//         }    
//     }
   
//     auto it =map.begin();
//     bool oddFlag=false;
//     while(it!=map.end()){
//         if(((it->second)%2==1)&&!oddFlag){
//             oddFlag=true;
//         }
//         else if(((it->second)%2==1)&&oddFlag){
//             return false;
//         }
//          it++;
//     }
//     return true;   
// }

//method 2 same as method 1 but use array to store frequency rather than a map

//method 3 using a bitset
bool checkPalindromePerm(string A){
    bitset<26>bs;//assuming only lower case alphabets in the string

    for (int i = 0; i < A.length(); i++)
    {
        bs.flip(A[i]-'a');  //index starts from 1  --> if odd count then 1 if even count 0
    }
    if(bs.count()>1){             //counts number of 1s
        return false;
    }
    return true;
    
}
int main(){
    cout<<checkPalindromePerm("tactcoa");
}