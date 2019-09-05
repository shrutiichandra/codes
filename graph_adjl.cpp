//g++ -o graph_adjl graph_adjl.cpp 
//DIRECTED GRAPH
#include <iostream>
#include <vector>

using namespace std;

vector <int> adj[10];

int main(){
    int x, y, nodes, edges;
    cout<<"Enter num of nodes and edges: ";
    cin >> nodes;       //Number of nodes
    cin >> edges;       //Number of edges
    cout<<"\nEnter "<<edges<<" edges: \n";
    for(int i = 0;i < edges;i++){
        cin >> x >> y;
        adj[x].push_back(y);        //Insert y in adjacency list of x
    }
    
    for(int i = 0;i <nodes;i++){   
        cout << "Adjacency list of node " << i << ": ";
        for(int j = 0;j < adj[i].size();++j){
         //   cout<<"j: "<<j<<" adj[i].size()-1: "<<adj[i].size()-1<<endl;
            if(j == adj[i].size() - 1)
                cout << adj[i][j] << endl;
            else
                cout << adj[i][j] << " --> ";
        }
    }
    return 0;
}