//g++ pascalTri2.cpp -o pascalTri2
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//for small numbers only
vector<int> getRow(int rowIndex) { 
	int n=rowIndex+1;       
	vector <int> v;
	v.push_back(1);
	for(int row=1;row<n;row++){
		vector<int> temp(row+1);
		for(int i=0;i<=row;i++)
		{	
			if(row==i || i==0){
				temp[i]=1;
			}
			else{
				temp[i]=v[i-1] + v[i]; //up and left
			}	
		}
		v=temp;
	}
	return v;
}

int main(){
	vector<int> v;
	int rows=3;
	v=getRow(rows);
	cout<<"Pascal's triangle for "<<rows<<" rows: \n";
	for(auto i: v){
		// for(auto j: i){
			cout<<i<<" ";
		// }
		cout<<"\n";
	}

	return 0;
}