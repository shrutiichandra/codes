#include <iostream>
#include <vector>
using namespace std;

int main(){
	string s="bca";
	// for(int i=97; i<=122; i++){
	// 	s+=char(i);
	// }
	vector<int> v{1,2,3};
	cout<<"s: "<<s<<" "; 
	string ans=s;
	for(int toroll=0; toroll<v.size(); toroll++){
		cout<<"vector index "<<toroll<<"\n";
		for(int num=0; num<v[toroll]; num++){
			cout<<"num: "<<num<<" at s "<<s[num]<<" ";
			int temp=int(s[num]) + 1;

			if(temp>122) temp=97;

			ans[num]=char(temp);
			cout<<char(temp)<<"\n";
			s=ans;
		}
	}
	// char c='z';
	cout<<"s: "<<ans<<"\n";

	// cout<<"c: "<<c<<" ";
	// int n=int(c);
	// cout<<"n: "<<n<<"\n";
	// int fina=n+1;
	// if(fina>122)
		// fina=97;
	// char x=char(fina);
	// cout<<"x "<<x<<"\n";
	// char c=n;
	return 0;
}