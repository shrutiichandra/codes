//g++ isPalindrome.cpp -o isPalindrome
// https://leetcode.com/problems/valid-palindrome/
#include <iostream>
using namespace std;
bool isPalindrome(string s) {
	bool ans=true;

	int n=s.length();

	int first=0, last=n-1;
	bool flag=false;
	bool alpha,num;
	while(first<last){
		cout<<"first: "<<first<<" last: "<<last<<" ";
			cout<<abs(s[first]-s[last])<<"\n";
			flag=false;
			alpha=false,num=false;
		if(isalnum(s[first])==0){
			cout<<"s: "<<s[first]<<"\n";
			first++;
			flag=true;
		}
		else{
			if(isalpha(s[first]))  alpha=true;
			else num=true;
			cout<<alpha<<", "<<num<<"\n";
		}
		if(isalnum(s[last])==0){
			cout<<"s: "<<s[last]<<"\n";

			last--;
			flag=true;
		}
		else{
			if(isalpha(s[last])) alpha=true;
			else num=true;
			cout<<alpha<<", "<<num<<"\n";
		}

		if(!flag && (abs(s[first]-s[last])==32 || s[first]==s[last]) && (alpha^num) ){
			cout<<"s: "<<s[first]<<", "<<s[last]<<"\n";

			first++;
			last--;
		}
		else if(!flag){
			cout<<"false\n";
			return false;
		}
		


	}
	return ans;
}

int main()
{
	cout<<"Given string: ";
	string s="b";
	cout<<s<<"\nPalindrome: ";
	isPalindrome(s) ? cout<<"true\n" : cout<<"false\n";
	return 0;
}