//g++ compareVersion.cpp -o
// https://leetcode.com/problems/compare-version-numbers/
#include <sstream>
#include <vector>
#include <iostream>
#include "common_utils.h"
using namespace std;
class Solution {
public:
	void removeLeadingZeros(string& str){
		str.erase(0, min(str.find_first_not_of('0'), str.size()-1));
		// cout<<"str: "<<str<<"\n";

	}

	void doPadding(string &str, int beg, int end){
		string padding=".0";
		for(int i=beg; i<end; i++){
			str+=padding;
		}
	}
    int compareVersion(string version1, string version2) {
        //v1>v2 return 1
        //v1<v2 return -1
        //v1=v2 return 0
        
        int m=version1.length(), n=version2.length();
        int parts_m=(m/2)+1, parts_n=(n/2+1);
        if(parts_m<parts_n){
        	doPadding(version1, parts_m, parts_n);
        }
        else if(parts_n<parts_m){
        	doPadding(version2,parts_n,parts_m);
        }
    	stringstream s1(version1);
    	stringstream s2(version2);

    	vector <string> v1;
    	vector <string> v2;
    	string temp;
    	while(getline(s1, temp, '.')){
    		v1.push_back(temp);
    	}
    	// cout<<"v1:";
    	 // printVector(v1);
    	while(getline(s2, temp, '.')){
    		v2.push_back(temp);
    	}
    	// cout<<"v2:";
    	// printVector(v2);

    	int len1=v1.size();
    	int len2=v2.size();
    	int i,j;
    	for(i=0, j=0; i<len1 && j<len2; i++, j++){
    		// cout<<"i: "<<i<<" j "<<j<<"\n";
    		removeLeadingZeros(v1[i]);
    		removeLeadingZeros(v2[i]);
    		if(stoi(v1[i])>stoi(v2[j])){
    			// cout<<v1[i]<<", "<<v2[j]<<" return 1\n";
    			return 1;
    		}
    		else if(stoi(v2[j])>stoi(v1[i])){
    			// cout<<v1[i]<<", "<<v2[j]<<" return -1\n";
    			return -1;
    		}
    	}
    	// cout<<"i "<<i<<" j "<<j<<", ";
    	// cout<<"len1: "<<len1<<" len2 "<<len2<<"\n";
    	// if(i!=len1){
    	// 	removeLeadingZeros(v1[i]);
    	// 	if(v1[i]!="0"){
    	// 		return 1;
    	// 	}
    	// }

    	// if(j!=len2 ){
    	// 	removeLeadingZeros(v2[j]);
    	// 	if(v2[j]!="0"){
    	// 		return -1;
    	// 	}
    	// }

    	return 0;
    }
};

int main(){
	string v1="1";
	string v2="1.0";

	cout<<"versions: "<<v1<<", "<<v2<<"\n";
	Solution s;
	int ans;
	ans=s.compareVersion(v1,v2);
	cout<<"compare: "<<ans<<"\n";

	return 0;
}