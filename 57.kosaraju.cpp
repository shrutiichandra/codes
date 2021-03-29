// https://www.geeksforgeeks.org/strongly-connected-components/
//g++ -o kosa kosaraju.cpp 
#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

vector <int> adj_list[10];
vector <int> adj_list_rev[10];
int visited[10]={0};
int vis_rev[10]={0};
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
void reverseGraph(int n){
	int s;
	for(int i=0;i<n;i++){
		for(int j=0;j!=adj_list[i].size();j++){
			s=adj_list[i][j];
			adj_list_rev[s].push_back(i);
		}
	}
}
void doDfs2(int source){
	vis_rev[source]=1;

	for(int i=0;i!=adj_list_rev[source].size();i++){
		if(vis_rev[adj_list_rev[source][i]]==0)
			doDfs2(adj_list_rev[source][i]);
		//vertices.push(adj_list_rev[source][i]);
	}

}
int doRevDfs(){
	int top;
	int count=0;
	while(!vertices.empty()){
		top=vertices.top();
		vertices.pop();
		if(vis_rev[top]==1)
			continue;
		else{
			doDfs2(top);
			count=count+1;
		}
	}
	return count;

}
int main(){
	int num=5;
	adj_list[1].push_back(0);
	adj_list[0].push_back(2);
	adj_list[2].push_back(1);
	adj_list[0].push_back(3);
	adj_list[3].push_back(4);

	//1. do dfs on this graph
	doDfs(0);
	
	reverseGraph(5);
//	memset(visited,0,sizeof(visited));
	int ans=doRevDfs();

	cout<<"connected comp: "<<ans<<endl;
	return 0;
}