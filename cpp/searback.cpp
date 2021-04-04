#include <iostream>
#include <vector>
using namespace std;
#define NOT_EXPL -1
#define BEING_EXPL 0
#define FULLY_EXPL 1
vector <int> adj_list[14000];
int visited[14000];
int doDFS(int node){
    cout<<"inside do dfs node: "<<node<<endl;
    visited[node]=1;
    for(int i=0;i<adj_list[node].size();i++){
        
        int neighbour=i;
        cout<<"neighbour: "<<adj_list[node][neighbour]<<" ";
        if(!visited[neighbour]&&doDFS(neighbour)){ 
            cout<<"not vis neighbour: "<<visited[neighbour]<<" return 1"<<endl;
            return 1;
        }
    }
     cout<<" return 0"<<endl;
    return 0;
}
int cycleCheck(int v){
    
   
    for(int i=1;i<=v;i++){
        cout<<"visited of "<<i<<": "<<visited[i]<<" ";
        if(!visited[i]){
           cout<<"inside if "<<endl;
            if(doDFS(i)){
                cout<<"do dfs on i: "<<i<<" is true. "<<endl;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    int testcase;
    int njunc;
    int mstreets;

    cin>>testcase;
    while(testcase--){
        cin>>njunc>>mstreets;
        int a,b;
        for(int i=0;i<mstreets;i++){
            cin>>a>>b;
            adj_list[a].push_back(b);
        }
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

        if(cycleCheck(njunc))
           cout<<"yrs"<<endl;
               //cycle[i]=1;
            
        //}

        int sum=0;

        for(int i=1;i<=njunc;i++)
            cout<<cycle[i]<<" ";

        cout<<sum<<endl;
       
    }
    return 0;
}