/*
There are N sweets and their rates are given. Pappu have X rupees. He wants to buy exactly 2 sweets. Determines whether or not there exist two sweets such that sum of cost of 2 sweets is exactly X rupees.

you cannot use the same sweet twice.

Input Format

The first line of each test file contains number of sweets, N.

The next N line contains cost of N sweets.

Next line contains Q, number of query.

Next Q line will consist of amount X which pappu have.

Constraints

2
N

10^4

1
Q

1000

Output Format

for each Query, print "Yes" if pappu can buy exactly 2 sweets, otherwise "No".

Output should be newline separated.

Sample Input 0

4
10
8
12
22
2
34
17

Sample Output 0

Yes
No


*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void swap(int* a,int* b){
    int c;
    c=*a;
    *a=*b;
    *b=c;
}
int partition(int* a,int start,int end){
    int key=a[end];
    int index=start-1;
    int i;
    for(i=start;i<=end-1;i++){
        if(a[i]<=key){
            index++;
            swap(&a[index],&a[i]);
        }
    }
   swap(&a[index+1],&a[end]);
  return index+1;
}
void quickSort(int* a,int start,int end){
    int pivot;  
    if(start<end)
    {
        pivot=partition(a,start,end);
        quickSort(a,start,pivot-1);
        quickSort(a,pivot+1,end);
    }
}
/*int check(int n,int* a,int sum){
    int i=0,j=n-1;
    quickSort(a,0,n-1);
    while(i<j){
        if(a[i]+a[j]==sum) return 1;
        else if(a[i]+a[j]<sum) i++;
        else j--;
    }
    return 0;
}*/
int check(int n,int* a,int sum){
  int i,temp,fl=0;
  int s[1000000]={0}; 
 
  for (i=0;i<n;i++){
      temp=sum-a[i];
      if (temp>=0&&s[temp]==1)
         fl++;
      s[a[i]]=1;
  }
    return fl;
}
 
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int num,queries;
    int i,j,fl=0;
    int rupees[10000];
    int amount[1000];
    scanf("%d",&num);
    for(i=0;i<num;i++){
        scanf("%d",&rupees[i]);
    }
    scanf("%d",&queries);
    for(i=0;i<queries;i++){
        scanf("%d",&amount[i]);
    }
    for(i=0;i<queries;i++){
        j=check(num,rupees,amount[i]);
        if(j>0) printf("Yes\n");
        else if(j==0) printf("No\n");
    }
    
    
    
    return 0;
}
