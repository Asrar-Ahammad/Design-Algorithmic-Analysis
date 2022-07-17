#include<iostream>
#include<cstring>
#include<time.h>


#define v 7
using namespace std;

int main(){
    clock_t time;
    time = clock();
    int G [v] [v] = {
        {0,28,0,0,0,10,0},
        {28,0,16,0,0,0,14},
        {0,16,0,12,0,0,0,},
        {0,0,12,22,0,18},
        {0,0,0,22,0,25,24},
        {10,0,0,0,25,0,0},
        {0,14,0,18,24,0,0},
    };
    int edge;

    int visited[v];

    for(int i=0;i<v;i++){
        visited[i] = false; 
    }

    edge = 0;
    visited[0] = true;
    
    int x,y;

    cout<<"Edge     Weight\n";

    while(edge<v-1){
        int min = INT_MAX;
        x = 0;
        y = 0;
        for(int i=0;i<v;i++){
            if(visited[i]){
                for(int j = 0;j<v;j++){
                    if(!visited[j] && G[i][j]){
                        min = G[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        cout<<x<<" ---> "<<y<<" : "<<G[x][y]<<"\n";
        visited[y] = true;
        edge++;
    }
    time = clock()-time;
    cout<<"The time taken to construct spanning tree :"<<(double)time/CLOCKS_PER_SEC;

    return 0;
}