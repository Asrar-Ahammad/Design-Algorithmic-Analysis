#include<iostream>
#include<algorithm>

using namespace std;

typedef struct{
    int value;
    int weight;
    float density;
}item;

void input(item items[],int sizeofitems){
    cout<<"Enter total "<<sizeofitems<<"values\n";
    for(int i=0;i<sizeofitems;i++){
        cout<<"Enter"<<i+1<<"value :";
        cin>>items[i].value;
        cout<<"Enter "<<i+1<<" Weight :";
        cin>>items[i].weight;
    }
}

void display(item items[],int sizeofitems){
    cout<<"Item values :";
    for(int i=0;i<sizeofitems;i++){
        cout<<items[i].value<<" ";
    }
    cout<<"\nItem weights :";
    for(int i=0;i<sizeofitems;i++){
        cout<<items[i].weight<<" ";
    }
}

bool compare(item i1,item i2){
    return(i1.density>i2.density);
}

float knapsack(item items[],int sizeofitems,int W){
    float totalvalue = 0;
    float totalweight = 0;

    //calculate density for each value
    for(int i=0;i<sizeofitems;i++){
        items[i].density=items[i].value/items[i].weight;
    }

    //sort w.r.t to density using compare function
    sort(items, items+sizeofitems,compare);

    for(int i=0;i<sizeofitems;i++){
        if(totalweight+items[i].weight<=W){
            totalvalue += items[i].value;
            totalweight += items[i].weight; 
         }else{
            int wt = W-totalweight;
            totalvalue += (wt * items[i].density);
            totalweight += wt;
            break; 
        }
    }
    cout<<"Max value for the bag is :"<<totalweight;
    return totalvalue;
}



int main(){
    int W;
    item items[3];
    input(items,3);
    cout<<"The entered data is :\n";
    display(items,3);
    cout<<"\nEnter knapsack weight :";
    cin>>W;
    float maxval=knapsack(items,3,W);
    cout<<"\nThe maximum weight of knapsack is :"<<maxval;
    return 0;
}