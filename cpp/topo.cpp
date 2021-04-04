#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

vector <int> adj_list[10];
int visited[10]={0};
stack <int> vertices;
void doDfs(int source){
	visited[source]=1;

	for(int i=0;i!=adj_list[source].size();i++){
	
		if(visited[adj_list[source][i]]==0){
			doDfs(adj_list[source][i]);

		}

	}
	vertices.push(source);

}
int main(){
	int num=5;
	adj_list[0].push_back(1);
	adj_list[0].push_back(2);
	adj_list[2].push_back(3);
	adj_list[3].push_back(4);
	adj_list[4].push_back(5);
	adj_list[1].push_back(4);

	//1. do dfs on this graph
	doDfs(0);
	//2. print stack from top
	cout<<"Topological Sort: "<<endl;
	while(!vertices.empty()){
		cout<<vertices.top()<<" ";
		vertices.pop();
	}

	return 0;
}