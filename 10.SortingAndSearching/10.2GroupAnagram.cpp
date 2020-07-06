// Group Anagrams: Write a method to sort an array of strings so that all the anagrams are next to
// each other.
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

void sort(vector<string>&A){
    unordered_map<string,vector<string>>map;
    for(string s:A){
        string key=s;
        sort(key.begin(),key.end());
        map[key].push_back(s);
    }
    A.clear();
    for(auto it:map){
        vector<string>temp=it.second;
        for(string s:temp){
            A.push_back(s);
        }
    }
}

int main(){
    vector<string>A={"abcd","efab","dcab","acre","race","care"};
    sort(A);
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<endl;
    }
}