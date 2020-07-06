#include<iostream>
#include<vector>
#include<string>
using namespace std;

int search(vector<string>&A,string str,int first,int last){
    if(first>last){
        return -1;
    }
    int mid=(first+last)/2;
    if(A[mid]==""){
        int left=mid-1;
        int right=mid+1;
        while(true){
            if(left<first && right>last){
                return -1;
            }else if(right<=last && A[right]!=""){
                mid=right;
                break;
            }else if(left>=first && A[left]!=""){
                mid=left;
                break;
            }
            left--;
            right++;
        }
    }
    if(A[mid]==str){
        return mid;
    }else if(A[mid].compare(str)<0){
        return search(A,str,mid+1,last);
    }else {
        return search(A,str,first,mid-1);
    }  
}

int main(){
    vector<string>A={"at","","","","ball","","","car","","","dad","",""};
    cout<<search(A,"ball",0,A.size()-1);
}