#include <bits/stdc++.h>
using namespace std;
void color(vector<int> v[],vector<int>& visited,int i,int m,vector<int>& colour)
{
    cout << " called for "<<i;
    if(m<=0){
        cout<<" returning\n";
        return ;
    }
    visited[i]=1;
    colour[i]=m;
    cout<<" vis: "<<visited[i]<< " colour: "<<colour[i]<<"\n";
    for(auto a=v[i].begin();a!=v[i].end();a++)
    {    cout<<"  neighbour: "<<*a<<"\n";
        if(visited[*a]==0)
            color(v,visited,*a,m-1,colour);
    }
}
int main() {
    int t=1;
    // cin>>t;
    while(t>0)
    {
        int n=5;
        // cin>>n;
        int m=2;
        // cin>>m;
        int e=4;
        // cin>>e;
        vector<int> v[n+1];
        // for(int i=0;i<e;i++)
        // {
        //     int x,y;
        //     cin>>x>>y;
        //     v[x].push_back(y);
        //     v[y].push_back(x);
        // }
           v[1].push_back(2);
           v[2].push_back(1);

           v[2].push_back(3);
           v[3].push_back(2);

           v[3].push_back(4);
           v[4].push_back(3);

           v[1].push_back(5);
           v[5].push_back(1);

           for(auto i= 1; i<= n; i++){
            cout<<i<<": ";
                for(auto j= 0; j<v[i].size(); j++){
                    cout<<v[i][j]<<" ";
                }
                cout<<"\n";
           }
        cout << "starting"<<endl;
        vector<int> visited(n+1,0);
        vector<int> colour(n+1,INT_MIN);
        for(int i=1;i<=n;i++)
        {
            if(visited[i]==0)
            {
                cout <<"calling colour"<<endl;
                color(v,visited,i,m,colour);
            }

        }
        cout<<"exit for\n";
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            if(colour[i]==INT_MIN)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            cout << 0 <<endl;
        }
        else
            cout << 1 <<endl;
        t--;
    }
	return 0;
}