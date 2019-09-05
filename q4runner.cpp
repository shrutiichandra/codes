#include <iostream>
#include <vector>
#include <set>
#include <string.h>
using namespace std;

int findCycles(vector<int> adj_list[],int* vis,int* in_deg,int node,set<int>& edges){
    vis[node]=1;
  cout<<"FIND CYCLE of "<<node<<" in_degree "<<in_deg[node]<<" ";
    int this_node_edge=0;
    int explored=0;
    cout<<" explored: "<<explored<<endl;
    cout<<"Traversing neighbours: "<<endl;
    for(int i=0;i<adj_list[node].size();i++){
        cout<<"Inside for: explored: "<<explored;
        cout<<" "<<i<<"th neighbour is "<<adj_list[node][i];
        cout<<" visited: "<<vis[adj_list[node][i]]<<endl;
        if(!vis[adj_list[node][i]]){
            cout<<"CASE 1: ";
           //cout<<adj_list[node][i]<<" was not visited"<<endl;
            vis[adj_list[node][i]]=1;
            cout<<adj_list[node][i]<<" make it visited"<<endl;
            int adj_edges=findCycles(adj_list,vis,in_deg,adj_list[node][i],edges);
            this_node_edge+=adj_edges;
            cout<<"in "<<node<<" neighbour "<<adj_list[node][i]<<" adding dfs res.sum: "<<this_node_edge<<endl;
        }
        else if(vis[adj_list[node][i]]==1&&!explored){
            cout<<"CASE 2: ";
          //  cout<<adj_list[node][i]<<" was visited but not explored"<<endl;
            cout<<"false explored. ";
            explored=1;
            cout<<"make explored true ";
            cout<<this_node_edge<<" + "<<in_deg[node]<<endl;
            this_node_edge+=in_deg[node];
            cout<<"in "<<node<<" neighbour "<<adj_list[node][i]<<". sum: "<<this_node_edge<<endl;
        }
        else if(vis[adj_list[node][i]]==2&&edges.find(adj_list[node][i])!=edges.end()&&!explored){
        //   cout<<adj_list[node][i]<<" was fully visited but not explored"<<endl;
            cout<<"CASE 3: ";
              cout<<"false explored"<<" ";
            explored=1;
          cout<<"make explored true ";
            cout<<this_node_edge<<" + "<<in_deg[node]<<endl;
            this_node_edge+=in_deg[node];
            cout<<"in "<<node<<" neighbour "<<adj_list[node][i]<<". sum: "<<this_node_edge<<endl;
        }
    }
    if(!explored&&this_node_edge){
        cout<<"false explored"<<endl;
        this_node_edge+=in_deg[node];
    }
    if(this_node_edge){
       cout<<"inserting in set: "<<node<<endl;
        edges.insert(node);
    }
    vis[node]=2;
    cout<<"Fully visited: "<<node<<endl;
   cout << "for node: " << node << " returning: " << this_node_edge << endl;
    return this_node_edge;
}
int main(){
    int testcase;
    cin>>testcase;
    while(testcase--){
        int njunc,mstreets;
        cin>>njunc>>mstreets;
        vector <int> adj_list[njunc+1];
        int vis[njunc+1]={0};
        int in_deg[njunc+1]={0};
        set <int> edges;
        
        for(int i=0;i<mstreets;i++){
            int source,dest;
            cin>>source>>dest;
            adj_list[source].push_back(dest);
            in_deg[dest]++;
        }
        
        int edges_count=0;
        for(int i=1;i<=njunc;i++){
     //        cout << "visiting" << endl;
            if(!vis[i]){
                edges_count+=findCycles(adj_list,vis,in_deg,i,edges);
            }
        }
        cout<<edges_count<<endl;
    }
}