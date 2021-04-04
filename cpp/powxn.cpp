//g++ powxn.cpp -o powxn
#include <iostream>
using namespace std;
#define MOD 10000007
double myPow(double x, int n) {
	 if(n<0){
	 	x=1/x;
	 	n=-n;
	 }
	 if(n==INT_MIN){
	 	return 0;
	 }
    double result = 1;
    while(n > 0) {

        if(n % 2 == 1) { 
            result = (result*x) ;
        }
        x = (x * x);
        n = n / 2; 
    }
    return result;
}
int main(){
	cout<<myPow(2.000,-2)<<"\n";
	return 0;
}