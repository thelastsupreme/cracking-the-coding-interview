// String Compression: Implement a method to perform basic string compression using the counts
// of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the
// "compressed" string would not become smaller than the original string, your method should return
// the original string. You can assume the string has only uppercase and lowercase letters (a - z).


#include<iostream>
#include<string>
#include<sstream>
using namespace std;

//method 1
// string compression(string s){
//     stringstream ss;                //using a stringstream so as to push the numbers into string without conversion
//     int count=0;
//     for(int i=0;i<s.length();i++){
//         // if(s[i]==s[i+1]){
//         //     count++;
//         // }else
//         // {
//         //     count++;
//         //     ss<<s[i]<<count;
//         //     count=0;
//         // }
//         count++;
//         if(i+1>s.length()||(s[i]!=s[i+1])){  //instead of going for an if else its better to go for a single if since count is being done in both cases
//             ss<<s[i]<<count;    //pushing the char and its count into the stream
//             count=0;
//         }
//     }
//     string s1=ss.str();         //covert stringstream to a string
//     s=(s1.length()>=s.length())?s:s1;      //choose whaterver is of least size initial string or compressed one
//     return s;
// }


//*******************************method 2*************************************************

int compressed_length(string s){     //function to check lemgth of compressed string
    int compressedLength=0;
    int count=0;
    for(int i=0;i<s.length();i++){
        count++;
        if(i+1>s.length()||(s[i]!=s[i+1])){ //instead of going for an if else its better to go for a single if since count is being done in both cases
            stringstream ss;                //three lines of code to get length of the integer count
            ss<<count;                      //or use to_string(count).length()
            string x=ss.str();              //to_string isnt working on mingw
            compressedLength+=x.length()+1;
            count=0;
        }
    }
    return compressedLength;
}

string compression(string s){
    if(compressed_length(s)>=s.length())    //if the retunrned compressed string length is greater then just return s
        return s;
    else{
        stringstream ss;               //using a stringstream so as to push the numbers into string without conversion
        int count=0;
        for(int i=0;i<s.length();i++){
            count++;
            if(i+1>s.length()||(s[i]!=s[i+1])){  //instead of going for an if else its better to go for a single if since count is being done in both cases
                ss<<s[i]<<count;    //pushing the char and its count into the stream
                count=0;
            }
        }
        s=ss.str();         //covert stringstream to a string
        return s;
    }
}

int main(){
    string ans=compression("abcddddd");
    string ans2=compression("abcdddddd");
    cout<<ans<<endl;
    cout<<ans2<<endl;
}