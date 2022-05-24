#include<iostream>
#include<time.h>
#include<stdlib.h>


using namespace std;

void binary(int n,int m,int arr[]){
	int high,low,count=0;
	high = m;
	low = 0;
	while(low<=high){
		int mid = (low+high)/2;
		if(n>arr[mid]){
			low = mid+1;
		}
		if(n<arr[mid]){
			high = mid-1;
		}
		if(n==arr[mid]){
			cout<<"\nThe element is at index :"<<mid;
			count++;
			break;
		}
	}
	if(count==0){
		cout<<"The element is not found.";
	}
}
int main(){
	int arr[1000],m;
	int n,temp=0;
	cout<<"Enter the size of array :";
	cin>>m;
	for(int i=0;i<m;i++){
		arr[i]=rand();
	}
	for(int i=0;i<m;i++){
		for(int j=i+1;j<m;j++){
			if(arr[i]>arr[j]){
				temp = arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	cout<<"\n The elements in array ";
	for(int i=0;i<m;i++){
		cout<<arr[i]<<", ";
	}
	cout<<"\nEnter a element to find in array :";
	cin>>n;
	clock_t t;
	t=clock();
	binary(n,m,arr);
	t=clock()-t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	cout<<"\nThe time taken for the program :"<<time_taken<<"s";
	return 0;
}