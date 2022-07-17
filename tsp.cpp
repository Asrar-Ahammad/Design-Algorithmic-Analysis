#include<iostream>
using namespace std;
int cost = 0,graph[4][4],visited[4];

void takeinput(){
    int i;
    cout<<"Enter value :";
    for(int i =0;i<4;i++){
        for(int j = 0 ;j<4;j++){
            cin>>graph[i][j];
        }
    }
    cout<<"\nThe graph is :";
    for(int i =0;i<4;i++){
        for(int j = 0 ;j<4;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int find_next_node(int node){
    int nd,min = INT_MAX,min_index,democost;

    for(int i = 0;i<4;i++){
        if(!visited[i] && graph[node][i]!=0 && graph[node][i]<min){
            democost = cost+graph[node][i];
            min = graph[node][i];
            min_index = i;
        }
    }

    nd = min_index;
    cost = cost+democost;
    return nd;
}

void tsp(int node){
    int next_node;
    visited[node] = 1;
    cout<<node<<" --> ";

    next_node = find_next_node(node);

    if(next_node == INT_MAX){
        int v = 0;
        cost = cost+graph[next_node][v];
        cout<<v;
        return;
    }
    tsp(next_node);
}

int main(){

    takeinput();
    int i ;
    for(int i=0;i<4;i++){
        visited[i] = 0;
    }
    int start;
    cout<<"\nEnter start node :";
    cin>>start;

    cout<<"TSP path ";
    tsp(start);
    return 0;
}