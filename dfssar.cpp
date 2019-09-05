//sarvat's
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n,m,x;
int a[100][100];
int visited[100][100];
vector<int> path;
int c=0,f=0,cnt=0,d=0,flag=0,g=0;

void dfs(int i,int j){
    
    visited[i][j]=1;
    c++;
    if(i+1<m&&j<n&&visited[i+1][j]==-1&&a[i+1][j]==1){
        dfs(i+1,j);
    }
    if(i-1>=0&&j<n&&visited[i-1][j]==-1&&a[i-1][j]==1){
        dfs(i-1,j);
    }
    if(j+1<n&&i<m&&visited[i][j+1]==-1&&a[i][j+1]==1){
        dfs(i,j+1);
    }
    if(j-1>=0&&i<m&&visited[i][j-1]==-1&&a[i][j-1]==1){
        dfs(i,j-1);
    }

}
void df(){
    int k=0;
    for( k=0;k<m;k++){
        for(int j=0;j<n;j++){
            if(visited[k][j]==-1&&a[k][j]==1){
                dfs(k,j);
                path.push_back(c);
                c=0;
            }
        }
    }
}
void init(){
    int k; 
    for(k=0;k<m;k++){
        for(int j=0;j<n;j++){
            visited[k][j]=-1;
        }
    }
}
int main() {
    
    cin>>m;
    cin>>n;
    int k;
    for( k=0;k<m;k++){
        string t;
        cin>>t;
        for(int j=0;j<n;j++){
           a[k][j]=t[j]-'0';
           visited[k][j]=-1;
           if(a[k][j]==1)
                d++;
        }
    }  
    for( k=0;k<m;k++){
        if(d==(m*n)-1||d==m*n){
            cout<<m*n;
            flag=1;
            break;
        }
        for(int j=0;j<n;j++){
            if(a[k][j]==0){
                a[k][j]=1;
                c=0;
                init();
                df();
                a[k][j]=0;
                init();
            }
            else if(a[k][j]==1){
                c=0;
                init();
                df();
                init();
            }
        }
    }
    if(flag!=1){
        sort(path.begin(),path.end());
        int v=path.size();
        cout<<path[v-1];
     }
      
   return 0;      
}