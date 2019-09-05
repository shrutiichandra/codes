//g++ groupAna.cpp -o groupAna
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

void print(vector<vector<string>> v){
	for(auto i: v){
		for(auto j: i){
			cout<<j<<" ";
		}
		cout<<"\n";
	}
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector <vector <string> > v;
	unordered_map<string,vector<string>> map;

	int size=strs.size();

	for(int i=0;i<size;i++){
		string temp=strs[i];
		sort(temp.begin(),temp.end());
		map[temp].push_back(strs[i]);
	}


	for(auto i=map.begin();i!=map.end();i++){
		// cout<<i->first<<": ";
		vector <string> :: iterator it;
		vector <string> one_group;
		for(it = i->second.begin(); it!=i->second.end();it++){
			one_group.push_back(*it);
		}
		v.push_back(one_group);
	}

	return v;
}


int main(){

	vector <string> s{"eat","tea","tan","ate","nat","bat"};
	vector<vector<string>> a;
	a=groupAnagrams(s);
	print(a);
	return 0;
}