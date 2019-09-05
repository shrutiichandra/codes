//g++ -o ncr ncr.c
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MOD 1000000007
long long int fpower(long long int b){
    int p=1000000007;
    long long int ans=1;
    while(p>0){
        if(p&1) 
           ans=(ans*b)%MOD;
        b=(b*b)%MOD;
       p=p/2;
    }
    return ans;
}

void fact(int n,int r){
    long long int factorial[n+1];
    long long int i,a,b,c;
    
    factorial[0]=1;
    for(i=1;i<=n;i++)
        factorial[i]=(factorial[i-1]*i)%MOD;
    

    a=fpower(factorial[n-r])%MOD;
    b=fpower(factorial[r])%MOD;
    c=factorial[n];
    printf("%lld ",(a*b*c)%MOD);
}

int main() {
    int t,n,r;
  
   fact(4,2);

        //printf("%d\n",fact(4,1));
    return 0;
}
