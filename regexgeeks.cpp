// g++ regexgeeks.cpp -o regexgeeks

#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

    bool isMatch(string s, string p) {
    	bool ans=false;

    	if(s=="" && p==""){
    		cout<<s<<", "<<p<<" 1\n";
    		ans=true;
    		return ans;
    	}
    	if((s=="" && p!="") || s!=""  && p==""){
    		cout<<s<<", "<<p<<" 5\n";
    		ans=false;
    		return ans;
    	}

    	if(p[0]=='*' && p[1]=='\0' && s==""){
    		cout<<s<<", "<<p<<" 2\n";
    		ans=false;
    		return ans;
    	}

    	if(p[0]=='.' || s[0]==p[0]){
    		cout<<s<<", "<<p<<" 3\n";
    		string a(s.begin()+1,s.end());
        	string b(p.begin()+1,p.end());
    		return isMatch(a,b);
    	}

    	if(p[0]=='*'){
    		cout<<s<<", "<<p<<" 4\n";
    		bool a1,a2;
    		string a(s.begin()+1,s.end());
    		// a1 = isMatch(a,p);
        	string b(p.begin()+1,p.end());
        	// a2 = isMatch(s,b);
    		return isMatch(s,b)||isMatch(a,p);
    	}

    	return ans;
	 }

int main(){
	string s="ab";
	string p=".*c";
	cout<<isMatch(s,p)<<"\n";
	return 0;
}