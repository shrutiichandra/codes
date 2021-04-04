/*
A semi marathon is going to be held in the beautiful city of Hyderabad. Hyderabad have many junctions and streets where all streets are unidirectional. In the semi marathon, people have to follow the direction of streets. People can walk the same street several times.

The marathon is due to start from the middle of any street. Pratyush wants to know how many such streets from where the marathon can commence such that the he can walk infinitely. 

Input Format

The first line contains an integer ,T the number of test cases.

The first line of each testcase contains two integers n and m, number of junctions and number of streets.

Junctions are denoted by integers in range [1, n].

Each of the next m lines describes a street,a b, a unidirectional street from junction a to junction b. A junction is not connected to itself. There may be several streets connecting the same pair of junctions. All the junctions in the city are not necessarily connected.

Constraints

1 <= T <= 20

1 <= n <= 140000

2 <= m <= 140000

Output Format

For each test case print the number of streets, such that if Pratyush start the marathon from the middle of any of them, he have the chance to walk as long as they like.

Output should be new line separated

Sample Input 0

1
7 7
7 2
7 5
7 2
2 4
4 2
6 7
4 6

Sample Output 0

6


*/
#include <iostream>
#include <vector>
#include <set>
#include <string.h>
using namespace std;

int findCycles(vector<int> adj_list[],int* vis,int* in_deg,int node,set<int>& edges){
    vis[node]=1;
   // cout<<"find cycle of "<<node<<endl;
    int this_node_edge=0;
    int explored=0;
    
    for(int i=0;i<adj_list[node].size();i++){
        //cout<<"inside for: "<<*i<<endl;
        if(!vis[adj_list[node][i]]){
        //    cout<<*i<<" was not visited"<<endl;
            vis[adj_list[node][i]]=1;
            int adj_edges=findCycles(adj_list,vis,in_deg,adj_list[node][i],edges);
            this_node_edge+=adj_edges;
            //cout<<*i<<" node edge: "<<this_node_edge;
        }
        else if(vis[adj_list[node][i]]==1&&!explored){
            //cout<<*i<<" was visited but not explored"<<endl;
            explored=1;
            this_node_edge+=in_deg[node];
            //cout<<"in_deg["<<node<<"]"<<in_deg[node]<<"\t";
            //cout<<"in cycle index: "<<node<<" "<<this_node_edge<<endl;
        }
        else if(vis[adj_list[node][i]]==2&&edges.find(adj_list[node][i])!=edges.end()&&!explored){
            //cout<<*i<<" visited is 2"<<endl;
           // cout<<*i<<"is in set and not explored"<<endl;
            explored=1;
            this_node_edge+=in_deg[node];
         //   cout<<"existing cycle, "<<*i<<" node edge- "<<this_node_edge<<endl;
        }
    }
    if(!explored&&this_node_edge){
        this_node_edge+=in_deg[node];
       // cout<<node<<" was not explored and node edge "<<this_node_edge<<endl;
    }
    if(this_node_edge){
     //   cout<<"inserting in set"<<node<<endl;
        edges.insert(node);
    }
    vis[node]=2;
   //  cout << "for index: " << node << " returning: " << this_node_edge << endl;
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
       // for (auto& v : adj_list) {
       //   v.clear();
       //  }
       // adj_list.clear();
        cout<<edges_count<<endl;
    }
}