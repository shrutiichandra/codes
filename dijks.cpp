//g++ -std=c++11 -o dijks dijks.cpp
//not running
#include <iostream>
#include <set>
#include <vector>
#define SIZE 1000
using namespace std;


vector < pair<int,int> >  vertex[SIZE];
//first-neighbours,second-weight
int dist[SIZE];
int visited[SIZE];

void dijkstra(){
	cout<<"\n---DIJKSTRA---\n";
	dist[1]=0; //source-1

	multiset <pair <int,int> > min_pri;

	min_pri.insert({0,1}); //source node dist 0

	while(!min_pri.empty()){
		pair <int,int> p=*min_pri.begin();

		min_pri.erase(min_pri.begin());

		int source=p.second;
		int weight=p.first;

		if(visited[source]) continue;

		visited[source]=1;

		for(int i=0;i<vertex[source].size();i++){
			int edge=vertex[source][i].first;
		int w_edge=vertex[source][i].second;

			if(dist[source]+w_edge<dist[edge]){
				dist[edge]=dist[source]+w_edge;
				min_pri.insert(make_pair(dist[edge],edge));
			}
		}

		
	}

	for(auto i:min_pri){
		cout<<i.first<<" "<<i.second<<endl;
	}	

}
void print(int n){

	for(int i =1;i<=n;i++){   
        cout << i << ": ";
        for(int j = 0;j < vertex[i].size();++j){
         //   cout<<"j: "<<j<<" adj[i].size()-1: "<<adj[i].size()-1<<endl;
            if(j == vertex[i].size() - 1)
                cout << vertex[i][j].first << endl;
            else
                cout <<  vertex[i][j].first<< "-->";
        }
     }
}
int main(){
	int  n,m;
	cout<<"enter num of vertices and edges: ";
	cin>>n>>m;
	int a,b,w;
	cout<<"\nenter "<<m<<" edges and weights: \n";
	cout<<"[vertices start from 1]\n";
	for(int i=0;i<m;i++){
		cin>>a>>b>>w;

		vertex[a].push_back(make_pair(b,w));

	}
	print(n);

	dijkstra();
}
