#include<iostream>
using namespace std;
int tree[10];
void root_node(int root){
    if(tree[0]!=0){
        cout<<"Root is already entered.";
    }
    else{
        tree[0]=root;
    }
}

void left_node(int left,int parent){
    if(tree[parent]==0){
        cout<<"Parent does not exist.";
    }
    else{
        tree[(parent*2)+1] = left;
    }
}

void right_node(int right,int parent){
    if(tree[parent]==0){
        cout<<"Parent does not exist.";
    }
    else{
        tree[(parent*2)+2] = right;
    }
}

void display(){
    for(int i=0;i<10;i++){
        if(tree[i]==0){
            cout<<" - ";
        }
        else{
            cout<<tree[i]<<" ";
        }
    }
}

int main(){
    int left,root,right,parent;
    int ch;

    cout<<"1. root node\n2. left node\n3.right node\n4.traverse\n5.exit";
    do{
        cout<<"\nEnter choice :";
        cin>>ch;
        switch(ch){
        case 1: 
            cout<<"Enter root node :";
            cin>>root;
            root_node(root);
            break;
        case 2:
            cout<<"Enter parent index :";
            cin>>parent;
            cout<<"Enter left node :";
            cin>>left;
            left_node(left,parent);
            break;
        case 3:
            cout<<"Enter parent index :";
            cin>>parent;
            cout<<"Enter right node :";
            cin>>right;
            right_node(right,parent);
            break;
        case 4:
            display();
            break;
        case 5:
            cout<<"Exited.";
            break;
        default:
            cout<<"Invalid choice.";
            break;
        }
    }while(ch!=5);
    return 0;    
}