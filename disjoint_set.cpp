//g++ -o dset disjoint_set.cpp 
//with and without path compression (_pc)
#include <iostream>

using namespace std;

int* initialize(int num){
	int* parent=new int[num];
	for(int i=0;i<num;i++)
		parent[i]=i;
	return parent;
}
void print(int* a,int num){

	for(int i=0;i<num;i++)
		cout<<a[i]<<" ";
	cout<<"\n";

}
int root(int a,int* arr){
	while(arr[a]!=a){
		a=arr[a];
	}
	return a;
}
int root_pc(int a,int* arr){
	while(arr[a]!=a){
		arr[a]=arr[arr[a]];
		a=arr[a];
	}
	return a;
}
void union1(int a,int b,int* parent){
	int roota=root(a,parent);
	int rootb=root(b,parent);
	parent[roota]=parent[rootb];
}
void union2(int a,int b,int* parent){
	int roota=root_pc(a,parent);
	int rootb=root_pc(b,parent);
	parent[roota]=parent[rootb];
}
int find2(int a,int* arr){
	return root_pc(a,arr);
}
int find1(int a,int* arr){
	return root(a,arr);
}

int main(){
	int arr[]={0,1,2,3,5};
	int n=sizeof(arr)/sizeof(arr[0]);

	int* parent;
	parent=initialize(n);
	// cout<<"initially, parent:\n";
	// print(parent,n);
	// cout<<"union 1,4\n";
	// union1(0,1,parent);
	// print(parent,n);
	// cout<<"union 0,2\n";
	// union1(0,2,parent);
	// print(parent,n);
	// cout<<"union 3,4\n";
	// union1(3,4,parent);
	// print(parent,n);
	// cout<<"union 0,4\n";
	// union1(0,4,parent);
	// print(parent,n);
	// cout<<"find 0:"<<find1(0,parent)<<"\n";


	cout<<"initially, parent:\n";
	print(parent,n);
	cout<<"union 0,1\n";
	union2(0,1,parent);
	print(parent,n);
	cout<<"union 0,2\n";
	union2(0,2,parent);
	print(parent,n);
	cout<<"union 3,4\n";
	union2(3,4,parent);
	print(parent,n);
	cout<<"union 0,4\n";
	union2(0,4,parent);
	print(parent,n);

	cout<<"find 0:"<<find2(0,parent)<<"\n";
}