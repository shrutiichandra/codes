//g++ restoreIpAddresses.cpp -o restoreIpAddresses
// https://leetcode.com/problems/restore-ip-addresses/
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
bool isValid(string s){
	bool ans=false;
	stringstream check(s);
	string octet;
	while(getline(check,octet,'.')){

		if(octet=="" || stoi(octet)>255 || stoi(octet)<0){
			ans=false;
			return ans;
		}
		if(octet.length()>1 && octet[0]=='0'){
			ans=false;
			return false;
		}
	}
	ans=true;
	return ans;
}
vector<string> restoreIpAddresses(string s) {
        vector <string> res;
        int len=s.length();

        if(len<4 || len>12){
        	return res;
        }
        // cout<<"len: "<<len<<"\n";
        string o1=s;
        int count=0;
        for(int i=0; i<len-2; i++){
        	for(int j=i+1; j<len-1; j++){
        		for(int k=j+1; k<len; k++){
        			// cout<<"i: "<<i<<" j: "<<j<<" k: "<<k<<"\n ";
        			o1=o1.substr(0,k)+"."+o1.substr(k);
        			// cout<<count<<"| "<<o1<<" ";
        			o1=o1.substr(0,j)+"."+o1.substr(j);
        			// cout<<o1<<" ";
        			o1=o1.substr(0,i)+"."+o1.substr(i);
        			count++;
        			// cout<<o1<<" "<<o2<<" "<<o3<<" "<<o4<<"\n";
        			// cout<<o1<<"\n";
        			if(isValid(o1)){
        				res.push_back(o1);
        			}

        		o1=s;
        		}
        	}
        }
        return res;
}

int main(){
	vector <string> v;
	string s="010010";
	cout<<"Given string: "<<s<<"\n";
	cout<<"All possible IPs from this string are: \n";
	v=restoreIpAddresses(s);
	for(auto i:v)
	{
		cout<<i<<"\n";
	}
	return 0;
}