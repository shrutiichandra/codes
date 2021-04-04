//print all paths between two nodes s and t
//modify dfs
#include <iostream>
#include <vector>
#include <algorithm>
#define NODES 4

using namespace std;
vector <int> adj_list[NODES];

void modifiedDfs(int src, int dest,bool* vis,int* path,int path_index);
void printAllPaths(int s,int t);
void print(int nodes);
int main(){

	// adj_list[0].push_back(1);
	// adj_list[0].push_back(2);
	// adj_list[0].push_back(3);
	// adj_list[2].push_back(0);
	// adj_list[2].push_back(1);
	// adj_list[1].push_back(3);
	// adj_list[2].push_back(3);
	// adj_list[3].push_back(2);
	// adj_list[1].push_back(2);
	// adj_list[2].push_back(1);
	// adj_list[1].push_back(3);
	// adj_list[3].push_back(1);

	adj_list[1].push_back(2);
	adj_list[2].push_back(1);
	adj_list[3].push_back(2);
	adj_list[2].push_back(3);

	cout<<"graph: \n";
	print(NODES);
	cout<<"----\n";
	printAllPaths(1,4);
	cout<<"----\n";	
}

void printAllPaths(int s,int t){
	bool* vis=new bool[NODES];
	int* path=new int[NODES];
	int path_index=0; //path is empty

	for(int i=0;i<NODES;i++)
		vis[i]=false;
	modifiedDfs(s,t,vis,path,path_index);
}

void modifiedDfs(int src, int dest,bool* vis,int* path,int path_index){
	cout<<"-------\n";
	cout<<"DFS "<<src<<"\n";
	vis[src]=true;

	path[path_index]=src;
	path_index++;
	cout<<"inc path index: "<<path_index<<"\n ";

	if(src==dest){
		//print current path array
		for(int i=0;i<path_index;i++)
			cout<<path[i]<<" ";
		cout<<"\n";
	}
	else{
		for(int i=0;i<adj_list[src].size();i++){
			int u=adj_list[src][i];

			if(vis[u]==false){
				
				modifiedDfs(u,dest,vis,path,path_index);
			}
		}
	}
	path_index--;
	cout<<"dfs "<<src<<" | "<<"dec path index: "<<path_index<<"\n ";

	vis[src]=false;
}

void print(int nodes){
	   for(int i = 1;i <nodes;i++){   
        cout << "Adjacency list of node " << i << ": ";
        for(int j = 0;j < adj_list[i].size();++j){
         //   cout<<"j: "<<j<<" adj[i].size()-1: "<<adj[i].size()-1<<endl;
            if(j == adj_list[i].size() - 1)
                cout << adj_list[i][j] << endl;
            else
                cout << adj_list[i][j] << " --> ";
        }
    }
}