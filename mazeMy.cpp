//g++ -o mazeMy mazeMy.cpp 
//doubt,ques??
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int matrix[10][10];
int vis[10][10];
vector <string> path;
vector <string> all_paths;
/*void doDFS(int row,int col,int n){
  //   cout<<"at row "<<row<<" col "<<col<<" val "<<matrix[row][col]<<" "<<endl;
    if(matrix[row][col]==0) return;
   
    if(vis[row][col]==1) return;
    
    vis[row][col]=1;
    
    int step=0;
    
    if(row+1<n&&col>=0&&col<n&&!step&&!vis[row+1][col]&&matrix[row+1][col]){
     //    cout<<"in D if"<<" ";
         cout<<"D";
        step=1;
        doDFS(row+1,col,n); 
        vis[row+1][col]=0;
    }
     if(col+1<n&&row>=0&&row<n&&!step&&!vis[row][col+1]&&matrix[row][col+1]){
       //   cout<<"in R if ";
        cout<<"R";
        step=1;
       doDFS(row,col+1,n);
         vis[row][col+1]=0;
    }
    if(row-1>=0&&col>=0&&col<n&&!step&&!vis[row-1][col]&&matrix[row-1][col]){ 
       //   cout<<"at row "<<row-1<<" col "<<col<<" val "<<matrix[row-1][col]<<" ";
       cout<<"U";
        step=1;
       doDFS(row-1,col,n);
        vis[row-1][col]=0;
    }
   
    if(col-1>=0&&row>=0&&row<n&&!step&&!vis[row][col-1]&&matrix[row][col-1]){ 
       //   cout<<"at row "<<row<<" col "<<col-1<<" val "<<matrix[row][col-1]<<" ";
        cout<<"L";
        step=1;
      doDFS(row,col-1,n);
        vis[row][col-1]=0;
    }
   // vis[row][col]=0;
  
}*/
void doDFS(int row,int col,int n){
    
 
  //   cout<<"at row "<<row<<" col "<<col<<" val "<<matrix[row][col]<<" "<<endl;
    if(row==n-1&&col==n-1){
        vis[row][col]=1;
        //make a string
        string full_path;
        for(int i=0;i<path.size();i++)
            full_path+=path[i];
        all_paths.push_back(full_path);
        //append some other string
        //pushback into one vector
        vis[row][col]=0;
        return;
    }
   
    
    if(row+1<n&&col>=0&&col<n&&!vis[row+1][col]&&matrix[row+1][col]){
     //    cout<<"in D if"<<" ";
    
      vis[row+1][col]=1;
        path.push_back("D");
        doDFS(row+1,col,n); 
        path.pop_back();
        vis[row+1][col]=0;
    }
     if(col+1<n&&row>=0&&row<n&&!vis[row][col+1]&&matrix[row][col+1]){
       //   cout<<"in R if ";
     
        vis[row][col+1]=1;
          path.push_back("R");
       doDFS(row,col+1,n);
          path.pop_back();
         vis[row][col+1]=0;
    }
    if(row-1>=0&&col>=0&&col<n&&!vis[row-1][col]&&matrix[row-1][col]){ 
       //   cout<<"at row "<<row-1<<" col "<<col<<" val "<<matrix[row-1][col]<<" ";
     
     vis[row-1][col]=1;
         path.push_back("U");
       doDFS(row-1,col,n);
         path.pop_back();
        vis[row-1][col]=0;
    }
   
    if(col-1>=0&&row>=0&&row<n&&!vis[row][col-1]&&matrix[row][col-1]){ 
       //   cout<<"at row "<<row<<" col "<<col-1<<" val "<<matrix[row][col-1]<<" ";
     
     vis[row][col-1]=1;
         path.push_back("L");
      doDFS(row,col-1,n);
         path.pop_back();
        vis[row][col-1]=0;
    }
   // vis[row][col]=0;
  
}


int main() {
    int testcase;
    int n_size;
    cin>>testcase;
    int num;
    while(testcase--){
    
       
        cin>>n_size;
        
         for(int i=0;i<n_size;i++)
            for(int j=0;j<n_size;j++)
               vis[i][j]=0;
        
        for(int i=0;i<n_size;i++){
            for(int j=0;j<n_size;j++){
                cin>>num;
               matrix[i][j]=num;
            }
        }
        
        
                   doDFS(0,0,n_size);
             
           
       for(int i=0;i<all_paths.size();i++)
           cout<<all_paths[i]<<" ";
        cout<<endl;
        all_paths.clear();
    }
    
    return 0;
}
