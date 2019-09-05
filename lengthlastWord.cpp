//g++ lengthlastWord.cpp -o lengthlastWord

#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int lengthOfLastWord(string s) {
	int len=0;
	int n=s.length();
	if(n==0){
		return len;
	}
	int last_index=n-1;
	// cout<<"s_len: "<<s_len<<"\n";

	while(s[last_index]==' '){
		last_index--;
	}
	int valid_idx=last_index;
	while(s[valid_idx]!=' '&& valid_idx>=0){
		// cout<<"s["<<i<<"]: "<<s[i]<<"\n";
		len++;
		valid_idx--;
	}

	return len;
}

int main(){
	cout<<lengthOfLastWord("a ")<<"\n";
	return 0;
}