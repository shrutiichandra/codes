#include <vector>
#include <algorithm>
#include <iostream>
#include "common_utils.h"
using namespace std;
// template <typename T> 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool ans=false;
        int n=s.length();
        vector <bool> mat(n+1, false);

        vector<string> :: iterator it;

        for(int i=1; i<=n; i++){
        	if(mat[i]==false){
        		string uptil_i=s.substr(0,i);
        		it=find(wordDict.begin(),wordDict.end(),uptil_i);
        		if(it!=wordDict.end()){
        			mat[i]=true;
        		}
        	}

        	if(mat[i]==true){
        		if(i==n){
        			return true;
        		}

        		for(int j=i+1; j<=n; j++){
        			if(mat[j]==false){
        				string uptil_j=s.substr(i,j-i);
		        		it=find(wordDict.begin(),wordDict.end(),uptil_j);
		        		if(it!=wordDict.end()){
		        			mat[j]=true;
		        		}			
        			}

        			if(j==n && mat[j]==true){
        				return true;
        			}
        		}
        	}
        }

        return false;
    }
};

int main(){
	string s="applepenapple";
	cout<<"given s: "<<s<<" | ";
	vector <string> v{"apple","pen"};
	printVector(v);
	Solution obj;
	cout<<"can break: ";
	obj.wordBreak(s,v) ? cout<<"true\n" : cout<<"false\n";
	return 0;
}
