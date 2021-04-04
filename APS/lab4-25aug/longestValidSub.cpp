/*
Your task is simple . Given a string of opening '(' and closing ')' paranthesis . Find the lenght of largest valid substring.

Input Format

First line contains T (1 <= T <= 10) , number of testcases.

Each of next T lines contains string of paranthesis .

Constraints

1 <= T <= 10

1<= Length of String <= 100000

Output Format

Single line corresponding to each testcase representing length of largest valid substring

Sample Input 0

3
)())))()(
()())(
((()(())

Sample Output 0

2
4
6


*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
void check(string s,int n){
    int longest=0;
    stack<int> str;
      str.push(-1);
        for(int i=0;i<n;i++){
             //   cout<<i<<endl;
            if(s[i]=='(') str.push(i);
            else{
                str.pop();
                if(str.empty()) {
                    str.push(i);
           
                    
                }
                else longest=max(longest,i-str.top());
            }
        }
        cout<<longest<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int test; 
    string s;
  int len;
   cin>>test;
    
    getline(cin,s); 
while(test--){
    getline(cin,s); 
    len=s.length();
   
        check(s,len);
    }
    return 0;
}
