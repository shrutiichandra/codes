#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char s[100000]; //10^5
    int test,len,i,flag;
    char curr;
    printf("%s",s);
    scanf("%d",&test);
    
    while(test--){
        scanf("%s",&s);
        len=strlen(s);
        flag=1;
        for(i=0;i<len&&flag;i++)
            if(s[i]=='1'){
                flag=0;
                break;
            }
        
        if(flag==0) printf("%d ",i);
        if(flag) printf("-1 ");
    }
    
    return 0;
}

