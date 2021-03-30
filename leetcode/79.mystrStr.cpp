#include <iostream>
#include <string>
#include <algorithm>
// https://leetcode.com/problems/implement-strstr/
using namespace std;
int strStr(string haystack, string needle) {
	int index;

	int h_len=haystack.length();
	int n_len=needle.length();

	for(int i=0;i<h_len;){
		cout<<i<<", "<<haystack[i]<<", "<<needle[0]<<"\n";
		if( haystack[i]!=needle[0] ){
			i++;
			continue;
		}
		else{
			cout<<"match: index: "<<i<<", ";
			index=i;
			string temp(haystack.begin()+index,haystack.begin()+index+n_len);
			cout<<"temp: "<<temp<<"\n";
			if(temp.compare(needle)==0){
				//match found
				return index;
			}
			else{
				//advance the i pointer ahead
				i++;

			}
		}
	}

	return -1;        
}

int main(){
	string text="mississippi";
	string patt="issip";

	cout<<strStr(text,patt)<<"\n";

	return 0;
}