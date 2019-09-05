//g++ -o dfslab dfsmyq4-lab9.cpp
//ques??
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int arr[100][100];
int visited[100][100]={0};
int ones=0;
int flag=0;
void doDFS(int row,int col,int trow,int tcol){
    if(visited[row][col]==1) return;
    
    visited[row][col]=1;
    
    if(arr[row][col]==0){ flag++; return;}
    
    ones++;
  
        if(row+1<trow&&col>=0&&col<tcol)// cout<<"1stif"<<endl;
            doDFS(row+1,col,trow,tcol); 
        if(row-1>=0&&col>=0&&col<tcol) //cout<<"2ndtif"<<endl;
            doDFS(row-1,col,trow,tcol);
        if(col+1<tcol&&row>=0&&row<trow)//cout<<"3rdif"<<endl
            doDFS(row,col+1,trow,tcol);
        if(col-1>=0&&row>=0&&row<trow) //cout<<"4thif"<<endl;
        doDFS(row,col-1,trow,tcol);
  
}

int main() {
    int m;
    int n;
    
    cin>>m>>n;
    
    string in;
  
    for(int i=0;i<m;i++){
        cin>>in;
      
        for(int j=0;j<n;j++){
            string sub=in.substr(j,1);
            arr[i][j]=sub[0]-'0';
            
        }
    }
    int max=-1;
      for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            if(arr[i][j==0]){
              arr[i][j]=1;
              ones=0;
              doDFS(i,j,m,n);
              arr[i][j]=0;
              if(ones>max) max=ones;
            }
            if(!visited[i][j]&&arr[i][j]==1){
              doDFS(i,j,m,n);
              if(ones>max) max=ones;
            }
          }
      }
    
    
    
  cout<<max<<endl;
    
    return 0;
}
