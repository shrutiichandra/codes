#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//for small numbers only
vector<vector<int>> generate(int numRows) {        
	vector <vector <int>> v;
	int n;
	for(int row=1;row<=numRows;row++){
		n=1;
		vector <int> temp;

		for(int i=1;i<=row;i++)
		{
			temp.push_back(n);
			n=n*(row-i)/i;

		}
		v.push_back(temp);
	}
	return v;
}

int main(){
	vector <vector <int>> v;
	int rows=5;
	v=generate(rows);
	cout<<"Pascal's triangle for "<<rows<<" rows: \n";
	for(auto i: v){
		for(auto j: i){
			cout<<j<<" ";
		}
		cout<<"\n";
	}

	return 0;
}