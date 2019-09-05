// g++ repeatedSq.cpp -o repeatedSq
#include <iostream>
#include <cmath>
#include <bitset>
#include <algorithm>
using namespace std;
unsigned countBits(unsigned int number) 
{       
      // log function in base 2  
      // take only integer part 
		cout<<"bits: "<<(int)log2(number)+1<<"\n";
      return (int)log2(number)+1; 
} 
 
long long int repeated(int x, int e, int mod){
	long long int y;
	y = x;
	 int k = countBits(e);
	bitset<6> b(e);
	string s=b.to_string();
	cout<<"s: "<<s<<", after rev: ";
	reverse(s.begin(),s.end());
	cout<<"s: "<<s<<"\n";
	for(int i = k-2 ; i>=0 ; i--){
		cout<<"i: "<<i<<" ";
		y = (y*y)%mod;
		cout<<"y: "<<y<<"\n";
		cout<<"s["<<i<<"]: "<<s[i]<<"\n";
		if(s[i]=='1'){
			cout<<"set, ";
			y = (y*x)%mod;
			cout<<"y: "<<y<<"\n";
		}
	}
	cout<<"ANS: ";
	return y;
}
// Driven program        
int main() 
{ 
   cout<<repeated(7,38,23)<<"\n";
    
    return 0; 
}  
