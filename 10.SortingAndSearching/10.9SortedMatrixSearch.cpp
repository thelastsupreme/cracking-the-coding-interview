// Sorted Matrix Search: Given an M x N matrix in which each row and each column is sorted in
// ascending order, write a method to find an element.
#include<iostream>
#include<vector>
using namespace std;

//method 1: smart linear search

pair<int,int>findElement(vector<vector<int>>&matrix,int elem){
    int row=0;
    int col=matrix[0].size()-1;
    //starting at right top most corner
    while (row<matrix.size()&&col>=0){
        if(matrix[row][col]==elem){
            return make_pair(row,col);
        }else if (matrix[row][col]>elem){
            col--;
        }else{
            row++;
        }
    }
    return make_pair(-1,-1);
}

//method 2 improved binary search
bool findNum(vector<vector<int>>&matrix,pair<int,int>x,pair<int,int>y,int key)
{
    if (x.first > x.second || y.first > y.second || x.second < x.first || y.second < y.first) return false;
    if ((x.first == x.second) && (y.first == y.second) && (matrix[x.first][y.first] != key)) return false;
    if (matrix[x.first][y.first] > key || matrix[x.second][y.second] < key) return false;
    if (matrix[x.first][y.first] == key || matrix[x.second][y.second] == key) return true;

    int xnew = (x.first + x.second)/2;
    int ynew = (y.first + y.second)/2;

    if (matrix[xnew][ynew] == key) return true;
    if (matrix[xnew][ynew] < key)      //or make a detailed if else ladder so as to decrease the number of recusrion calls
    {
        if (findNum(matrix,make_pair(xnew+1,x.second),make_pair(y.first,y.second),key))
            return true;
        return (findNum(matrix,make_pair(x.first,x.second),make_pair(ynew+1,y.second),key));
    } else {
        if (findNum(matrix,make_pair(x.first,xnew-1),make_pair(y.first,y.second),key))
            return true;
        return (findNum(matrix,make_pair(x.first,x.second),make_pair(y.first,ynew-1),key));
    }
}
int main(){
    vector<vector<int>>A={  {15,20,40,85},
                            {20,35,80,95},
                            {30,55,95,105},
                            {40,80,100,120}};
    pair<int,int>ans=findElement(A,89);
    cout<<"row : "<<ans.first<<" col : "<<ans.second<<endl;
    cout<<findNum(A,make_pair(0,A[0].size()-1),make_pair(0,A.size()-1),35);
}