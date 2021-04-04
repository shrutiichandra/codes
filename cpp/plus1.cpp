//g++ plus1.cpp -o plus1
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
	int num=digits.size();
	vector <int> res;
	int s=0;
	int c=0;

	for(int i=num-1;i>=0;i--){
		if(i==num-1){
			cout<<"digits["<<i<<"]: "<<digits[i]<<", ";
			s=digits[i]+1+c;
			cout<<"s: "<<s<<"\n";

		}
		else {
			cout<<"digits["<<i<<"]: "<<digits[i]<<", ";

			s=digits[i]+c;
			cout<<"s: "<<s<<"\n";

		}
		if(s>9){
			c=s/10;
			cout<<"carry: "<<c<<", ";
			s=s%10;
			cout<<"s: "<<s<<"\n";
		}
		else c=0;
		res.push_back(s);

	}
	if(c){
		res.push_back(c);
	}
	reverse(res.begin(),res.end());
	return res;
}


int main(){
	vector<int> v{9,9,9};
	vector <int> a;
	a=plusOne(v);
	for(auto i: a){
		cout<<i;
	}
	cout<<"\n";
	return 0;
}