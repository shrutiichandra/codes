#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void swap(int *a,int *b){
    int temp=*a;
   *a=*b;
    *b=temp;
}
 
int selectionSort(int arr[],int n){
    int i,j,min,count=0;
    for(i = 0;i<n-1;i++){
        min=i;
        for(j=i+1;j< n;j++)
          if(arr[j]<arr[min])
            min=j;
    
        swap(&arr[min], &arr[i]);
        count++;
    }
    return count;
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int n,i,j,s=0;
    scanf("%d",&n);
    int* arr=(int*)malloc(n*sizeof(int));
    int* index=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
   
    printf("%d",selectionSort(arr,n));
    return 0;
}

