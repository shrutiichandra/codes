//g++ reverseWordO1.cpp -o reverseWordO1
//O1 space
#include <algorithm>
// #include <vector>
#include <iostream>
// #include <sstream>
using namespace std;
void reverseWords(string &s) {

	int len=s.length();

	char delim=' ';
	int i=0;



	
		while(i<s.length()){
            while(i<s.length() && s[i]==' '){
            	s.erase(s.begin()+i);
            }
            cout<<"s: \""<<s<<"\""<<"\n";
			int curr=i;

			cout<<"curr: "<<curr<<" i: "<<i<<" \n";
			while(s[curr]!=delim && curr<s.length()){
				// cout<<"s: "<<s[curr]<<" ";
				curr++;
			}
			cout<<"curr: "<<curr<<"\n";
			reverse(s.begin()+i, s.begin()+curr);
			cout<<"while rev: \""<<s<<"\"\n";
			i=curr+1;
			curr=i;


		}
		if(!s.empty()&&s[s.length()-1]==' ') s.pop_back();
		reverse(s.begin(),s.end());
		cout<<"s, after rev: \""<<s<<"\"\n";

	



}

int main(){
	string s="1 ";
	cout<<"original: "<<"\""<<s<<"\""<<"\n";
	cout<<"reversed, ";
	reverseWords(s);
	cout<<"\""<<s<<"\""<<"\n";
	return 0;
}