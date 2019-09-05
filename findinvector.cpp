//g++ -std=c++11 findinvector.cpp -o findinvector

#include<vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	vector <int> v{1,2,3,4,5};
	vector <int> ::iterator i;
	i=find(v.begin(),v.end(),5);
	if(i!=v.end()){
		cout<<i-v.begin()<<",";
		cout<<*i;
	}
	return 0;
}