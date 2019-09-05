//g++ reverseWord.cpp -o reverseWord
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
void reverseWords(string &s) {

	int len=s.length();

	stringstream line(s);

	vector<string> words;
	char delim=' ';
	string temp;
	while(getline(line, temp, delim)){
		if(temp!="")
		words.push_back(temp);
	}

	s="";
	for(int i=words.size()-1; i>=0; i--){
		s=s+words[i]+" ";
		if(i==0) s.pop_back();
	}
}

int main(){
	string s="the sky is blue";
	cout<<"original: "<<"\""<<s<<"\""<<s<<"\n";
	cout<<"reversed, ";
	reverseWords(s);
	cout<<"\""<<s<<"\""<<"\n";
	return 0;
}