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
        if(s[i]=='(') str.push(i);
        else{
            str.pop();
            if(str.empty()) 
               str.push(i);
                else longest=max(longest,i-str.top());
            }
        }
        cout<<longest<<endl;
}

int main() {
    
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
