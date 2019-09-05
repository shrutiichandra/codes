//g++ -o fastfib fast-fib.cpp 
//1,1,2,3,5,8,13,21,34
#include <iostream>

using namespace std;
int fib(int num);
void power(int arr[2][2],int exp);
void multiply(int a[2][2],int b[2][2]);
int main(){
	int n=9;
	
	cout<<"9th fibonacci number: ";
	cout<<fib(9);
	return 0;
}

int fib(int num){
	cout<<"inside fib("<<num<<")"<<endl;
	int fib_arr[2][2]={{1, 1},{1,0}};
	if(num==0){
		cout<<"returning 0"<<endl;
		return 0;
	}
	power(fib_arr,num-1);
	cout<<"returning "<<fib_arr[0][0]<<endl;
	return fib_arr[0][0];

}

void power(int base[2][2],int exp){
	cout<<"inside power exp: "<<exp<<" base array: "<<endl;
	if((exp==0||exp==1)) return;

	int matrix[2][2]={{1, 1}, {1,0}};

	power(base,exp/2);
	multiply(base,base);
	
	if(exp%2!=0)
		multiply(base,matrix);
}

void multiply(int a[2][2],int b[2][2]){
	int p1=a[0][0]*b[0][0]+a[0][1]*b[1][0];
	int p2=a[0][0]*b[0][1]+a[0][1]*b[1][1];
	int p3=a[1][0]*b[0][0]+a[1][1]*b[1][0];
	int p4=a[1][0]*b[0][1]+a[1][1]*b[1][1];

	a[0][0]=p1;
	a[0][1]=p2;
	a[1][0]=p3;
	a[1][1]=p4;
}