#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//ques nth fib
#define MAX 100000
#define MOD 1000000007
long long int fib(long long int n){
    long long int arr[MAX];
    long long int i;
   // printf("n=%lld",n);
    arr[1]=1;
    arr[2]=1;
    for(i=3;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[n]%MOD;
    
}
int main() {
    long long int n,ans; //10^18
    int test; //10^5
    scanf("%d",&test);
    while(test--){
        scanf("%lld",&n);
        ans=fib(n);
        if(ans>=0) printf("%lld\n",ans);
        else printf("%lld\n",ans+MOD);
    }

    return 0;
}

