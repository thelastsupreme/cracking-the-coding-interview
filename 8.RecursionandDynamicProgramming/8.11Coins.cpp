// Coins: Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents), and
// pennies (1 cent), write code to calculate the number of ways of representing n cents.

#include<iostream>
#include<vector>
using namespace std;

//method 1: generating all possible combinations with a constraint on the lines of backtracking
//this solution is without using an additional data structure for memoization

int makeChange(int amount,vector<int>&denoms,int index){
    if(index>=denoms.size()-1) return 1;
    int denomAmount=denoms[index];
    int ways=0;
    for(int i=0;i*denomAmount<=amount;i++){     //critical step
        int remainingAmount=amount-i*denomAmount;
        ways+=makeChange(remainingAmount,denoms,index+1); //now check what the next denom has to offer
    }
    return ways;
}

//method 2 : use an array or map for memoization
int makeChange_2(int amount,vector<int>&denoms,vector<vector<int>>&map,int index){
    if(map[amount][index]>0){
        return map[amount][index]; //just access the map rather than finding repeated values again
    }
    if(index>=denoms.size()-1) return 1;
    int denomAmount=denoms[index];
    int ways=0;
    for(int i=0;i*denomAmount<=amount;i++){     //critical step
        int remainingAmount=amount-i*denomAmount;
        ways+=makeChange(remainingAmount,denoms,index+1); //now check what the next denom has to offer
    }
    map[amount][index]=ways; //storing values for a particular amount and index
    return ways;
}

int main(){
    vector<int>denoms={25,10,5,1};
    cout<<makeChange(10,denoms,0)<<endl;
    vector<vector<int>>map(11,vector<int>(denoms.size(),0)); //init with n+1 and denoms.size()
    cout<<makeChange_2(10,denoms,map,0);
}