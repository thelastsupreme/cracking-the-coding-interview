// Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
// column are set to 0.
#include<iostream>
#include<vector>
using namespace std;

void print_vect(vector<vector<int> >&input)
{
	for (int i = 0; i < input.size(); i++) {
		for(int j=0;j<input[i].size();j++)
        {
            cout << input[i][j] << ' ';
        }
        cout<<endl;
	}
}
void print(vector<int>A){
    for (int i = 0; i <A.size(); i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
//method 1 use an other vector of size m*n and store

//method 2 use two boolean vectors to store flags that will be set to false if there is an element 0 in the respective row or column
void setZeroes(vector<vector<int> > &A) {
    vector<bool>col_check(A[0].size(),true);
    vector<bool>row_check(A.size(),true);
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {

            if(A[i][j]==0)
            {
                col_check[j]=false;
                row_check[i]=false;
            }

        }
    }
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {

            if(row_check[i]==false||col_check[j]==false)
            {
                A[i][j]=0;
            }

        }
    }
    print_vect(A);
}
//method 3 it can be done in space of O(1) by using th first row as row_check vector and first column as column_check vector
void setZeros_1(vector<vector<int>>&A){
    bool rowHasZero=false;
    bool colhasZero=false;
    //check if first col has a zero
    for(int i=0;i<A.size();i++){
        if(A[i][0]==0){
            colhasZero=true;
            break;
        }
    }
    //check if first row has a zero
    for(int i=0;i<A[0].size();i++){
        if(A[0][i]==0){
            rowHasZero=true;
            break;
        }
    }
    for(int i=1;i<A.size();i++) //i from second row
    {
        for(int j=1;j<A[i].size();j++) //j from second col
        {

            if(A[i][j]==0)
            {
                A[i][0]=false;  //first col is being used as row_check vector
                A[0][j]=false;  //first row is being used as col_check vector
            }

        }
    }
    
    for(int i=1;i<A.size();i++)
    {
        for(int j=1;j<A[i].size();j++)
        {

            if(A[i][0]==false||A[0][j]==false)
            {
                A[i][j]=0;
            }

        }
    }
    if (rowHasZero)
    {
        for (int i = 0; i <A.size(); i++)
        {
            A[0][i]=0;
        }
        
    }
    if (colhasZero)
    {
        for (int i = 0; i <A.size(); i++)
        {
            A[i][0]=0;
        }
        
    }
    print_vect(A);

}

int main(){
    vector<vector<int>> C={{1,1,0},{1,1,1},{1,0,1}};
    setZeros_1(C);
}