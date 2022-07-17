#include<iostream>
using namespace std;

int max(int a,int b){
    return (a>b)?a:b;
}

int knapsack(int weight[],int profit[],int n,int W){
    int sack[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0){
                return 0;
            }
            else if(weight[i-1]<=j){
                sack[i][j] = max(sack[i-1][j],profit[i]+sack[i-1][j-weight[i]]);
            }
            else{
                sack[i][j] = sack[i-1][j];
            }
        }
    }
    cout<< sack[4][8];
}

int main(){
    int weight[]={2,3,4,5};
    int value[]={1,2,5,6};
    int n = sizeof(weight)/sizeof(weight[0]);
    int W = 8;

    cout<<"The maximum profit :"<<knapsack(weight,value,n,W);

    return 0 ;
}