// Permutations without Dups: Write a method to compute all permutations of a string of unique
// characters.

#include<iostream>
#include<vector>
#include<string>
using namespace std;

//method 1 by generating all possible solutions
void getPermsHelper(string &str,string temp,vector<string>&result){
    if(str.size()==0){
        result.push_back(temp);
    }else{
        for(int i=0;i<str.size();i++){
            char c=str[i];         //store char in c
            str.erase(str.begin()+i);  //remove that from main string
            temp.push_back(c);     //push it into temp string
            getPermsHelper(str,temp,result);//recursive call on the changed strings
            temp.pop_back();       //remove element from temp string
            str.insert(str.begin()+i,c);//insert element back in main string
        }
    }
}
vector<string>getPerms(string str){
    string temp="";
    vector<string>result;
    getPermsHelper(str,temp,result);
    return result;
}
//method 2
// P(a1a2a3a4 ) = {a1 + P(a2a3a4 )} + {a2 + P(a1a3a4 )} + {a3 + P(a1a2a4 )} + {a4 + P(a1a2a3)}
//just passing the indices and a prefix

//pseudo code
/*
    for (int i= 0; i < len; i++) {
    // Remove char i and find permutations of remaining chars.
        String before= remainder.substring(0, i);
        String after = remainder.substring(i + 1, len);
        Arraylist<String> partials = getPerms(before + after); //removing char in unique way
    // Prepend char i to each permutation.
        for (String s : partials) {
            result.add(remainder.charAt(i) + s);
    }

*/
int main()
{
    vector<string>result=getPerms("abc");
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
}