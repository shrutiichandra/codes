#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

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

