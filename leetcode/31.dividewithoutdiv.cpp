//g++ -std=c++11 dividewithoutdiv.cpp -o dividewithoutdiv
// https://leetcode.com/problems/divide-two-integers/
#include <iostream>
#include <limits.h>
#include <math.h>
using namespace std;
int divide(int dividend, int divisor) {
     	// if (dividend==0) return 0;
      //   if (divisor==0) return INT_MAX;
		double new_dividend=fabs(dividend);
		double new_divisor=fabs(divisor);
		double power=log(new_dividend)-log(new_divisor);
        long long res=double(exp(power));
         
        if(dividend<0 && divisor>0){
            res=-res;
        }
        
        if(dividend>0 && divisor<0){
            res=-res;
        }
        if (res>INT_MAX) res=INT_MAX;
        return res;
    }

    
int main(){
	
	
	cout<<"==="<<divide(-2147483648,2)<<"\n";
	return 0;
}