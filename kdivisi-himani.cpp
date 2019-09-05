//himani's
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h> 
#include<chrono>
using namespace std;
using namespace std::chrono;
int matrix[100][10000]={0};
int check(int arr[10000],int n,int k){
    for(int i=1;i<n;i++){
        for(int j=0;j<k;j++){
            if(matrix[j][i-1]==1){
                int x=(j+arr[i])%k;
                 matrix[x][i]=1;
                x=(arr[i]-j)%k;
                if(x<0)x=x+k;
                matrix[x][i]=1;
            }
        }
    }
    if(matrix[0][n-1]==1)return 1;
    return 0;
}
int main() {
    auto start=high_resolution_clock::now();
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    for(int p=0;p<t;p++){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int k=0;k<n;k++)cin>>arr[k];
    matrix[arr[0]%k][0]=1;
    if(check(arr,n,k))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    memset(matrix,0,sizeof(matrix));
    }
    
    return 0;
}