// Peaks and Valleys: In an array of integers, a "peak" is an element which is greater than or equal to
// the adjacent integers and a "valley" is an element which is less than or equal to the adjacent integers.
// For example, in the array {5, 8, 6, 2, 3, 4, 6}, {8, 6} are peaks and {5, 2} are valleys. Given an array
// of integers, sort the array into an alternating sequence of peaks and valleys.
// EXAMPLE
// Input: {5, 3, 1, 2, 3}
// Output: {5, 1, 3, 2, 3}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//method 1 : sort array and swap alternatively

void sortValley(vector<int>&A){
    sort(A.begin(),A.end());
    for(int i=1;i<A.size();i+=2){
        swap(A[i-1],A[i]);
    }
}

//method : best approach O(N)
void sortValley_2(vector<int>&A){
    for(int i=1;i<A.size()-1;i++){
        if(i%2==1){
            if(A[i+1]<A[i])
                swap(A[i],A[i+1]);
        }else
        {
            if(A[i+1]>A[i])
                swap(A[i],A[i+1]);
        }
        
    }
}

//alternative approach from book for O(n);

// void sortValleyPeak(int[] array)
// {
//     for (int i = 1; i < array.length; i += 2)
//     {
//         int biggestindex = maxindex(array, i - 1, i, i + 1);
//         if (i != biggestindex)
//         {
//             swap(array, i, biggestindex);
//         }
//     }
// }

// int maxindex(int[] array, int a, int b, int c)
// {
//     int len = array.length;
//     int aValue a > = 0 && a < len ? array[a] : Integer.MIN_VALUE;
//     int bValue b >= 0 && b < len ? array[b] : Integer.MIN_VALUE;
//     int cValue c >= 0 && c < len ? array[c] : Integer.MIN_VALUE;
//     int max = Math.max(aValue, Math.max(bValue, cValue));
//     if (aValue == max)
//         return a;
//     else if (bValue == max)
//         return b;
//     else
//         return c;
// }

int main(){
    vector<int>A={4,1,7,8,0,9};
    sortValley_2(A);
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
}