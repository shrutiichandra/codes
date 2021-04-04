#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<string> m;
void dfs(vector<string>& res,string& s,const string& digits,int pos){
	cout<<"--in dfs s: "<<s<<" digits: "<<digits<<" pos: "<<pos<<"\n";
        if(pos==digits.size()){
            res.push_back(s);
            cout<<"--bye---\n";
            return;
        }

        for(auto ch:m[digits[pos]-'0']){
        	cout<<"m[digits["<<pos<<"] - '0']: "<<m[digits[pos]-'0']<<"\n";
            s+=ch;
            cout<<"now, s: "<<s<<"\n";
            dfs(res,s,digits,pos+1);
            s.pop_back();
            cout<<"----exit for---\n";
        }
 }
vector<string> letterCombinations(string digits) {
	vector<string> res;
        if(digits.empty())
            return res;
        m={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string s;
        dfs(res,s,digits,0);
        return res;

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