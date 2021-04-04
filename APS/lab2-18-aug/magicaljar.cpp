/*
Mitesh has a magical jar.Mitesh can put any number of chocolate(none also)in the jar every morning and each chocolate gets converted into two by the end of night.Now Mitesh wants some exact number of chocolates denoted by N no matter how many nights it takes but he wants to put least number of them from his side. He asks you to find the minimum number of chocolate he need to put into the jar across those days?

Input Format

First line conatins T i.e number of testcases. each of next T line conatains an integer denoting N

Constraints

1<= T <=100000

1<= N <= 1000000000

Output Format

Corresponding to each test case print single integer on new line denoting minimum number of chocolate Mitesh needs to put in Jar.

Sample Input 0

1
3

Sample Output 0

2

Explanation 0

Day 1 : mitesh puts one chocolate , it gets double by day 2.

Day 2 : mitesh puts another chocolate. So now he have 3 in toatl( 1*2 + 1 ). 
*/
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
