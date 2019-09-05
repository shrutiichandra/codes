#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

unsigned int largest(unsigned int a[], int l,int r){
  unsigned int maximum=a[l];
  int i;
  for(i=l;i<r;i++){
    if (a[i]>maximum){
        maximum=a[i];
    }
  }
  return maximum;
}
int main() {
    int n,i,j;
    scanf("%d",&n); //n is 10^6
    unsigned int* height=(unsigned int*)malloc(sizeof(unsigned int)*n);
    for(i=0;i<n;i++){
        scanf("%u",&height[i]); //height is 10^18
    }
    for(i=0;i<n-1;i++){
        if(height[i]==largest(height,i,n-1)) printf("1 ");
        else printf("0 ");
    }
    printf("1 ");
    return 0;
}
