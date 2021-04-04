//g++ -o hamil hamil.cpp
//undirected graph
#include <iostream>
#define NOT_IN_STACK 0
#define IN_STACK 1
#define COLS 10
using namespace std;

bool dfs(int s,bool adj[][COLS],int label[],int count,int n){
	if(count==n) 
		return 1;

	for(int i=0;i<n;i++){
		if(adj[s][i]&&label[i]==NOT_IN_STACK){
			label[i]=IN_STACK;
			if(dfs(i,adj,label,count+1,n))
				return 1;
			label[i]=NOT_IN_STACK;
		}
	}
	return false;
}

bool check(bool adj[][COLS],int n){
	int label[COLS]={0};

	for(int i=0;i<n;i++){
		label[i]=IN_STACK;
		if(dfs(i,adj,label,1,n))
			return 1;
		label[i]=NOT_IN_STACK;
	}
	return 0;
}

int main(){
	int nverti;
	int medge;
	cout<<"Enter number of vertices and edges: ";
	cin>>nverti>>medge;
	bool adj[10][10];
	for(int i=0;i<nverti;i++)
		for(int j=0;j<nverti;j++)
			adj[i][j]=0;
	
	int start,fin;
	cout<<"\nEnter "<<medge<<" edges: ";
	for(int i=0;i<medge;i++){
		cin>>start>>fin;
		adj[start][fin]=1;
		adj[fin][start]=1;
	}
	cout<<"\nHamiltonian Cycle: ";
	if(check(adj,nverti))
		cout<<"YES";
	else cout<<"NO";
	cout<<"\n";
}