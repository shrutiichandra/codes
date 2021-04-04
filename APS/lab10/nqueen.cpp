/*The n-queens puzzle is the problem of placing n queens 
on an n×n chessboard such that no two queens attack each other. 
Given an integer n, print all distinct solutions to the
 n-queens puzzle. Each solution contains distinct board 
 configurations of the n-queens’ placement, where the 
 solutions are a permutation of [1,2,3..n] in increasing order,
 here the number in the ith place denotes that the ith-column
  queen is placed in the row with that number.

  Input Format

The first line of input contains an integer T denoting the no of 
test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the chessboard.

Constraints

    1<=T<=10
    1<=n<=15

Output Format

For each test case, output your solutions on one line where each solution is enclosed in square brackets '[', ']' 
separated by a space . The solutions are permutations of {1, 2, 3 …, n} in increasing order where the number in the ith place denotes the ith-column queen is placed in the row with that number, if no solution exists print -1. In case of multiple outputs keep them lexicographic.

Sample Input 0

2
1
4

Sample Output 0

[1 ]
[2 4 1 3 ] [3 1 4 2 ]


*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
set <string> all_safe;
int matrix[15][15];
int isSafe(int row,int curr_col,int s){
    for(int i=0;i<curr_col;i++)
        if(matrix[row][i]) return 0;
    for(int i=row,j=curr_col;i<s&&j>=0;i++,j--)
        if(matrix[i][j]) return 0;
    for(int i=row,j=curr_col;i>=0&&j>=0;i--,j--)
        if(matrix[i][j]) return 0;
    
    return 1;
}
int nqueens(int n,int curr_col){
    string safe_sol="";
    if(curr_col==n){
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(matrix[i][j]==1){
                   safe_sol.append(to_string(j+1)+" ");
               }
           }
       }
       
       all_safe.insert(safe_sol);
       
       return 0;
   }
    for(int row=0;row<n;row++){
        if(isSafe(row,curr_col,n)){
            matrix[row][curr_col]=1;
            nqueens(n,curr_col+1);
            matrix[row][curr_col]=0;
        }
    }
   return -1;
}

int main() {
    int testcase;
    cin>>testcase;
    int size;
   
    while(testcase--){
        cin>>size;
        nqueens(size,0);
       
        for(auto i:all_safe){
             cout<<"[";
           cout<<i<<"] ";
        }
       
        
        cout<<endl;
        all_safe.clear();
    }
    return 0;
}