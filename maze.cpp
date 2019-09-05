#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;

int arr[100][100];
vector <string> s;
int soln[100][100];
ll n;
vector <string> res;

void DFS(ll x,ll y){
      
    if(x==n-1 && y==n-1){
        soln[x][y]=1;
        string word;
        for(int i=0;i<s.size();i++){
            word=word+s[i];
        }
        res.push_back(word);
        soln[x][y]=0;
        return;
    }
    if(arr[x-1][y] && x>0 && !soln[x-1][y]){
        soln[x][y]=1;
        s.push_back("U");
        DFS(x-1,y);
        s.pop_back();
        soln[x-1][y]=0;
    }
    if(arr[x][y+1] && y<n-1 && !soln[x][y+1]){
        soln[x][y]=1;
        s.push_back("R");
        DFS(x,y+1);
        s.pop_back();
        soln[x][y+1]=0;
    }
    if(arr[x+1][y] && x<n-1 && !soln[x+1][y]){
        soln[x][y]=1;
        s.push_back("D");
        DFS(x+1,y);
        s.pop_back();
        soln[x+1][y]=0;
    }
    if(arr[x][y-1] && y>0 && !soln[x][y-1]){
        soln[x][y]=1;
        s.push_back("L");
        DFS(x,y-1);
        s.pop_back();
        soln[x][y-1]=0;
    }   
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ll T;
    cin >> T;
    while(T--){
        bool flag;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
               soln[i][j]=0;
            }
        }
        cin >> n;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
               cin >> arr[i][j];
            }
        }
        DFS(0,0);
        sort(res.begin(),res.end());
        for(int i=0;i<res.size();i++)
        {
           cout << res[i] << " ";
        }
        cout << endl;
        res.clear();
    }
    return 0;
}