// Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4
// bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(std::vector<vector<int>> const &input)
{
	for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input.size(); j++)
        {
            std::cout<< input[i][j] << ' ';
        }	
        cout<<endl;
	}
}
//method 1 algo
// 1 for i = 0 to n
// 2 temp= top[i];
// 3 top[i] = left[i]
// 4 left[i] = bottom[i]
// 5 bottom[i] = right[i]
// 6 right[i] = temp

void rotate_1(vector<vector<int> > &matrix) {
    int len = matrix.size();
    for (int i = 0; i < len / 2; i++) {
        for (int j = i; j < len - i - 1; j++) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[len - j - 1][i];
        matrix[len - j - 1][i] = matrix[len - i - 1][len - j - 1];
        matrix[len - i - 1][len - j - 1] = matrix[j][len - i - 1];
        matrix[j][len - i - 1] = tmp;
        }
    }
}

//method 2 trying transpose and mirror image
bool rotate(vector<vector<int>>A){
    if(A.size()==0||(A.size()!=A[0].size())){
        return false;
    }
   for(int i=0;i<A.size();i++)
    {
        for(int j=i;j<A[0].size();j++)
            swap(A[i][j],A[j][i]);
    }
    for(int i=0;i<A.size();i++)
        reverse(A[i].begin(),A[i].end());
    print(A);
}

    
int main()
{
    vector<vector<int>>A={{1,2,3},{4,5,6},{7,8,9}};
    rotate(A);
}