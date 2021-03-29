//g++ catalan.cpp -o catalan
// https://www.geeksforgeeks.org/program-nth-catalan-number/
#include <vector>
#include <iostream>

using namespace std;
int numTrees(int n) {
	vector <int> catalan(n+1,0);
	catalan[0]=1;
	catalan[1]=1;

	for(int i=2; i<=n; i++){
		for(int j=0; j<i; j++){
			catalan[i]+=catalan[j]*catalan[i-j-1];
		}
	}
	return catalan[n];
}
int main(){
	int n=19;
	cout<<n<<"th Catalan Num: "<<numTrees(19)<<"\n";
	return 0;
}