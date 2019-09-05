#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector <string>& v,string& ans,vector <string>& m,int pos,string& input){
	if(pos==input.length()){
		v.push_back(ans);
		return;
	}
	string this_key_letters = m[input[pos]-'0'];
	int len = this_key_letters.length();

	for(int i=0;i<len;i++){
		ans += this_key_letters[i];

		dfs(v,ans,m,pos+1,input);

		ans.pop_back();
	}
}

vector<string> letterCombinations(string digits) {
	vector <string> ans;

	vector <string> letter_on_keys{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	string seed="";
	dfs(ans,seed,letter_on_keys,0,digits);

	return ans;

}
int main(){
	vector <string> v;
	v=letterCombinations("23");
	for (auto i: v){
		cout<<i<<", ";
	}
	cout<<"\n";
	return 0;
}