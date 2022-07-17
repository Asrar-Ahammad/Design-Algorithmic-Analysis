#include<iostream> 
using namespace std;

int adjmat[20][20];

void print(int v){
    for(int i=0;i<=v; i++){
        for(int j=0; j<=v;j++){
            cout<<adjmat[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void addedge(int u,int v){
    adjmat[u][v]=1;
    adjmat[v][u]=1;
}

int main(){
    int v,e;
    cout<<"Enter number of vertices :";
    cin>>v;
    cout<<"Enter number of edges :";
    cin>>e;
    int u,y;
    for(int i=0;i<e;i++){
        cout<<"Enter start :";
        cin>>u;
        cout<<"Enter destination :";
        cin>>y;
        addedge(u,y);
        u = 0;
        y = 0;
    }
    print(v);
}
