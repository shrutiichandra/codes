//g++ addBin -o addBin
#include <iostream>
#include <algorithm>

using namespace std;

string addBinary(string a, string b) {
	int len_a=a.length()-1;
	int len_b=b.length()-1;

	if(len_a<len_b){
		swap(a,b);
	}
	len_a=a.length()-1;
	len_b=b.length()-1;
	cout<<"a: "<<a<<" b: "<<b<<"\n";
	int s=0;
	int c=0;
	int i,j;
	string ans;
	for(i = len_a, j = len_b; i >= 0 && j >= 0;--i, --j){
		cout<<"a["<<i<<"]: "<<a[i]<<" b["<<j<<"]: "<<b[j]<<", ";
		s=(a[i] - '0') + (b[j] - '0') + c;
		cout<<"s: "<<s<<"\n";
		if( s>1 ){
			c=s/2;
			cout<<"c: "<<c<<", ";
			s=s%2;
			cout<<"s: "<<s<<"\n";
		}
		else c=0;
		ans+=to_string(s);
	}
	cout<<"end for: "<<ans<<"\n";
	 // ans=to_string(s);
	cout<<"i: "<<i<<" j: "<<j<<"\n";
	if(i>=0){
		cout<<"string remains\n";
		while(i>=0){
			cout<<"a["<<i<<"]: "<<a[i]<<", c: "<<c<<", ";
			s=(a[i] - '0') + c;
			cout<<"s: "<<s<<"\n";
			if( s>1 ){
				c=s/2;
				cout<<"__c: "<<c<<", ";
				s=s%2;
				cout<<"s: "<<s<<"\n";
			}
			else c=0;
			i--;
			ans+=to_string(s);
		}
	}
	if(c){
		ans+=to_string(c);
	}
	cout<<"ans: "<<ans<<"\n";
	reverse(ans.begin(),ans.end());

	return ans;
}

int main(){
	cout<<addBinary("1","111")<<"\n";

	return 0;
}