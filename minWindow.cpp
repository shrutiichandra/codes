//g++ minWindow.cpp -o minWindow
//267/268 TLE
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
// #include <map>
using namespace std;


string minWindow(string s, string t) {
	int slen=s.length();
	int tlen=t.length();
	string ans="";
	unordered_map<char,int> map_pat;

	for(int i=0; i<tlen; i++){
		map_pat[t[i]]++;
	}

	int minim=9999999;
	int left=0,right=0;
	int count=0;
	vector<int> indexes;
	for(int i=0; i<slen; i++){
		if(map_pat[s[i]]>0){
			indexes.push_back(i);
		}
	}
	if(indexes.size()==0)
		return ans;
	for(auto i:indexes)	cout<<i<<"\n";
	int idx;
	for(idx=0; left<slen && right<slen;){
	// for(int left=0; left<slen; left++)
		left=indexes[idx];
		right=left;
		count =0;
		cout<<"right: "<<right<<" left: "<<left<<"\n";
		unordered_map<char,int> used;

		for(int i=left; i<slen && right<slen; i++){
			cout<<"i: "<<i<<" s[i]: "<<s[i]<<" map_pat[s[i]]: "<<map_pat[s[i]]<<" used[s[i]]: "<<used[s[i]]<<" ";
			if(map_pat[s[i]]==0){
				cout<<"not in pat ";
				//no-op
			}
			else if(map_pat[s[i]]>0 && used[s[i]]!=map_pat[s[i]]){
				cout<<"in pat \n";
				used[s[i]]++;
				cout<<"-->used[s[i]: "<<used[s[i]]<<" ";
				count++;
				cout<<"--> count: "<<count<<"\n";
			}
			else{ //comment out later
				cout<<"\n";
			}
			if(count==tlen){
				//we found a window
				cout<<"left,right: "<<left<<","<<right<<" ";
				int wlen=right-left+1;
				cout<<"new win length: "<<wlen<<"\n";
				if(wlen<minim){
					minim=wlen;
					ans=s.substr(left,wlen);
					cout<<"ans: "<<ans<<"\n";
				}
				//find the index of first 
				idx++;
				cout<<"idx: "<<idx<<"\n";
				break;
			}
			right++;

		}//end for
		if(ans==""){
			break;
		}
	}
	
	return ans;
}

int main(){
	string s="ADOBECODEBANC";
	string t="ABC";
	cout<<"Given strings: "<<s<<", "<<t<<"\n";
	cout<<"Minimum window in "<<s<<" which contains all characters in "<<t<<" is "<<minWindow(s,t)<<"\n";
	return 0;
}