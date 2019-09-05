//g++ -std=c++11 -o dfscycle dfscycle.cpp
//incomplete
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define NOT_EXPL -1
#define BEING_EXPL 0
#define FULLY_EXPL 1
vector <int> adj_list[14000];
int visited[14000];
int doDFS(int node){

    visited[node]=1;
  cout<<"inside do dfs node: "<<node<<endl;
    for(auto i=adj_list[node].begin();i!=adj_list[node].end();i++){
     //   cout<<"neighbour: "<<adj_list[node][neighbour]<<" ";
        if(!visited[*i]){ 
            doDFS(*i);
          //  cout<<"not vis neighbour: "<<visited[neighbour]<<" return 1"<<endl;
         
        }
    }
     //cout<<" return 0"<<endl;
    //return 0;
}
void cycleCheck(int s,int v){
    doDFS(s);
}

int inDegree(int v){
    int in_degrees[v+1]={0};
    for(int i = 1;i <=v;i++){   
            for(auto j = adj_list[i].begin();j != adj_list[i].end();++j){
                cout<<*j<<" ";
                in_degrees[*j]++;
            }
            cout<<endl;
        }
        cout<<endl;
        for(int i=1;i<=v;i++)

            cout<<in_degrees[i]<<" ";

        return 0;
}
int edgeCount(int v){
    int edge_cnt[v+1]={0};
    for(int i = 1;i <=v;i++){   
        for(auto j = adj_list[i].begin();j != adj_list[i].end();++j){
            if()
        }
    }
}

int main(){
    int testcase=1;
    int njunc=4;
    int mstreets=6;

    //cin>>testcase;
    while(testcase--){
       // cin>>njunc>>mstreets;
        int a,b;
        /*for(int i=0;i<mstreets;i++){
            cin>>a>>b;*/
            adj_list[1].push_back(2);
            adj_list[1].push_back(3);
            adj_list[2].push_back(3);
            adj_list[3].push_back(1);
            adj_list[3].push_back(4);
            adj_list[4].push_back(4);
      //  }
        for(int i = 1;i <=njunc;i++){   
            cout << "Adjacency list of node " << i << ": ";
            for(int j = 0;j < adj_list[i].size();++j){
        
                if(j == adj_list[i].size() - 1)
                    cout << adj_list[i][j];
                else
                    cout << adj_list[i][j] << " --> ";
                
            }
            cout<<endl;
        }
        int cycle[njunc]={0};
    }
        cycleCheck(3,njunc);
        inDegree(njunc);
    return 0;
}