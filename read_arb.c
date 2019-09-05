#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, const char * argv[]){char buf[160];strcpy(buf, argv[1]);printf("The content of memory location 12345678 is: ");printf(buf);exit(0);}