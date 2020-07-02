// Triple Step: A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3
// steps at a time. Implement a method to count how many possible ways the child can run up the
// stairs.
#include<iostream>
#include<vector>
using namespace std;

//method1 using brute force and recursion

int countWaysRecursion(int n){
    if(n<0){
        return 0;
    }else if (n==0){
        return 1;
    }else{
        return countWaysRecursion(n-1)+countWaysRecursion(n-2)+countWaysRecursion(n-3);
        //choices made to reach n-1 step and n-2 step and n-3 step all combined
    }
}

int countWaysDynamic(int n){
    vector<int>temp(n+1,0);{
        temp[0]=1;
        temp[1]=1;
        temp[2]=2;
        for(int i=3;i<temp.size();i++){
            temp[i]=temp[i-1]+temp[i-2]+temp[i-3];
        }
    }
    return temp[n];
}

int main(){
    cout<<countWaysRecursion(10)<<endl;
    cout<<countWaysDynamic(10)<<endl;
}