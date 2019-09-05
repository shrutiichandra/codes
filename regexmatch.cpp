// g++ regexmatch.cpp -o regexmatch
//388/487 testcases 
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

    bool isMatch(string s, string p) {
        bool ans=false;
        if((s=="" && p!="") || (s!="" && p=="") || (s=="" && p=="")){
        	//letters remain in one of the string
        	//one string is empty

        	cout<<s<<", "<<p<<" one empty , other not\n";
        	return false;
        }
        if(s.length()==1 && p.length()==1){
        	cout<<s<<", "<<p<<", last step\n";
        	if(s.compare(p)==0){
        		return true;
        	}
        }
        if(s[0]==p[0] && p[1]!='*'){
        	//first chars match
        	//go on
        	cout<<s<<", "<<p<<", match found\n";
        	string a(s.begin()+1,s.end());
        	string b(p.begin()+1,p.end());
            return isMatch(a,b);
        }
        if(p[0]=='.' && p[1]!='*'){
        	//eg. test and .est
        	//skip the current letter and move on
        	cout<<s<<", "<<p<<", skipping\n";
        	//if . is the last thing
        	if(p.length()==1){
        		if(s.length()==1)
        			return true;
        		else
        			return false;
        	}
        	string a(s.begin()+1,s.end());
        	string b(p.begin()+1,p.end());
            return isMatch(a,b);
        }
        if(s[0]==p[0] && p[1]=='*'){
        	//eg. aab a*b
        	//skip all consequent occurrences of current letter
        	cout<<s<<", "<<p<<", kleene star\n";
        	//if * is the last thing
        	if(p.length()==2)
        		return true;
        	if(p.length()==3 && p[2]==p[0]){
        		cout<<p[2]<<", "<<p[0]<<"\n";
        		p.erase(p.begin()+2);
        		string a(s.begin(),s.end());
        		return isMatch(a,p);

        	}
        	char c=s[0];
        	int index=0;
        	while(s[index]==c){
        		cout<<"s["<<index<<"]: "<<s[index]<<"\n";
        		index++;
        	}
        	cout<<"index: "<<index<<"\n";
        	
        	string a(s.begin()+index,s.end());
        	string b(p.begin()+2,p.end());
            return isMatch(a,b);
        	
        }

        if(s[0]!=p[0] && p[1]=='*' && p[0]!='.'){
        	//eg. aab c*a*b
        	//skip all consequent occurrences of current letter
        	cout<<s<<", "<<p<<", kleene star\n";
        	//if * is the last thing
        	if(p.length()==2){
        		if(s.length()==1)
        			return true;
        		else
        			return false;
        	}
        	
        	string a(s.begin(),s.end());
        	string b(p.begin()+2,p.end());
            return isMatch(a,b);
        	
        }

        if(p[0]=='.' && p[1]=='*'){
        	//eg. aab .*b
        	
        	cout<<s<<", "<<p<<", dot kleene star\n";
        	//if.* is the last thing
        	if(p.length()==2)
        		return true;
        	//.* is followed by some other letter
        	//find the occurrence of that letter
        	char c=p[2];
        	size_t found = s.find(c); 
        	if (found != string::npos){
        		//char is present at index found
        		string a(s.begin()+found,s.end());
        		string b(p.begin()+2,p.end());
            	return isMatch(a,b);

        	} 

        	
        }
        cout<<"any other case\n";
        return false;
    }

int main(){
	/*
		"mississippi"
"mis*is*p*."

	*/
	string s="aaa";
	string p="a*a";
	cout<<isMatch(s,p)<<"\n";
	return 0;
}