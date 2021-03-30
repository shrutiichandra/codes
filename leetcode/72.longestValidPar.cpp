//g++ longestValidPar.cpp -o longestValidPar
// https://leetcode.com/problems/longest-valid-parentheses/
#include <stack>
#include <string>
#include <iostream>
#include <limits.h>
using namespace std;

int longestValidParentheses(string s) {
	stack <int> st;
	st.push(-1);
	int maxLen=INT_MIN;
	int len=0;
	for(int i=0;i<s.length();i++){
		cout<<i<<" "<<s[i]<<"\n";
	}
	cout<<"-----\n";
	for(int i=0;i<s.length();i++){
		cout<<"s["<<i<<"]: "<<"s[i] ";
		if(s[i]=='('){
			cout<<"push "<<i<<"\n";
			st.push(i);
		}
		else {
			
				st.pop();
				cout<<"pop\n";	

			if(st.empty()){
			cout<<"push "<<i<<"\n";

				st.push(i);
			}
			else{
				cout<<"i: "<<i<<" st.top(): "<<st.top()<<" ";
				len=i-st.top();
				cout<<"len: "<<len<<"\n";
				if(maxLen<len){
					maxLen=len;
				}
			}
		}
	}
	return maxLen;
}

int main(){
	cout<<longestValidParentheses(")()())")<<"\n";

	return 0;
}