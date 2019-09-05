#include <iostream>
#include <vector>
#include <limits.h>
#include "common_utils.h"
using namespace std;
class Solution {
public:
    int recur(vector<vector<int>>& result,int i,int j,vector<vector<int>>& matrix)
    {
        cout<<"i "<<i<<" j "<<j<<"\n";
        if(i>matrix.size()-1 || j>matrix[i].size()-1)
            return 0;
        int up=INT_MAX,down=INT_MAX,left=INT_MAX,right=INT_MAX;
        if(matrix[i][j]==0)
            return 0;
        if(i!=0){
            cout<<"i,j: "<<i<<", "<<j<<" up\n";
            up=1+result[i-1][j];
        }
        if(j!=0){
            cout<<"i,j: "<<i<<", "<<j<<" left\n";
            left=1+result[i][j-1];
        }
        if(i!=matrix.size()-1)
        {   
            cout<<"i,j: "<<i<<", "<<j<<" down\n";
            if(matrix[i+1][j]==0){
                down=1;
            }
            else{
                down=1+recur(result,i+1,j,matrix);
            }
        }
        if(j!=matrix[i].size()-1)
        {    
            cout<<"i,j: "<<i<<", "<<j<<" right\n";
            if(matrix[i][j+1]==0){
                right=1;
            }
            else{
                right=1+recur(result,i,j+1,matrix);
            }
        }
        return min(up,min(left,min(down,right)));
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return matrix;
        vector<vector<int>> result(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                // if(matrix[i][j]==0)
                //      result[i][j]=0;
                // else
                // {
                     result[i][j]=recur(result,i,j,matrix);
                // }
            }
        }
        return result;
        
    }
};
int main(){
    vector <vector<int>> v{{0,0,0},{0,1,0},{1,1,1}};
    printVectorInVector(v);
    vector <vector<int>> m;
    Solution obj;
    m=obj.updateMatrix(v);
    cout<<"new Mat: ";
    printVectorInVector(m);

    return 0;
}