//g++ evalRPN.cpp -o evalRPN
#include <vector>
#include <iostream>
#include <stack>
#include "common_utils.h"
using namespace std;

class Solution {
public:
	bool isNumber(string s){
		int len=s.length();
		int start=0;
		if(s[0]=='-') start=1;
		if(len<2 && start==1) return false;
		for(int i=start; i<len; i++){
			if(isdigit(s[i]))
				continue;
			else return false;
		}
		return true;
	}
	
    int evalRPN(vector<string>& tokens) {
        int ans=0;

        stack<string> st;

        int len=tokens.size();

        for(int i=0; i<len; i++){
        	cout<<"isNumber "<<tokens[i]<<" ";
        	if(isNumber(tokens[i])){
        		cout<<"true, push: "<<tokens[i]<<"\n";
        		st.push(tokens[i]);
        	}
        	else{
        		cout<<"false, ";
        		//pop first 2 elements
        		int first_top=stoi(st.top());
        		st.pop();
        		int second_top=stoi(st.top());
        		st.pop();
        		if (tokens[i]=="+"){
        			ans=first_top+second_top;
        			cout<<"add, "<<ans<<"\n";
        		}
        		else if(tokens[i]=="-"){
        			ans=second_top-first_top;
        			cout<<"sub, "<<ans<<"\n";
        		}
        		else if(tokens[i]=="*")	{
					ans=first_top*second_top;
        			cout<<"mul, "<<ans<<"\n";
      			}
      			else if(tokens[i]=="/"){
      				ans=second_top/first_top;
        			cout<<"div, "<<ans<<"\n";
        		}
        		st.push(to_string(ans));
        	}
        }
        ans=stoi(st.top());

        return ans;
    }
};

int main(){
	vector <string> v{"4","3","-"};
	cout<<"given: ";
	printVector(v);
	Solution obj;
	int ans;
	ans=obj.evalRPN(v);

	cout<<"evaluated: "<<ans<<"\n";
	return 0;
}