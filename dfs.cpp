#include<iostream>
#include<list>

using namespace std;

int main(){
    int cost[10][10],stk[10],top;
    int visited[10];
    int visit[10];

    int m,n;
    cout<<"Enter number of vertices :";
    cin>>m;
    cout<<"Enter number of edges :";
    cin>>n;
    int u,v;
    cout<<"\nEnter edges :\n";
    for(int i=1;i<=n;i++){
        cin>>u>>v;
        cost[u][v]=1;
    }
    int initial;
    cout<<"\nEnter initial vertex to begin :";
    cin>>initial;
    visited[initial]=1;
    int i=1;
    while(i<m){
        
    }
    return 0;
}