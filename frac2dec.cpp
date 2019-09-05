//g++ frac2dec.cpp -o frac2dec
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
string fractionToDecimal(int numerator, int denominator) {
	string ans="";
	if(numerator==0){
		ans="0";
		return ans;
	}

	if(numerator<0 ^ denominator<0){ //if either n or d is -ve, res is -ve
		cout<<"ans -ve\n";
		ans+="-";
	}


	long num = abs(numerator);
	long den = abs(denominator);


	long rem = num % den;

	long quo;
	if(num < den)
		ans+="0.";
	else {
		quo=num/den;
		if(rem!=0){
			string dec=to_string(quo)+".";
			ans+=dec;
		}
		else{
			ans+=to_string(quo);
		}
	}
	// cout<<"first rem: "<<rem<<"\n";

	unordered_map<long,long> v;
	//remainder is not in map
	while(rem!=0){
		if(v.find(rem)!=v.end()){
			ans.insert(v[rem],1,'(');
			ans += ')';
			break;

		}
		cout<<"in while rem: "<<rem<<" ";
		v[rem] = ans.length();
		rem = rem*10;
		cout<<"rem*10: "<<rem<<" ";
		
		quo = rem/den;
		cout<<"quo: "<<quo<<" ";
		
		ans += to_string(quo);

		rem = rem%den;
		cout<<"rem next: "<<rem<<"\n";

	}

	return ans;
}

int main(){
	int num=7;

	int den=-12;
	cout<<"fraction: "<<num<<"/"<<den<<"\n";
	string ans=fractionToDecimal(num,den);
	cout<<"decimal: "<<ans<<"\n";

	return 0;
}