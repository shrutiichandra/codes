#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int n,i,j,s=0;
    scanf("%d",&n);
    int* arr=(int*)malloc(n*sizeof(int));
    int* index=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        if(i!=arr[i]){
            index[arr[i]]=1;
        }
    }
    for(i=0;i<n;i++){
        s=s+index[i];
    }
    printf("%d\n",s-1);
    
    return 0;
}
