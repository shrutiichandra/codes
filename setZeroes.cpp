//g++ setZeroes.cpp -o setZeroes
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
void print(vector <vector <int> >& v ){
        for(auto i:v){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    cout<<"-----------------------\n";
}
void setzero(int r_idx, int c_idx, vector<vector<int>>& matrix,int m,int n){
    //for col
    cout<<"-----col-----\n";
    for(int c=0;c<m;c++){
        cout<<"("<<c<<", "<<c_idx<<") ";
        matrix[c][c_idx]=0;
    }
    //for row
    cout<<"\n----row----\n";
    for(int r=0;r<n;r++){
        cout<<"( "<<r_idx<<", "<<r<<" )";
        matrix[r_idx][r]=0;
    }
    cout<<"\n";
}
void setZeroes(vector<vector<int>>& matrix) {
    int rows=matrix.size();
    int cols=matrix[0].size();
    
    vector <int> :: iterator it;
    set < pair <int,int> > zeroes;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            // cout<<i<<", "<<j<<" ";
            it=find(matrix[i].begin(), matrix[i].end(),0);
            
            if(it!=matrix[i].end()){
                // cout<<"matrix "<<matrix[i][j]<<", ";
                int col_idx=distance(matrix[i].begin(),it);
                int row_idx=i;
                // cout<<"index "<<i<<","<<col_idx<<"\n";
                pair<int, int> coord;
                coord.first=row_idx;
                coord.second=col_idx;
                zeroes.insert(coord);
                matrix[row_idx][col_idx]=-1;
            }
            
        }
    }
    cout<<"\nin Pair: ";
    for(auto i=zeroes.begin();i!=zeroes.end();i++){
        cout<<"( "<<i->first<<", "<<i->second<<" ) ";
        setzero(i->first,i->second,matrix,rows,cols);

    }
    cout<<"\n";
    
}

int main(){

    vector <vector <int>> v{{1,1,1},{1,0,0},{1,1,1}};
    print(v);
    setZeroes(v);   
    print(v);


}