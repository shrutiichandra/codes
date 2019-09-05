#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string simplifyPath(string path) {
	string res="";
	int len=path.length();

	string root="/";
	vector<string> st;
	// st.push(root);
	stringstream s(path);
	string temp;
	while(getline(s,temp,'/')){
		// cout<<"temp: "<<temp<<" ";
		if(temp=="." || temp.empty()){
			// cout<<"continue\n";
			continue;
		}
		else if(temp==".."){
			if(!st.empty()){
				// cout<<"pop\n";
				st.pop_back();
			}
		}
		else{
			// cout<<"push\n";
			st.push_back(temp);
		}
	}
	
	for(int i=0; i<st.size();i++){
		res=res+"/"+st[i];
	}
	
	return res;        
}

int main(){
	string path1="/home/";
	cout<<"simplifyPath: "<<simplifyPath(path1)<<"\n";

	string path2="/a/./b/../../c/";
	cout<<"simplifyPath: "<<simplifyPath(path2)<<"\n";

	string path3="/a/../../b/../c//.//";
	cout<<"simplifyPath: "<<simplifyPath(path3)<<"\n";

	string path4="/a//b////c/d//././/..";
	cout<<"simplifyPath: "<<simplifyPath(path4)<<"\n";

	return 0;
}