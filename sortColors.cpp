//g++ sortColors.cpp -o sortColors
//very naive
#include <vector>
#include <iostream>

using namespace std;
void print(vector<int>& v){
	for(auto i:v){
		cout<<i<<" ";
	}
	cout<<"\n";
}
void sortColors(vector<int>& nums) {
	int len=nums.size();

	int red=0;
	int white=0;
	int blue=0;

	for(int i=0; i<len; i++){
		if(nums[i]==0){
			red++;
		}
		else if(nums[i]==1){
			white++;
		}
		else {
			blue++;
		}
	}
	cout<<"len: "<<len<<" ";
	cout<<"red: "<<red<<" white: "<<white<<" blue: "<<blue<<"\n";
	for(int i=0;i<red;i++){
		cout<<"red i: "<<i<<" ";
		nums[i]=0;
	}
	cout<<"\n";
	for(int i=red;i<red+white;i++){
		cout<<"white i: "<<i<<" ";
		nums[i]=1;
	}
	cout<<"\n";
	for(int i=red+white;i<white+blue+red;i++){
		cout<<"blue i: "<<i<<" ";
		nums[i]=2;
	}
	cout<<"\n";
}

int main(){
	vector <int> v{2,0,2,1,1,0};
	print(v);
	sortColors(v);
	print(v);
	return 0;
}