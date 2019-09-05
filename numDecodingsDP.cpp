//g++ numDecodingsDP.cpp -o numDecodingsDP

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include "common_utils.h"
using namespace std;

int numDecodings(string s) {
	int ans=0;

	int len=s.length();
	if(s[0]=='0'){
		return 0;
	}

	vector <int> cnt(len+1,0);

	cnt[0]=1;
	cnt[1]=1;

	for(int i=2; i<=len; i++){
		cout<<"s["<<i<<"-1]: "<<s[i-1]<<" ";
		//if the number previous the curr is >0
		if(s[i-1]>'0'){ //from 1 to 9
			cout<<"cnt["<<i<<"]: ";
			cnt[i]=cnt[i-1];
			cout<<cnt[i]<<"\n";

		}

		if(s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<'7')){
			cout<<"--cnt["<<i<<"]: ";
			cnt[i]+=cnt[i-2];
			cout<<cnt[i]<<"\n";

		}

	}
	printVector(cnt);
	ans=cnt[len];
	return ans;
}

int main(){
	string s="19";
	cout<<"s: "<<s<<"\n";
	cout<<"numDecodings: "<<numDecodings(s)<<"\n";
	return 0;
}