//g++ -std=c++11 searchin2darr.cpp -o searchin2dar

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target){
	bool ans;
	int rows=matrix.size();
	int cols=matrix[0].size();
	cout<<rows<<" x "<<cols<<"\n";
	for(int r=0;r<rows;){
		if(target >= matrix[r][0] && target <= matrix[r][cols-1]){
			//target is present in this row
			ans=binary_search(matrix[r].begin(),matrix[r].end(),target);
			return ans;
		}
		//else target is present in some other row
		r++;
	}
	//if no condition is true
	return false;

}
int main(){
	vector <vector <int> > v{ {1}};
	cout<<searchMatrix(v,1)<<"\n";
	return 0;
}