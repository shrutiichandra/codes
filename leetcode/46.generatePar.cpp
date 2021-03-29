// https://leetcode.com/problems/generate-parentheses/
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
//g++ generatePar.cpp -o generatePar
using namespace std;
void backtrack1(vector<string> &v, string& s, int open, int close,int n){
	cout<<"---backtrack--- s: "<<s<<" open: "<<open<<" close: "<<close<<"\n";
	if(close==n){
		v.push_back(s);
		cout<<"---backtrack end---\n";
		return;
	}

	if(open<n){
		cout<<"open: "<<open<<" n: "<<n<<"\n";

		backtrack1(v,s.append("("),open+1,close,n);
		cout<<"after fn call open: "<<open<<" close: "<<close<<" ";
		s.pop_back();
		cout<<"s: "<<s<<"\n";
	}
	if(close<open){
		cout<<"close: "<<close<<" open: "<<open<<"\n";
		backtrack1(v,s.append(")"),open,close+1,n);
		cout<<"after fn call open: "<<open<<" close: "<<close<<" ";

		s.pop_back();
		cout<<"s: "<<s<<"\n";

	}
}
vector<string> generateParenthesis(int n){
	vector <string> ans;
	string seed="";
	backtrack1(ans,seed,0,0,n);
	return ans;
}

int main(){
	vector <string> v;
	v = generateParenthesis(3);
	for(auto i:v){
		cout<<i<<"\n";
	}
	return 0;
}