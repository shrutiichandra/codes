/*
You are given an array of size N. And Q queries asking for the sum of elements between index L and R (including both L and R)

Input Format

First line contains 2 integers N and Q denoting the number of elements in the array and number of queries respectively.

2nd line contains N space separated integers denoting the N elements of given array A.

Following Q lines contains 2 integers L and R for each Q queries

Constraints

1 <= N, Q <= 10^5

abs(A[i]) <= 10^9

Output Format

Q new line separted integers denoting the result of each query.

Sample Input 0

10 2
-10 -10 -1 -3 10 -7 -7 9 9 0 
0 9
2 5

Sample Output 0

-10
-1


*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//segment sum
//que1
#define ELEM 100001
int main() {
    long long int size;
    long long int queries; //10^5
    long long int left,right,sum;
    long long int i;
    long long int arr[ELEM];
    long long int suff[ELEM];
    scanf("%lld %lld",&size,&queries);
   
    for(i=0;i<size;i++){//10^5
        scanf("%lld",&arr[i]);
    }
    suff[0]=arr[0];
    for(i=1;i<size;i++){ //10^5
        suff[i]=suff[i-1]+arr[i];
    }
    while(queries--){//10^9
        sum=0;
        scanf("%lld %lld",&left,&right);
        if(left==0) printf("%lld\n",suff[right]);
        else printf("%lld\n",suff[right]-suff[left-1]);
    }
    return 0;
}
