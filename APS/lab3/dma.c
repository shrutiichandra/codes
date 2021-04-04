/*
A.K. Das Sir just conducted a quiz in class. He requested DMA TAs to give him maximum and minimum sum of marks scored by any group of students. This group of students should have continous roll numbers and there is no limit to the size of this group. DMA TAs being busy with their own assignments, help them!

Input Format

Single line containing space separated numbers which denotes marks of students in order of their roll numbers.

Constraints

Number of students <= 10^8

-10^8 <= marks <= 10^8

Output Format

First line contains single integer denoting maximum sum

Second line contains single integer denoting minimum sum

Sample Input 0

1 2 3 -4 1

Sample Output 0

6
-4


*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define ELEM 1000
//ques4
int main() {
  //  printf("before");
    
    long long int size;
    long long int a[1000000];
    long long int i=0;
    long long int min_sum=999999,min=999999;
    long long int max_sum=0,max=0;
    while((scanf("%lld",&a[i]))!=-1){
        i++; 
    }
    size=i;

 
    for(i=0;i<size;i++){
        max+=a[i];
        if(max<0) max=0;
         if(max_sum<max) max_sum=max;
    } 
 
    printf("%lld\n",max_sum);
  
    for(i=0;i<size;i++){
        if(min>0) min=a[i];
        else min+=a[i];
        if(min<min_sum) min_sum=min;
    }
   printf("%lld\n",min_sum);
    
    
    return 0;
}
