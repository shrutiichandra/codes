#include <vector>
#include <string>
#include <iostream>

using namespace std;
bool isPalindrome(string s) {
	bool ans=true;

	int n=s.length();

	int first=0, last=n-1;


	while(first<last){
		if(s[first]==s[last]){
			// cout<<"s: "<<s[first]<<", "<<s[last]<<"\n";

			first++;
			last--;
		}
		else{
			// cout<<"false\n";
			return false;
		}
		


	}
	return ans;
}

void partitionHelper(vector<vector<string>>& v, vector<string> curr, int s, int e,string str){
	if(s>=e){
		v.push_back(curr);
		return;

	}

	for(int i=s; i<e; i++){
		string test=str.substr(s,i-s+1);
		if(isPalindrome(test)){
			curr.push_back(test);
			partitionHelper(v,curr,i+1,e,str);
			curr.pop_back();
		}

	}
}


vector<vector<string>> partition(string s) {
	int end=s.length();
	vector<vector<string>> v;
	vector<string> temp;
	int start=0;
	
    partitionHelper(v,temp,start,end,s);

    return v;
}

int main(){
	string s="aab";
	vector<vector<string>> v;
	cout<<"given s: "<<s<<"\n";

	v=partition(s);
	for(auto i:v){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<"\n";
	}

}