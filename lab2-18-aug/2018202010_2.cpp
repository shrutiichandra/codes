#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int numberOfOnes(int n){
    if(n==0) return 0;
    return (n&1)+numberOfOnes(n>>1);
}
int main() {
    int test;//10^5
    int n;//10^9
    int i,j,c,q,r;
    cin>>test;
    while(test--){
        cin>>n;
        if(ceil(log2(n))==floor(log2(n))) cout<<"1\n";
        else{
            c=numberOfOnes(n);
            cout<<c<<endl;
        }
    }
    
    
    
    return 0;
}

