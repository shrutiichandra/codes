#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int findmin(int a[],int size){
    int i;
    int min=a[0];
    for(i=1;i<size;i++){
        if(a[i]<min)
            min=a[i];
    }
    return min;
}
int main() {
    int n; //10^7
    scanf("%d",&n);
    int* height=(int*)calloc(sizeof(int),n);
    int i,area,min;
    
    for(i=0;i<n;i++)
        scanf("%d",&height[i]);
    printf("%d\n",n*findmin(height,n));
    
    return 0;
}

