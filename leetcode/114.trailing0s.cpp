//g++ trailing0s.cpp -o trailing0s
//https://leetcode.com/problems/factorial-trailing-zeroes/
#include <iostream>

using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {
        int num_zeros=0;
        int rem=n;
        int i=5;
        while(rem>=1){
        	rem = n/i;
        	cout<<num_zeros<<" ";
        	num_zeros += rem;
        	cout<<num_zeros<<"\n";

        	i = i*5;
        }

        return num_zeros;
    }
};

int main(){
	int n=30;
	Solution s;
	int ans=s.trailingZeroes(n);
	cout<<"num: "<<n<<"!, "<<ans<<"\n";
	return 0;
}