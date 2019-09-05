//g++ numDecodings.cpp -o numDecodings
//memory limit exceeded
//220/258
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
void generateSubs(vector<string>& v, string s,int n, int start,string res){
	if(start==n){
		v.push_back(res);
	}

	for(int j=n-1; j>=start; j--){
		string temp=s.substr(start, j-start+1)+" ";
		generateSubs(v,s,n,j+1,res+temp);
	}
}
int numDecodings(string s) {
	int ans=0;

	int len=s.length();
	if(s[0]==0){
		return 0;
	}
	vector<string> subs;
	
	int start=0;
	string seed="";
	generateSubs(subs,s,len,start,seed);
	string delim=" ";
	int cnt;
	
	for(int i=0; i<subs.size(); i++){
		stringstream ss(subs[i]);
		string temp;
		cnt=0;
		int found=0;
		while(getline(ss, temp, ' ')){
			cout<<temp<<": ";
			
			if(temp[0]=='0' || stoi(temp)>=27 ){
				cout<<"count 0, ";
				cnt=0;
				found=1;
			}
			else if(found==0){
				cout<<"count 1, ";
				cnt=1;
			}
		}

		ans+=cnt;
		cout<<"ans: "<<ans<<"\n";


	}
	
	cout<<"\n";
	return ans;
}

int main(){
	cout<<"numDecodings: "<<numDecodings("101")<<"\n";
	return 0;
}