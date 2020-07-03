// Permutations with Duplicates: Write a method to compute all permutations of a string whose
// characters are not necessarily unique. The list of permutations should not have duplicates.

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

//method 1 is to just code for without dups and then from the result vector just extract unique strings


//method 2 use a map to store counters and using them for optimization


void generatePerms(unordered_map<char,int>&map,string str,int rem,vector<string>&result){
    if(rem==0){
        result.push_back(str);
        return;
    }

    for(auto it: map){
        int count=map[it.first]; //gettting count of char
        if(count>0){
            map[it.first]--; //decrement count and call the function
            generatePerms(map,str+it.first,rem-1,result); //str now has your character
            map[it.first]++; //increment count 
        }
    }
}

int main(){
    unordered_map<char,int>map;
    map.insert(make_pair('a',4));
    map.insert(make_pair('b',2)); //hardcoded a map for string aaaabb
    vector<string>result;
    generatePerms(map,"",6,result);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
}