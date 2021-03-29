//g++ ladderLength.cpp -o ladderLength
//BFS
// https://leetcode.com/problems/word-ladder/
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
bool isAdjacent(string s, string t){
	int n=s.length();
	int different=0;
	for(int i=0; i<n; i++){
		if(s[i]!=t[i]){
			different++;
		}
	}
	if(different==1){
		return true;
	}
	return false;
}
void print(vector<string> v){
	for(auto i:v) cout<<i<<" ";
		cout<<"\n";
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	int steps=0;
	vector <string>:: iterator it;

	it=find(wordList.begin(), wordList.end(),endWord);
	if(it==wordList.end()){
		return steps;
	}
	
	unordered_map <string,int> mp;
	queue <string> q;
	q.push(beginWord);
	mp[beginWord]=1;
	
	while(!q.empty()){
		string head=q.front();
		cout<<"\nhead: "<<head<<"\n";

		q.pop();
		
		for(it=wordList.begin(); it!=wordList.end(); ){

			string word=*it;
			cout<<"word: "<<word<<"\n";
			if(isAdjacent(head,word)){
				q.push(word);
				cout<<"adjacent ";
				mp[word]=mp[head]+1;	
				wordList.erase(it);
				print(wordList);
				if(word==endWord){
					// cout<<"Steps "<<steps<<"\n";
					return mp[word];
				}
			}
			else it++;

		}
		
	}
	return steps;
}

int main(){
	// vector <string> v{"hot","dot","dog","log","lot","cog"};
	vector <string> v{"poon","plea","same","poin","plie","plee","poie"};
	string start="toon";	//toon,hit
	string target="plea"; //plea ,cog
	cout<<"word list: ";
	for(auto i:v) cout<<i<<" ";
	cout<<"\nBegin: "<<start<<" End: "<<target<<", Min Steps?\n";
	cout<<"Ans: "<<ladderLength(start,target,v)<<"\n";

	return 0;
}