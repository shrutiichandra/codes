#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void check(int* taste,int n){
        int i,j,l,r,fl=1;
        i=0; j=n-1;
        
        for(l=i;l<n;l++){
     
            for(r=j;(r>=0)&&fl;r--){

                if(taste[r]-taste[l]>=0){
                    printf("%d\n",r-l);
                    fl=0;
                }
            }

        }
}
int main() {
    int test; //100
    int n,i;//10^5
    int taste[100000];
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&taste[i]);
            check(taste,n);
    }
    return 0;
}
