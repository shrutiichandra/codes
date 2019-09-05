#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define ll long long
long long int findxor(long long int n){
    if(n%4==0) return 1;
    if(n%4==1) return n;
    if(n%4==2) return n+1;
    if(n%4==3) return 0;
}
int main() {
    //q - 10^5 n- 10^12
    long long int que,n;
    scanf("%lld",&que);
    while(que--){
        scanf("%lld",&n);
        printf("%lld\n",findxor(n));
    }
    return 0;
}

