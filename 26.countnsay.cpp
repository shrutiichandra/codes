//g++ countnsay.cpp -o countnsay
// https://leetcode.com/problems/count-and-say/
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string countAndSay(int n) {
	if(n<1){
		return "";
	}

	if(n==1){
		return "1";
	}

	if(n==2){
		return "11";
	}

	string ans;
	string prev="11";
	int count=0;
	int left=0,right=0;
	for(int i=3;i<=n;i++){
		cout<<"prev: "<<prev<<"\n";
		ans="";
		left=0; right=0;
		for(int s=0;s<prev.length();s++){	
			cout<<"prev["<<s<<"]: "<<prev[s]<<", left:"<<left<<"\n";
			if(prev[s]==prev[s+1]){
				right++;
				cout<<"right: "<<right<<"\n";
			}
			else{
				count=right-left+1;
				cout<<"count: "<<count<<" ";
				string c=to_string(count);
				// string p=prev[left];
				string temp(1,prev[left]);
				cout<<"temp: "<<c<<", ";

				c.append(temp);

				ans.append(c);
				cout<<"ans: "<<ans<<"\n";
				left+=count;
				right=left;
			}

		}
		prev=ans;	
	}


	return ans;
        
}

int main(){
	cout<<countAndSay(7)<<"\n";

	return 0;
}