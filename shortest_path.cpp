#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define NODES 4

using namespace std;

vector <pair <int,int> > v[NODES];
bool vis[NODES];
int dist[NODES];
void dijkstra(){
	for(int i=0;i<NODES;i++)
		vis[i]=false;
	for(int i=1;i<NODES;i++)
		dist[i]=9999;

	dist[0]=0; //source vertex 0

	priority_queue< pair<int, int>,vector <pair <int,int> > ,greater <pair<int, int>> > q;
	q.push({0,0});

	while(!q.empty()){
		pair <int, int> p=q.top();
		q.pop();
		int weight=p.first;
		cout<<"weight: "<<weight<<" ";
		int v2=p.second;
		cout<<"v2: "<<v2<<"\n";
		if(vis[v2]) continue;
		vis[v2]=true;

		for(int i=0;i<v[v2].size();i++){
			int edge=v[v2][i].second;
			cout<<"edge: "<<edge<<"\n";
			int w=v[v2][i].first;
			cout<<"w: "<<w<<"\n";
			cout<<dist[v2]+w<<" sum\n";
			if(dist[v2]+w<dist[edge]){
				dist[edge]=dist[v2]+w;
				q.push({dist[edge],edge});
			}
		}
	}
	
}
int main(){
	int v1,v2,w;
	int cost=0;

	v[0].push_back(make_pair(1,1));
	v[0].push_back(make_pair(4,3));
	v[0].push_back(make_pair(3,2));

	v[1].push_back(make_pair(1,0));
	v[1].push_back(make_pair(2,2));

	v[2].push_back(make_pair(3,0));
	v[2].push_back(make_pair(2,1));
	v[2].push_back(make_pair(5,3));

	v[3].push_back(make_pair(5,2));
	v[3].push_back(make_pair(4,0));

int i=0;
	//for(int i = 0;i <4;i++){   
       // cout << "Adjacency list of node " << i << ": ";
        for(int j = 0;j < v[0].size();++j){
         //   cout<<"j: "<<j<<" adj[i].size()-1: "<<adj[i].size()-1<<endl;
            if(j == v[i].size() - 1)
                cout << v[i][j].second<< endl;
            else
                cout << v[i][j].second << " --> ";
        }
    //}
	dijkstra();

	for(auto i:dist){
		cout<<i<<" ";
	}
}