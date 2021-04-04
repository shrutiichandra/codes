#include <stdio.h>
int subsetsum(int* arr,int size,int s);
int main(){
	int arr[]={1,2,4,8,9};
	int n=sizeof(arr)/sizeof(int);
	int sum=6;
	printf("%d\n",subsetsum(arr,n,sum));

}
int subsetsum(int* arr,int size,int s){
	int subset[size+1][s+1];
	int i,j;
	//when sum is 0, return true
	//when set is empty return false
	for(i=0;i<=size;i++)
		for(j=0;j<=s;j++)
			subset[i][j]=0;

	for(i=1;i<=size;i++){
		for(j=1;j<=s;j++){
			if(j<arr[i-1])
				subset[i][j]=subset[i-1][j];
			if(j>=arr[i-1])
				subset[i][j]=1+subset[i-1][j]+subset[i-1][j-arr[i-1]];
		}
	}
	return subset[size][s];
}