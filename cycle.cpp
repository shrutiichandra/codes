//g++ -std=c++11 -o cyc cycle.cpp
#include <iostream>
#include <vector>
using namespace std;
#define NOT_EXPL -1
#define BEING_EXPL 0
#define FULLY_EXPL 1
vector <int> adj_list[14000];
int doDFS(int node,int* state){
    cout<<"inside do dfs node: "<<node<<endl;
    state[node]=BEING_EXPL;
    for(auto i=adj_list[node].begin();i!=adj_list[node].end();i++){
        
        int neighbour=*i;
        cout<<"neighbour: "<<adj_list[node][neighbour]<<" ";
        if(state[neighbour]==BEING_EXPL){ 
            cout<<"state of neighbour: "<<state[neighbour]<<" return 1"<<endl;
            return 1;
        }
        if(state[neighbour]==NOT_EXPL&&doDFS(neighbour,state)){
             cout<<"state of neighbour: "<<state[neighbour]<<" return 1"<<endl;
            return 1;
        }
    }
    state[node]=FULLY_EXPL;
     cout<<" return 0"<<endl;
    return 0;
}
int cycleCheck(int v){
    
    int state[v];
    for(int i=1;i<=v;i++){
        state[i]=NOT_EXPL;
    }

    for(int i=1;i<=v;i++){
        cout<<"cycle check: state of "<<i<<": "<<state[i]<<" ";
        if(state[i]==NOT_EXPL){
           cout<<"inside if "<<endl;
            if(doDFS(i,state)){
                cout<<"do dfs on i: "<<i<<" is true. "<<endl;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    cout<<"CYCLE DETECTION DIRECTED GRAPH\n";
    int testcase;
    int njunc;
    int mstreets;
    cout<<"enter number of testcases: ";
    cin>>testcase;
    while(testcase--){
        cout<<"\nenter number of junctions and streets: ";
        cin>>njunc>>mstreets;
        int a,b;
        cout<<"\nEnter "<<mstreets<<" edges: \n";
        cout<<"[first vertex begins from 1]\n";
        for(int i=0;i<mstreets;i++){
            cin>>a>>b;
            adj_list[a].push_back(b);
        }
        cout<<"\n Graph is: \n";
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

        cout<<"\nCYCLE CHECK---\n";
           a=cycleCheck(njunc);
      /* for(int i=1;i<=njunc;i++){
             if(a)
               cycle[i]=1;
            
        }

        int sum=0;

        for(int i=1;i<=njunc;i++)
            sum+=cycle[i];

        cout<<sum<<endl;*/
            if(a) cout<<"YES"<<endl;
            else cout<<"NO\n";
       
    }
    return 0;
}