//g++ -o kdivi kdivi.cpp
/**
You are given an array of integers. You can place either '+' or '-' between two elements thus resulting in a mathematical expression. Your task is to check wheather there exist any expression such that resultant value is divisible by an integer K

Input Format

First line contains T number of test cases.

In each test case , first line contains two integers N (length of array) and K

Second line of each test case contains N space separated integers.

Constraints

1 <= T <= 10

1<= N <= 10000

1<= K <= 100

1<= value_of_array_elements <= 500

Output Format

For each testcase print "YES" if there exist any expression such that its resultant value is divisible by K otherwise print "NO".

Print answer on newline for each testcase.

Sample Input 0

4
4 5
7 2 8 4
5 10
9 7 3 5 5
1 10
10
2 3
1 1

Sample Output 0

YES
NO
YES
YES


*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


void check(int* a,int len,int n){
   int dp[100][10000]={0};
      dp[a[0]%n][0]=1;
    int sum,diff;
    for(int col=1;col<len;col++){
        for(int row=0;row<n;row++){
            if(dp[row][col-1]){
                sum=(a[col]+row)%n;
                dp[sum][col]=1;
                diff=(a[col]-row)%n;
                if(diff<0) diff+=n;
                dp[diff][col]=1;
            }
        }
    }
    
    if(dp[0][len-1]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main() {
    int testcase;
    cin>>testcase;
    int arr_num;
    int arr[10000];
    int k;
    while(testcase--){
        cin>>arr_num;
        cin>>k;
        for(int i=0;i<arr_num;i++)
            cin>>arr[i];
       
       check(arr,arr_num,k);
        
        
    }

    //cout<<log2(5)<<endl;
    return 0;
}