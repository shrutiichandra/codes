//g++ regexinbuilt.cpp -o regexinbuilt

#include <iostream>
#include <algorithm>
#include <string>
#include <regex>

using namespace std;

    bool isMatch(string s, string p) {
    	regex r(p);

    	if(regex_match(s,r)){
    		return true;
    	}
    	return false;


	 }

int main(){
	string s="aaa";
	string p="a*a";
	cout<<isMatch(s,p)<<"\n";
	return 0;
}