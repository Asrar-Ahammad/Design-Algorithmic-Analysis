#include<iostream>
#include<vector>

using namespace std;

#define v 4

int tsp(int graph[][v],int s){
    vector<int>vertex;
    for(int i=0;i<v;i++){
        if(i!=s){
            vertex.push_back(i);
        }
    }
    int min_path =  INT_MAX;
    do{
        int current_path = 0;

        for(int i = 0;i<vertex.size();i++){
            
        }

    }while(next_permutation(vertex.begin(),vertex.end()));
}

int main(){
    int graph[][v] = { { 0, 10, 15, 20 },
                       { 10, 0, 35, 25 },
                       { 15, 35, 0, 30 },
                       { 20, 25, 30, 0 } };
    int s = 0;
    cout<<"Cost of min path :"<<tsp(graph,s);
    return 0;
}