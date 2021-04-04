/*
n 18th Century there was a King. He had only one beautiful daughter Shivani. Today, 19th September is her birthday. King was very confused what to gift Shivani as her birthday present.He called for a meeting with his mantri's. One of the wise mantri suggested to gift her villages. King was very happy with this idea and decided to gift her some villages. Please help the king find the number of villages he has in his kingdom.

A group of connected 1s forms a village.

Input Format

First line will have the values of M,N. Space separated. Next M lines will consist of N values {0,1}

Constraints

1<=M,N<=1000

Output Format

Single integer denoting number of villages.

Sample Input 0

4 5
11110
11010
11000
00000

Sample Output 0

1

Explanation 0

All the 1's are connected.

Sample Input 1

4 5
11000
11000
00100
00011

Sample Output 1

3

Explanation 1

3 Groups of connected 1's are formed. -> 1 1 (Top left corner) 1 1

-> 1 (3rd row 3rd column)

-> 1 1 (Bottom Right)*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000][1000];
int vis[1000][1000]={0};
int cont=0;
void doDFS(int row,int col,int trow,int tcol){
    vis[row][col]=1;
    if(arr[row][col]==0) return;
    
    if(arr[row][col]==1){
        //cont++;
        if(row-1>=0&&!vis[row-1][col]) doDFS(row-1,col,trow,tcol);
        if(row+1<trow&&!vis[row+1][col]) doDFS(row+1,col,trow,tcol);
        if(col-1>=0&&!vis[row][col-1]) doDFS(row,col-1,trow,tcol);
        if(col+1<tcol&&!vis[row][col+1]) doDFS(row,col+1,trow,tcol);
    }
    
}
int main() {
    int m,n;
    cin>>m>>n;
    string element;
//    memset(vis,-1,sizeof(vis));
    for(int i=0;i<m;i++){
        cin>>element;    
        for(int j=0;j<element.length();j++){
            arr[i][j]=element[j]-'0';
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j]&&arr[i][j]==1){
                cont++;
                doDFS(i,j,m,n);
            }
        }
    }
    cout<<cont;
    return 0;
}
