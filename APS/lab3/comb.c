/*
Yuor task is simple, print the value of nCr for the given values of n and r for T test cases.

Since the value can be really large, print is after taking its modulo with 10^9 + 7.

Input Format

First line contains an integer T denoting the number of test cases.

Following T lines contains 2 integers n and r for each test case.

Constraints

1 <= t <= 10^5

1 <= r <=n <= 10^6

Output Format

for each test case print the value of nCr mod 1000000007 in a newline

Sample Input 0

2
7 3
5 2

Sample Output 0

35
10


*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MOD 1000000007
long long int fpower(long long int b){
    int p=1000000007-2;
    long long int ans=1;
    while(p>0){
        if(p&1) 
           ans=(ans*b)%MOD;
        b=(b*b)%MOD;
       p=p/2;
    }
    return ans%MOD;
}
int main() {
    long long int factorial[1000001];
    long long int i,a,b,c;
    int t,n,r;
    
    factorial[0]=1;
    for(i=1;i<1000000;i++)  
         factorial[i]=(factorial[i-1]*i)%MOD;
    
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&r);
        a=fpower(factorial[n-r])%MOD;
        b=fpower(factorial[r])%MOD;
        c=factorial[n];
        printf("%lld\n",(((a*b)%MOD)*c)%MOD);
    }
    
    return 0;
}