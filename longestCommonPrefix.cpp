//g++ longestCommonPrefix.cpp -o longestCommonPrefix
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits.h>
 using namespace std;


 string longestCommonPrefix(vector<string>& strs) {
 	string ans;

 	int num_words=strs.size();

 	if(num_words==0){
 		return "";
 	}

 	int min_len=INT_MAX;
 	

 	for(int i=0;i<num_words;i++){
 		int	len=strs[i].length();
 		if(min_len>len)
 			min_len=len;
 	}
 	// cout<<"min_len: "<<min_len<<"\n";

 	//do binary search
 	int low=0,high=min_len;
 	int mid;
 	int flag;
 	while(low<=high){
 		flag=0;
 		mid=(low+high)/2;
 		//check if all strings in the input array contains this prefix
 		cout<<"low: "<<low<<", mid: "<<mid<<"\n";
 		for(int i=1;i<num_words&&!flag;i++){
 			cout<<"strs["<<i<<"]: "<<strs[i]<<", ";
 			for(int j=low;j<=mid && !flag;j++){
 				cout<<"strs[0]["<<j<<"]: "<<strs[0][j]<<"\n";
 				if(strs[i][j]!=strs[0][j]){
 					//exit
 					//do not update prefix
 					flag=1;
 				}
 			}
 		}

 		//if flag is still 0
 		if(flag==0){
 			cout<<"substr: "<<strs[0].substr(low,mid-low+1)<<"\n";
 			ans += strs[0].substr(low,mid-low+1);

 			low = mid+1;
 		}
 		else{
 			high = mid - 1;
 		}

 	}

 	return ans;
 }

 int main(){
 	vector <string> s{"aa","aa"};
 	cout<<longestCommonPrefix(s)<<"\n";
 	return 0;
 }