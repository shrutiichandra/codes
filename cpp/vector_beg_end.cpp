#include <vector>
#include <iostream>

using namespace std;

int main(){
	vector <int> num;

	num.push_back(7);
	num.push_back(8);
	num.push_back(9);
	num.push_back(10);
	num.push_back(11);
	num.push_back(12);

	//this will not work
	cout<<*num.begin()<<"\n";

	cout<<num[0]<<"\n";	
	return 0;
}