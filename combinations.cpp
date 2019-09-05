//g++ combinations.cpp -o combinations
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
void combineHelper(int n,int k, vector <int>& temp, vector <vector <int>>& v,int start){
	cout<<"start: "<<start<<"\n";
	if(temp.size()==k){
		cout<<"done\n";
		v.push_back(temp);
		return;

	}

	for(int i=start; i<=n; i++){
		// cout<<"i: "<<i<<"\n";
		temp.push_back(i);
		combineHelper(n,k,temp,v,i+1);
		temp.pop_back();
	}
	
}
vector<vector<int>> combine(int n, int k) {
	vector <vector <int>> v;
	vector <int> temp;
	// int curr=0;
	int start=1;
	combineHelper(n,k, temp, v,start);
	return v;
}

int main(){
	vector <vector <int>> v;
	v=combine(5,3);

	for(auto i:v){
		for(auto j:i){

			cout<<j<<" ";
		}
		cout<<"\n";
	}
	return 0;
}